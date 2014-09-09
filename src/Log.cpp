/*
 * Log.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
 */

#include <Log.h>

namespace Logger {

Log::Log(LogTarget& newTarget, Severity newSeverity): target(newTarget), logLevel(newSeverity) {
  target.open();
}

void Log::write(Severity severity, std::string file, std::string line,
    std::string logText) {
  if(severity >= logLevel)
    target.write(line);
}

void Log::setLogLevel(Severity newLogLevel) {
  logLevel = newLogLevel;
}

Log::~Log() {
  target.close();
}

} /* namespace Logger */
