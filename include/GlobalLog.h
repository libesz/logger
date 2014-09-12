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

#include <string.h>

#define FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define STARTLOG(target, logLevel) Logger::globalLog = new Logger::Log(target, logLevel)
#define STOPLOG() delete Logger::globalLog
#define LOGLEVEL(newLevel) Logger::globalLog->setLogLevel(newLevel)
#define LOG(text,...) Logger::globalLog->write(Logger::Severity::INFO,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)

#endif /* GLOBALLOG_H_ */
