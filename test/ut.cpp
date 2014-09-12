/*
 * ut.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: libesz
 */

#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
