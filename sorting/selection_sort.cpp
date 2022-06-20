#include <iostream>
using namespace std;

int main(){
    int arr[] = {1,13,9,15,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[min_idx]>arr[j])
                min_idx = j;
        }
        swap(arr[i],arr[min_idx]);
    }
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
}