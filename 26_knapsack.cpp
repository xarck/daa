#include<bits/stdc++.h>
using namespace std;


int main(){
    int num,x,bagSize;
    vector<int> weight,profit;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>x;
        weight.push_back(x);
    }
    for(int i=0;i<num;i++){
        cin>>x;
        profit.push_back(x);
    }
    cin>>bagSize;
    vector<float> properweight = {};
    
    int n = weight.size();
    
     for(int i=0;i<n;i++){
        properweight.push_back((float)profit[i]/weight[i]);
    }
    vector<pair<float,pair<int,int>>> ppi;
    priority_queue<pair<float,pair<int,int>>> maxHeap;
    

    for(int i=0;i<n;i++){
        maxHeap.push({properweight[i],{profit[i],weight[i]}});
    }
    float totalProfit = 0.f;

    while(!maxHeap.empty()){
        pair<float,pair<int,int>> ele = maxHeap.top();
        int currWeight = ele.second.second;
        int currProfit = ele.second.first;
        if(bagSize-currWeight>0){
            totalProfit+=currProfit;
            bagSize-=currWeight;
        }else{
            float fprofit = (float)bagSize*currProfit/currWeight;
            bagSize = 0;
            totalProfit+=fprofit;
        }
        maxHeap.pop();
    }

    cout<< totalProfit;


}