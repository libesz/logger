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
  Log *globalLog;

  #define STARTLOG(target, logLevel) globalLog = new Log(target, logLevel)
  #define STOPLOG() delete globalLog

}

#endif /* GLOBALLOG_H_ */
