//
// Created by yixin on 22/07/22.
//
#ifndef LEETCODE_IO_SOLUTION_H
#define LEETCODE_IO_SOLUTION_H
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool check(unordered_map<char, int> &sCount, unordered_map<char, int> &tCount);
    string minWindow(string s, string t);
};

#endif //LEETCODE_IO_SOLUTION_H
