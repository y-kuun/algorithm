/*
 * Complete the function below.
 */

#include <iostream>
#include <string>

using namespace std;

string longest_repeating_pattern(string pattern_format, string search_string) {
    if (pattern_format.size() == 0 && search_string.size() == 0) return "";
    int maxlen = -1;
    int maxloc;
    for (int i = 0; i < search_string.size(); i++) {
        int cur_loc = i;
        for (int j = 0;; j++) {
            int tmp = (j % pattern_format.size());
            if (cur_loc == search_string.size()) {
                if (maxlen < cur_loc - i) {
                    maxlen = cur_loc - i - tmp;
                    maxloc = i;
                    i = search_string.size();
                }
                break;
            }
            if (pattern_format[tmp] == 'L' && search_string[cur_loc] >= 'a' &&
                search_string[cur_loc] <= 'z') {
                cur_loc++;
            } else if (pattern_format[tmp] == 'U' &&
                       search_string[cur_loc] >= 'A' &&
                       search_string[cur_loc] <= 'Z') {
                cur_loc++;
            } else if (pattern_format[tmp] == 'D' &&
                       search_string[cur_loc] >= '0' &&
                       search_string[cur_loc] <= '9') {
                cur_loc++;
            } else {
                if (maxlen < cur_loc - i) {
                    maxlen = cur_loc - i - tmp;
                    maxloc = i;
                }
                break;
            }
        }
    }
    return search_string.substr(maxloc, maxlen);
}

int main() {
    string res;
    string _pattern_format("LUD");

    string _search_string("zZ1_example_aA1bB2c");

    res = longest_repeating_pattern(_pattern_format, _search_string);
    return 0;
}
