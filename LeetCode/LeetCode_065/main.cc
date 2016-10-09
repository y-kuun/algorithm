#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isNumber(string s) {
        // positive&negative integer&flat
        bool hasDot = false;
        bool hasE = false;
        bool flaged = false;
        int start_loc = 0;
        while (start_loc < s.size() && s[start_loc] == ' ') {
            start_loc++;
        }
        for (int i = start_loc; i < s.size(); i++) {
            if (isdigit(s[i])) {
                continue;
            }
            if (s[i] == '.' && !hasDot) {
                hasDot = true;
            }
            if (s[i] == 'e' && !hasE) {
                hasE = true;
            } else
                return false;
        }
        return true;
    }
};