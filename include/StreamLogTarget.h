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
 *  StreamLogLogger.h
 *
 *  Created on: Sep 6, 2014
 *      Author: Gergo Huszty
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
