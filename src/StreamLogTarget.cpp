/*
 * StreamLogTarget.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
 */

#include <StreamLogTarget.h>

namespace Logger {

StreamLogTarget::StreamLogTarget(std::ostream &newStream): stream(newStream) {

}

void StreamLogTarget::flush() {
}

void StreamLogTarget::write(std::string s) {
  stream << s << std::endl;
}

void StreamLogTarget::open() {
}

void StreamLogTarget::close() {
}

StreamLogTarget::~StreamLogTarget() {
  // TODO Auto-generated destructor stub
}

} /* namespace Logger */
