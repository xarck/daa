#include <bits/stdc++.h>
using namespace std;

int maxDivide(int a, int b)
{
    while (a % b == 0)
        a = a / b;
    return a;
}
 
int isUgly(int no)
{
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);
 
    return (no == 1) ? 1 : 0;
}
 
int getNthUglyNo(int n)
{
    int i = 1;     
    int count = 1;
    while (n > count)
    {
        i++;
        if (isUgly(i))
            count++;
    }
    return i;
}

int main(){
    int n,x;
    cin>> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    for(int i=0;i<n;i++){
        cout<< getNthUglyNo(nums[i]) << endl;
    }
}