#include <iostream>
using namespace std;

int main(){
    int arr[] = {1,13,9,15,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
}