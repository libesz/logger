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
#define TRACE(text,...) Logger::globalLog->write(Logger::Severity::TRACE,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define DEBUG(text,...) Logger::globalLog->write(Logger::Severity::DEBUG,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define LOG(text,...) Logger::globalLog->write(Logger::Severity::INFO,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define WARN(text,...) Logger::globalLog->write(Logger::Severity::WARN,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define ERR(text,...) Logger::globalLog->write(Logger::Severity::ERR,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define CRIT(text,...) Logger::globalLog->write(Logger::Severity::CRIT,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)

#endif /* GLOBALLOG_H_ */
