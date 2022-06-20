#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> profit {10,30,40,20,55};
    vector<int> time {2,2,1,3,1};
    int tmax = time[0];
    for(auto i: time){
        if(tmax<i) tmax = i;
    }
    priority_queue<pair<int,int>> maxHeap;
    for(int i=0;i<profit.size();i++){
        maxHeap.push({profit[i],time[i]});
    }
    vector<int> pos(tmax+1,-1);
    while(!maxHeap.empty()){
        pair<int,int> ele = maxHeap.top();
        int x = ele.first;
        int y = ele.second;
        if(pos[y]==-1){
            pos[y] = x;
        }else{
            y--;
            while(y>=0){
                if(pos[y]==-1){
                    pos[y] = x;
                    break;
                }
                else y--;
            }
        }
        maxHeap.pop();
    }
    for(int i=1;i<pos.size();i++){
        cout<< pos[i]<< " ";
    }
}