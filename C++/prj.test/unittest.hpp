#pragma once
#ifndef UNITTEST
#define UNITTEST

#include <vector>
#include <string>

template<class T>
void FillData(const int n, std::vector<T>& data) {
    data.clear();
    data.reserve(n);
    for (int i = 0; i < n; i += 1) {
        data.emplace_back(i);
    }
}

template<>
void FillData(const int n, std::vector<std::string>& data) {
    data.clear();
    data.reserve(n);
    for (int i = 0; i < n; i += 1) {
        data.emplace_back(std::to_string(i));
    }
}

#endif