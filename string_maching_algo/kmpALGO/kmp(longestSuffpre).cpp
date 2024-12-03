#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s="abcabdabcabdabdab";
    vector<int> lps(s.size(),0);
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
    cout<<"maximum size: "<<lps[s.size()-1]<<" 😍";
}
