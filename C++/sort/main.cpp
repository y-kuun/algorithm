#include <iostream>
#include <climits>
using namespace std;

void print_arr(int arr[], const int i, const int j){
    for(int k = i; k <= j; k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}

namespace dyk{
    void swap(int arr[],const int k, const int small){
        int tmp = arr[small];
        arr[small] = arr[k];
        arr[k] = tmp;
    }
    int min(int arr[], const int left, const int right)
    {
        int min_val = INT_MAX;
        int min_pos = -1;
        for(int i = left; i <= right; i++){
            if(arr[i] < min_val){
                min_pos = i;
                min_val = arr[i];
            }
        }
        return min_pos;
    }
    int partition(int arr[],const int i, const int j){
        int pivot = arr[j];
        int small = i;
        for(int k = i; k < j; k++){
            if(arr[k] <= pivot){
                swap(arr, k, small);
                small++;
            }
        }
        swap(arr, j, small);
        cout<<"Pivot: "<< pivot << endl;
        return small;
    }
    void qsort(int arr[], const int i, const int j){
        if(i < j){
            int pos = partition(arr, i, j);
            qsort(arr, i, pos-1);
            qsort(arr, pos+1, j);
        }
    }
    void bubblesort(int arr[], int len)
    {
        cout<<"Bubble Sort!"<<endl;
        bool flag = true;
        for(int cell = len - 1; cell > 0 && flag; cell--){
            flag = false;
            for(int i = 0 ; i < cell; i++){
                if(arr[i] > arr[i+1]){
                    swap(arr, i, i+1);
                    flag = true;
                }
            }
        }
    }
    void selectsort(int arr[], int len){
        cout<<"Select Sort!"<<endl;
        for(int i = 0; i < len ; i++){
            int pos = min(arr, i, len - 1);
            swap(arr, i, pos);
        }
    }
    void insertsort(int arr[], int len){
        cout<<"Insert Sort!"<<endl;
        for(int i = 1; i < len; i++){
            int j = i;
            while(j > 0 && arr[j] < arr[j-1])
            {
                swap(arr, j, j-1);
                j--;
            }
        }
    }
}

int main(int argc, char* argv[]){
    int arr[] = {9, 4, 8, 3, 1, 2, 5, 10, 2, 5, -1};
    int len = sizeof(arr)/sizeof(int);
    print_arr(arr, 0, len -1);
    dyk::insertsort(arr, len);
    print_arr(arr, 0, len -1);
    return 0;
}
