/*
 * StreamLogTarget.h
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
 */

#ifndef STREAMLOGTARGET_H_
#define STREAMLOGTARGET_H_

#include <LogTarget.h>
#include <iostream>

namespace Logger {

class StreamLogTarget: public LogTarget {
  std::ostream &stream;
public:
  StreamLogTarget(std::ostream &newStream);
  void flush();
  void write(std::string s);
  void open();
  void close();

  virtual ~StreamLogTarget();
};

} /* namespace Logger */

#endif /* STREAMLOGTARGET_H_ */
