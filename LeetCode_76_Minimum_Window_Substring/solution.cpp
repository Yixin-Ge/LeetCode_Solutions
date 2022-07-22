#include <unordered_map>
#include <climits>
#include "solution.h"

using namespace std;

bool Solution::check(unordered_map<char, int> &sCount, unordered_map<char, int> &tCount) {
    for(auto p: tCount) {
        if(sCount[p.first] < p.second) return false;
    }
    return true;
}


string Solution::minWindow(string s, string t) {
    unordered_map<char, int> tCount;
    unordered_map<char, int> sCount;

    for(char c: t) {
        tCount[c]++;
    }

    int left = 0;
    int right = 0;
    int maxSize = INT_MAX;
    int ansLeft = -1;

    sCount[s[0]]++;

    int sSize = s.size();

    while(left < sSize) {
        if(!check(sCount, tCount)) {
            if(right == sSize - 1) break;
            else {
                right++;
                sCount[s[right]]++;
            }
        }
        else {
            while(check(sCount,tCount) && left <= right) {
                if(maxSize > right - left + 1) {
                    maxSize = right - left + 1;
                    ansLeft = left;
                    // result = s.substr(left, maxSize);
                }
                sCount[s[left]]--;
                left++;
            }
        }

    }

    if(ansLeft == -1) return "";
    else return s.substr(ansLeft, maxSize);
}