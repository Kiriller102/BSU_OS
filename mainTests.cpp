//
// Created by Kirill on 12.04.2023.
//

#include "gtest/gtest.h"
#include <cstdio>
#include <random>
#include <ctime>
#include <boost/process.hpp>

namespace bp = boost::process;

TEST(testMain, test) {
  bp::opstream inPipe;
  bp::ipstream outPipe;

  bp::child mainProcess("main",
                           bp::std_in < inPipe,
                           bp::std_out > outPipe);

//  std::stringstream output;
//  inPipe << "hi";
//  inPipe << 4;
//  while (std::getline(outPipe, output, '\r')) {
//    std::cout << output << std::flush;
//  }
  std::string output;
  inPipe << "hi";
  inPipe << 4;
  std::getline(outPipe, output);
  inPipe.close();
  outPipe.close();

  EXPECT_EQ(output, "HiHiHiHi");
}