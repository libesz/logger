/*
 * GlobalLog.h
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
 */

#ifndef GLOBALLOG_H_
#define GLOBALLOG_H_

#include <Log.h>
namespace Logger {
  extern Log *globalLog;
}
using namespace Logger;

#define STARTLOG(target, logLevel) globalLog = new Log(target, logLevel)
#define STOPLOG() delete globalLog
#define LOG(text) globalLog->write(Severity::INFO, std::string(__FILE__), __LINE__, std::string(text))

#endif /* GLOBALLOG_H_ */
