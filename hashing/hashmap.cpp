#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map <string, int > m;
    // insert approach 1
    pair<string ,int> p=make_pair("mera",1);
    m.insert(p);
    //insert approach 2
    pair<string,int> e("hello",2);
    m.insert(e);
    //insert approach 3
    m["world"]=4;
    //Q: what will happen Ans: override
    m["world"]=3;
    //search
    cout<<m["hello"]<<endl;
    //error will came if u used m.at["unknowval"].
    // but there is a trick to use it after m["known val "]which doesn't give error
    // bcuz it automatically alot default val(o) to unknown key
    cout<<m["abcs"]<<endl;
    cout<<m.at("abcs")<<endl;
    //size
    cout<<m.size()<<endl;
    //to check presence if absent ->zero dega
    cout<<m.count("hello")<<endl;
    //erase 
    m.erase("abcs");
    cout<<m.size()<<endl;
    //access full map
    // for(auto i:m){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }


    //2nd method iterator basically it print in unorder omplexity 0(1)
    unordered_map<string ,int>:: iterator i=m.begin();
    while(i!=m.end()){
    cout<<i->first<<" "<<i->second<<endl;
    i++ ;
    }
    // use map or order print   complexity 0(n)
    // map<string ,int>:: iterator i=m.begin();
    // while(i!=m.end()){
    // cout<<i->first<<" "<<i->second<<endl;
    // i++ ;
    // }

    //
}