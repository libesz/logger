/*
 * Log.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
 */

#include <Log.h>
#include <cstdio>
#include <cstdarg>

namespace Logger {

Log::Log(LogTarget& newTarget, Severity newSeverity): target(newTarget), logLevel(newSeverity) {
  target.open();
}

void Log::write(Severity severity, std::string file, unsigned line, std::string logText, ...) {
  if(severity >= logLevel) {
    char buffer[bufferSize];
    va_list args;
    va_start (args, logText);
    unsigned size = vsnprintf (buffer, bufferSize, logText.c_str(), args);
    va_end (args);
    std::string str(buffer);
    str.resize(size);
    target.write(str);
  }
}

void Log::setLogLevel(Severity newLogLevel) {
  logLevel = newLogLevel;
}

Log::~Log() {
  target.close();
}

} /* namespace Logger */
