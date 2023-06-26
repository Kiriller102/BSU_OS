//
// Created by Kirill on 20.04.2023.
//

#include "interface.h"

void Sleep(uint32_t x) {
  boost::this_thread::sleep(boost::posix_time::milliseconds(x));
}

std::pair<int, int> min_max(std::vector<int> &vec) {
  boost::unique_lock<boost::mutex> lock(mutex);

  if (vec.empty()) {
    std::cerr << "ERROR: empty  array";
    return {0, 0};
  }
  int max = 0, min = 0;
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[min] > vec[i]) {
      min = i;
    }
    Sleep(7);
    if (vec[max] < vec[i]) {
      max = i;
    }
    Sleep(7);
  }
  std::cout << "min: " << vec[min] << '\n';
  std::cout << "max: " << vec[max] << std::endl;
  return {min, max};
}

int average(std::vector<int> &vec) {
  boost::unique_lock<boost::mutex> lock(mutex);


  if(vec.empty()) {
    std::cerr << "ERROR: empty  array";
    return 0;
  }
  int64_t sum = vec[0];
  for (int i = 1; i < vec.size(); ++i) {

    if (vec[i] > 0 && INT64_MAX - vec[i] < sum) {
      std::cerr << "ERROR: sum outside the long long max range";
      return 0;
    }

    if (vec[i] < 0 && INT64_MIN - vec[i] > sum) {
      std::cerr << "ERROR: sum outside the long long min range";
      return 0;
    }

    sum += vec[i];
    Sleep(12);
  }
  int average = int(sum / int64_t(vec.size()));
  std::cout << "Average: " << average << std::endl;
  return average;
}