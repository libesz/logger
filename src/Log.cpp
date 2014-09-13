/*
 * Copyright 2014 Gergo Huszty.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *  Log.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Gergo Huszty
 */

#include <Log.h>
#include <cstdio>
#include <cstdarg>
#include <iostream>
#include <ctime>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <memory>

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

Log::Log(LogTarget& newTarget, Severity newSeverity):
    target(newTarget),
    logLevel(newSeverity),
    allowExpandIfTooLong(false) {
  target.open();
  target.write(getTimeStamp() + std::string(" LOG OPEN"));
}

void Log::write(Severity severity, std::string file, unsigned line, std::string logText, ...) throw(std::out_of_range) {
  if(severity >= logLevel) {
    std::stringstream ss;

    ss << getTimeStamp();
    ss << " " << std::setw(5) << severity << " ";
    ss << std::setw (maxFileNamePadding) << file;
    ss << " (" << std::setw (maxLineNumPadding) << std::to_string(line) << "): ";

    //char *logBuffer = new char[logText.size() + logBufferPadSize];
    int bufferSize = logText.size() + logBufferPadSize;
    std::unique_ptr<char[]> logBuffer(new char[bufferSize]);
    va_list args;
    va_start(args, logText);
    int resultSize = vsnprintf(logBuffer.get(), bufferSize, logText.c_str(), args);
    va_end (args);
    if(bufferSize<resultSize) {
      if(allowExpandIfTooLong) {
        logBuffer.reset(new char[resultSize+1]);
        va_start(args, logText);
        int resultSize2 = vsnprintf(logBuffer.get(), resultSize+1, logText.c_str(), args);
        va_end(args);
        if(resultSize<resultSize2)
          throw std::out_of_range("vsnprintf result is too long");
      } else {
        target.write(getTimeStamp() + std::string(" TRUNCATED LOG:"));
      }
    }
    ss << std::string(logBuffer.get());
    target.write(ss.str());
  }
}

void Log::setLogLevel(Severity newLogLevel) {
  logLevel = newLogLevel;
  std::stringstream ss;
  ss << getTimeStamp() << " NEW LOGLEVEL: " << newLogLevel;
  target.write(ss.str());
}

void Log::setAllowExpandIfTooLong(bool newAllowExpandIfTooLong) {
  allowExpandIfTooLong = newAllowExpandIfTooLong;
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
