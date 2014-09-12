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
 *  Log.h
 *
 *  Created on: Sep 6, 2014
 *      Author: Gergo Huszty
 */

#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <LogTarget.h>
#include <stdexcept>

namespace Logger {

enum class Severity {
  TRACE,
  DEBUG,
  INFO,
  WARN,
  ERR,
  CRIT
};


std::ostream& operator<<(std::ostream &out, Severity s) throw(std::runtime_error);

class Log {
  const unsigned logBufferSize = 128;
  const unsigned maxFileNamePadding = 15;
  const unsigned maxLineNumPadding = 3;
  Log();
  LogTarget &target;
  Severity logLevel;
  std::string getTimeStamp();
public:
  Log(LogTarget &newTarget, Severity logLevel);
  void write(Severity severity, std::string file, unsigned line, std::string logText, ...);
  virtual ~Log();
  void setLogLevel(Severity newLogLevel);
};

} /* namespace Logger */

#endif /* LOG_H_ */
