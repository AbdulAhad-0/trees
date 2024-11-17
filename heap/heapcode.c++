#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        size=0;
        arr[0]=-1;
    }
    void insert(int d){
         size++;
        int idx=size;
        arr[size]=d;
        while(idx>1){
            int  par =idx/2;
            if(arr[par]<arr[idx]){
            swap(arr[par],arr[idx]);
            idx=par;}
            else{
                return;
            }
        }
    }
    void display(){
        for(int i=1;i<=size;i++){
            cout<<" "<<arr[i];
        }
    }
};
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.display();
}