#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    vector<int> sTime,fTime,act;
    for(int i=0;i<n;i++){
        cin>>x;
        sTime.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        fTime.push_back(x);
    }
    for(int i=1;i<=n;i++){
        act.push_back(i);
    }

    vector<pair<int , pair<int , int>>> acts;

    for(int i = 0 ; i < 11 ; i++)
    {
        acts.push_back({fTime[i] ,{sTime[i] , act[i]}});
    }

    sort(acts.begin() , acts.end());

    vector<int> ans;
    int count = 0;
 
    for(auto it : acts) 
    {
        int fTime = it.first ;
        int sTime =  it.second.first; 
        int act =  it.second.second;

        int prevF ;

        if(count == 0)
        {
            ans.push_back(act);
            prevF = fTime;
            count++;
        }
        else if(sTime >= prevF){
            ans.push_back(act);
            prevF = fTime;
        }
            
                
    }
    cout<< ans.size() << endl;
    for(auto it : ans)
        cout << it << " ";


    return 0;
}