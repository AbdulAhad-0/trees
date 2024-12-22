#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/**
 * Given the following graph:
 * 
 *     0
 *    / \
 *   1   2
 *  / \   \
 * 3   4   5
  */
void dfs( vector<vector<int>> &g,int s){
    vector<bool> visited(g.size(),false);
    stack<int> a;
    a.push(s);
    visited[s]=true;
    while(!a.empty()){
        int current=a.top();
        a.pop();
        cout<<current<<" ";
        for(int i=0;i<g[current].size();i++){
            if(!visited[g[current][i]]){
                a.push(g[current][i]);
                visited[g[current][i]]=true;
            }
        }
    }
}

int main(){
    vector<vector<int>> graph={{1,2},{0,3,4},{0,5},{1},{1,5},{2,4}};
    // graph ={    0->1,2 1-> 0,3,4 2->0,5 3->1 4->1,5 5->2,4}
    dfs(graph,0);
    return 0;
    //output: 0 2 5 4 1 3
}