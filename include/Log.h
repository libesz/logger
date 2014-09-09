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

namespace Logger {

enum class Severity {
  TRACE,
  DEBUG,
  INFO,
  WARN,
  ERR,
  CRIT
};

class Log {
  Log();
  LogTarget &target;
  Severity logLevel;
public:
  Log(LogTarget &newTarget, Severity logLevel);
  void write(Severity severity, std::string file, unsigned line, std::string logText);
  virtual ~Log();
  void setLogLevel(Severity newLogLevel);
};

} /* namespace Logger */

#endif /* LOG_H_ */
