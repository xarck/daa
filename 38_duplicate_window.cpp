#include <bits/stdc++.h>
using namespace std;

bool checkDuplicatesWithinK(vector<int> arr,int n,int k){
    for(int i=0;i<n;i++){
        int j = i+1;
        int range = k;
        while(range>0 and j<n){
            if(arr[i]==arr[j])
                return true;
            j++;
            range--;
        }
    }
    return false;
}


int main(){
    int n,n1,k,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>n1;
        vector<int> nums(n1,0);
        for(int i = 0;i<n1;i++){
            cin>>x;
            nums[i] = x;
        }
        cin>>k;
        if(checkDuplicatesWithinK(nums,n1,k))
            cout << "Duplicates not present in window " << k;
        else
            cout<< "Duplicates are present in window "<< k;
    }
    
}