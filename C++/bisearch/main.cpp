#include <iostream>
using namespace std;


int bisearch(int* arr, int value, int length){
    int left = 0;
    int right = length - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == value)
            return mid;
        if(arr[mid] > value)
        {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char* argv[]){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr)/sizeof(int);
    int input;
    while(cin>>input)
    {
        cout<<bisearch(arr, input, len)<<endl;
    }
    return 0;
}
