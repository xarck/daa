#include<bits/stdc++.h>
using namespace std;

void findPairs(vector<int>arr){
    bool found = false;
    int n = arr.size();
    unordered_map<int,pair<int,int>> H;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int prod = arr[i]*arr[j];
            if(H.find(prod)==H.end())
                H[prod] = make_pair(i,j);
            else{
                pair<int,int> pp = H[prod];
                cout << arr[pp.first] << " " << arr[pp.second] << " and " << arr[i]<<" "<<arr[j]<<endl;
                found = true;
            }
        }
    }

    if(!found)
        cout<< "No Pairs Found" << endl;
}

int main(){
    int n,x;
    cin>> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    findPairs(nums);
}