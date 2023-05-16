//
// Created by Kirill on 20.04.2023.
//

#ifndef THREADS_LAB__INTERFACE_H_
#define THREADS_LAB__INTERFACE_H_

#include <boost/thread.hpp>
#include <future>
#include <iostream>
#include <vector>

extern boost::mutex mutex;
extern boost::condition_variable condition;

void Sleep(uint32_t x);

std::pair<int, int> min_max(std::vector<int> &vec);

int average(std::vector<int> &vec);

#endif //THREADS_LAB__INTERFACE_H_
