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
#include <sstream>
#include <iomanip>

namespace Logger {

std::ostream& operator<<(std::ostream &out, Severity s) throw(std::runtime_error) {
  switch(s) {
  case Severity::TRACE:
    out << std::string("TRACE");
    break;
  case Severity::DEBUG:
    out << std::string("DEBUG");
    break;
  case Severity::INFO:
    out << std::string("INFO");
    break;
  case Severity::WARN:
    out << std::string("WARN");
    break;
  case Severity::ERR:
    out << std::string("ERR");
    break;
  case Severity::CRIT:
    out << std::string("CRIT");
    break;
  default:
    throw std::runtime_error("UNKNOWN Severity supplied");
  }
  return out;
}

Log::Log(LogTarget& newTarget, Severity newSeverity): target(newTarget), logLevel(newSeverity) {
  target.open();
  target.write(getTimeStamp() + std::string(" LOG OPEN"));
}

void Log::write(Severity severity, std::string file, unsigned line, std::string logText, ...) {
  if(severity >= logLevel) {
    std::stringstream ss;

    ss << getTimeStamp();
    ss << " " << std::setw(5) << severity << " ";
    ss << std::setw (maxFileNamePadding) << file;
    ss << " (" << std::setw (maxLineNumPadding) << std::to_string(line) << "): ";

    char logBuffer[logBufferSize];
    va_list args;
    va_start (args, logText);
    vsnprintf (logBuffer, logBufferSize, logText.c_str(), args);
    va_end (args);
    ss << std::string(logBuffer);
    target.write(ss.str());
  }
}

void Log::setLogLevel(Severity newLogLevel) {
  logLevel = newLogLevel;
  std::stringstream ss;
  ss << getTimeStamp() << " NEW LOGLEVEL: " << newLogLevel;
  target.write(ss.str());
}

Log::~Log() {
  target.write(getTimeStamp() + std::string(" LOG CLOSE"));
  target.close();
}


std::string Log::getTimeStamp() {
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%F %T",timeinfo);
  return std::string(buffer);
}

} /* namespace Logger */
