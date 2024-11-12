#include<iostream>
using namespace std;
void conquer(int arr [],int mid,int si,int ei){
    int merge[ei-si+1];
    int idx1=si;
    int idx2=mid+1;
    int i=0;
    while(idx1<=mid&&idx2<=ei){
        if(arr[idx1]<arr[idx2])
        merge[i++]=arr[idx1++];
        else{
           merge[i++]=arr[idx2++]; 
        }
    }
    while(idx1<=mid){
        merge[i++]=arr[idx1++];
    }
    while(idx2<=ei){
        merge[i++]=arr[idx2++];
    }
     for (int j = 0; j < i; j++) {
        arr[si + j] = merge[j];
    }
}
void mergesort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=(ei+si)/2;
    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);
    conquer(arr,mid,si,ei);
}
int main(){
    int arr[12]={5,11,3,2,4,6,8,2,15,77,8,61};
    mergesort(arr,0,11);
    for(int i=0;i<12;i++){
        cout<<" "<<arr[i];
    }
    
}