#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
 void bfstriversal(vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
 
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
 
        for (int i = 0; i < graph[current].size(); i++) {
            if (!visited[graph[current][i]]) {
                q.push(graph[current][i]);
                visited[graph[current][i]] = true;
            }
        }
    }
}
    int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1, 5},
        {2, 4}
    };
    bfstriversal(graph, 0);
    return 0;

    }