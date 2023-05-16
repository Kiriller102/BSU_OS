//
// Created by Kirill on 20.04.2023.
//

#include "interface.h"
#include <boost/thread.hpp>

boost::mutex mutex;
boost::condition_variable condition;

int main(int argc, char *argv[]) {
  int n;
  std::vector<int> vec;

  std::cout << "Enter array size: ";
  std::cin >> n;

  vec.resize(n);
  std::cout << "Enter array: ";
  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i];
  }

  condition.notify_all();

  std::promise<std::pair<int, int>> minMaxPromise;
  std::promise<int> averagePromise;

  boost::thread
      t1([&minMaxPromise, &vec]() { minMaxPromise.set_value(min_max(vec)); });
  boost::thread
      t2([&averagePromise, &vec]() { averagePromise.set_value(average(vec)); });

  t1.join();
  t2.join();

  std::pair<int, int> minMaxPos = minMaxPromise.get_future().get();
  int average = averagePromise.get_future().get();
  vec[minMaxPos.first] = average;
  vec[minMaxPos.second] = average;

  for (auto i : vec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  return 0;
}