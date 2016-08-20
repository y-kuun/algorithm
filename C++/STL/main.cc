#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    auto itv = v.begin();
    auto itvv = itv + 5;
    cout<<*itv<<"--"<<*itvv<<endl;
    v.erase(itvv);
    cout<<*itv<<"--"<<*itvv<<endl;
    return 0;
}
