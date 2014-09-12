/*
 * Log.h
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
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
