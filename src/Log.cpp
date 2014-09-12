/*
 * Log.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
 */

#include <Log.h>
#include <cstdio>
#include <cstdarg>
#include <iostream>
#include <ctime>
#include <cstring>

namespace Logger {

Log::Log(LogTarget& newTarget, Severity newSeverity): target(newTarget), logLevel(newSeverity) {
  target.open();
}

void Log::write(Severity severity, std::string file, unsigned line, std::string logText, ...) {
  if(severity >= logLevel) {
    std::string str = getTimeStamp();
    char logBuffer[bufferSize];
    va_list args;
    va_start (args, logText);
    unsigned logSize = vsnprintf (logBuffer, bufferSize, logText.c_str(), args);
    va_end (args);
    str += " ";
    str += file;
    str += " (";
    str += std::to_string(line);
    str += "): ";
    unsigned headerSize = str.size();
    str += std::string(logBuffer);
    str.resize(headerSize + logSize);
    target.write(str);
  }
}

void Log::setLogLevel(Severity newLogLevel) {
  logLevel = newLogLevel;
}

Log::~Log() {
  target.close();
}


std::string Log::getTimeStamp() {
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];
  memset(buffer, 0, 80);

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%d-%m-%Y %H:%M:%S",timeinfo);
  return std::string(buffer);
}

} /* namespace Logger */
