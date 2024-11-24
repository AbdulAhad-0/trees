#include <iostream>
#include <vector>
using namespace std;
class dataitem{
    public:
    int data;
    int key;
};
#define insize 20
#define loadtreshold 0.7
class hashtable{
    vector<dataitem*> hasharray;
    dataitem * dummy;
    int cursize;
    int tablesize;
    public:
    hashtable(){
        tablesize=insize;
        cursize=0;
        hasharray.resize(tablesize, nullptr);
        dummy=new dataitem;
        dummy->data=-1;
        dummy->key=-1;
    }
    void resizetable(){
        int oldsize=tablesize;
        tablesize*=2;
        vector<dataitem*> old = hasharray;
        hasharray.resize(tablesize,nullptr);
        cursize=0;
        for(int i=0;i<oldsize;i++){
            if(old[i]!=nullptr&&old[i]!=dummy){
                insert(old[i]->data,old[i]->key);
                delete old[i];
            }
        }
    }
    double loadfactor(){
        return (double)(cursize/tablesize);
        }
    int hashcode(int key) {
        return key % tablesize;
    }
    void insert(int data,int key){
        if(loadfactor()>loadtreshold){
            resizetable();
        }
        dataitem *a=new dataitem;
        a->data=data;
        a->key=key;
        int hidx=hashcode(key);
        while(hasharray[hidx]!=nullptr&&hasharray[hidx]!=dummy&&hasharray[hidx]->key!=-1){
            if(hasharray[hidx]->key==key){
                delete a;
                hasharray[hidx]->data=data;
                return;
            }
            hidx=(hidx+1)%tablesize;
        }
        hasharray[hidx]=a;
        cursize++;
    }
    dataitem *deleteitem(int key){
         int hidx=hashcode(key);
        while(hasharray[hidx]!=nullptr&&hasharray[hidx]!=dummy&&hasharray[hidx]->key!=-1){
            if(hasharray[hidx]->key==key){
                dataitem *temp=hasharray[hidx];
                hasharray[hidx]=dummy;
                cursize--;
                return temp;
            }
            hidx=(hidx+1)%tablesize;
        }
      return nullptr;
    }
    dataitem* search(int key){
         int hidx=hashcode(key);
        while(hasharray[hidx]!=nullptr&&hasharray[hidx]!=dummy&&hasharray[hidx]->key!=-1){
            if(hasharray[hidx]->key==key)
                return hasharray[hidx];
            hidx=(hidx+1)%tablesize;
        }
        return nullptr;
    }
    void display(){
        for (int i=0;i< tablesize;i++) {
            if (hasharray[i]!=nullptr&&hasharray[i]!=dummy)
                cout<<" ("<< hasharray[i]->key<<","<< hasharray[i]->data<<")"; 
            else
                cout << " ~~ ";
        }
        cout << endl;
    }
};
int main(){
     hashtable hashTable;
    hashTable.insert(1, 20);
    hashTable.insert(2, 70);
    hashTable.insert(42, 80);
    hashTable.insert(4, 25);
    hashTable.insert(12, 44);
    hashTable.insert(14, 32);
    hashTable.insert(17, 11);
    hashTable.insert(13, 78);
    hashTable.insert(37, 97);
    cout << "Contents of Hash Table: ";
    hashTable.display();
    int ele=37;
    cout <<"Searching for element: "<<ele;
    dataitem*item = hashTable.search(ele);
    if (item != nullptr) {
        cout << "\nElement found: ("<<item->key << ", "<< item->data<<")";
    } else {
        cout << "\nElement not found";
    }
    hashTable.deleteitem(ele);
    cout << "\nHash Table contents after deletion: ";
    hashTable.display();
    return 0;
}