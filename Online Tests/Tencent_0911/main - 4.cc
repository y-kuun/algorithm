#include <cstdio>
#include <set>
using namespace std;

bool func(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char** argv) {
    int num;
    scanf("%d", &num);
    set<int> num_set;

    for (int i = 2; i <= num; i++) {
        if (func(i)) num_set.insert(i);
    }
    int result;

    set<int>::iterator it;
    set<int>::iterator rit;

    for (it = num_set.begin(); it != num_set.end(); it++) {
        rit = num_set.find(num - (*it));
        if (rit != num_set.end()) {
            result++;
            num_set.erase(it);
            if ((*it) != num - (*rit)) {
                num_set.erase(num - (*rit));
            }
        }
    }

    printf("%d", result);

    return 0;
}