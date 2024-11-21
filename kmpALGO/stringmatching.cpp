#include<iostream>
#include<vector>
using namespace std;
 void find_lps(vector<int>& lps,string s){
    int pre=0,suf=1;
    while(suf<s.size()){
        //matched
        if(s[pre]==s[suf]){
            lps[suf]=pre+1;
            pre++;
            suf++;
        }
        else{ //not matched 🤔
            if(pre==0){
                lps[suf]=0;
                suf++;
            }
            else{
                pre=lps[pre-1];
            }
        }
    }
}
int main(){
    string s="abcabdabcabdabdab";
    string n="bdabd";
    vector<int> lps(n.size(),0);
    find_lps(lps,n);
    int fir=0,sec=0;
    while(sec<n.size()&&fir<s.size()){
        if(s[fir]==n[sec]){
            fir++;
            sec++;
        }       
        else{
            if(sec==0){
                fir++;
            }
            else{
                sec=lps[sec-1];} 
        }
    }
    if(sec==n.size()){
    cout<<"index: "<<fir-sec<<endl;}
    if(fir==s.size()){
        cout<<"index: -1"<<endl;
    }
}
