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
 *  LogTarget.h
 *
 *  Created on: Sep 6, 2014
 *      Author: Gergo Huszty
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
