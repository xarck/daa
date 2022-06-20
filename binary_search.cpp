#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr,int l,int r,int key){
    if(r>=l){
        int mid = l + (r-l)/2;
        if(arr[mid]==key) return mid;
        if(key>arr[mid]) return binarySearch(arr,mid+1,r,key);
        else return binarySearch(arr,l,mid-1,key);
    }
    return -1;
}

int main(){
    vector<int> arr{1,5,5,5,7,9,12,15,17};
    int n= arr.size();
    int key  =5;
    int mid = binarySearch(arr,0,n,key);
    int c1 = mid-1;
    int c2 = mid+1;
    int count = 1;
    cout<< mid << c1<< c2<<endl;
    while(c1>=0){
        if(arr[c1]==key) {
            count++;
            c1--;
        }else{
            break;
        }
    }
    while(c2<=n){
        if(arr[c2]==key) {
            count++;
            c2++;
        }else{
            break;
        }
    }
    cout<< count;
}