/*
 * LogTarget.h
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
 */

#ifndef LOGTARGET_H_
#define LOGTARGET_H_

#include <string>

namespace Logger {

class LogTarget {
public:
  LogTarget();
  virtual void flush() = 0;
  virtual void write(std::string s) = 0;
  virtual void open() = 0;
  virtual void close() = 0;
  virtual ~LogTarget();
};

} /* namespace Logger */

#endif /* LOGTARGET_H_ */
