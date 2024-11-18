#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;
    heap(){
        size=0;        
    }
    void insert(int d){    
        arr[size]=d;
        size++;
        int i=size-1;
        while(i>0){
            int p=(i-1)/2;
            if(arr[i]>arr[p]){
                swap(arr[i],arr[p]);
                i=p;
            }
            else{
                return;
            }
        }
    }
    void del(){
        arr[0]=arr[size-1];
        size--;
        int i=0;
         heapify(arr, size, 0);
        }
        void heapify(int arr[],int n,int i){
             int left=i*2+1;
            int right=i*2+2;
            int l=i;
            if(left<n && arr[left]>arr[l]){
                l=left;
            }
            if(right<n&&arr[right]>arr[l]){
                l=right;
            }
            if(l!=i){
                swap(arr[l],arr[i]);
                heapify(arr,n,l);
            }
        }
        void print(){
            for(int i=0;i<size;i++){
                cout<<" "<<arr[i];

            }
        }
        void buildheap(){
            for (int i=(size-1)/2;i>=0;i--){
                heapify(arr,size,i);
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
    cout<<"\n basic array:"<<endl;
    h.print();
    
    h.buildheap();
    cout<<" \n heap array:"<<endl;
    h.print();
    cout<<" \n heap array after deletion:"<<endl;
    h.del();
    h.print();


}