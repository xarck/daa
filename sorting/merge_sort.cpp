#include <iostream>
using namespace std;

void merge(int arr[],int p,int q,int r){
    int n1 = q-p+1;
    int n2 = r-q;

    int L1[n1],L2[n2];
    
    for(int i=0;i<n1;i++)
        L1[i] = arr[p+i];
    for(int j=0;j<n2;j++)
        L2[j] = arr[q+j+1];
    
    int i=0,j=0,k=p;
    
    while(i<n1&&j<n2){
        if(L1[i]<=L2[j]) arr[k++] = L1[i++];
        else arr[k++] = L2[j++];
    }
    
    while(i<n1) arr[k++] = L1[i++];
    while(j<n2) arr[k++] = L2[j++];
}


void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int arr[] = {1,13,9,15,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
}