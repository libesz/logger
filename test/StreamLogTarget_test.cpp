/*
 * StreamLogTarget_test.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
 */

#include <StreamLogTarget.h>
#include <gtest/gtest.h>
#include <sstream>

namespace Logger {

TEST(StreamLogTargetTest, TestBasicWrite) {
  const std::string sampleLogText = "hello";
  std::stringstream stream;
  StreamLogTarget t(stream);
  t.write(sampleLogText);
  std::stringstream firstLine;
  firstLine << sampleLogText << std::endl;
  EXPECT_EQ(firstLine.str(), stream.str());
}

} /* namespace Logger */
