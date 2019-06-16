#include <bits/stdc++.h>
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400
using namespace std;

void bfs (int v, vector<vector<int> > &adj, vector<bool> &used){
    queue<int> fila;
    fila.push(v);

    while (!fila.empty()){
        int a = fila.front();
        fila.pop();

        for (int i = 0; i < adj[a].size(); i++){
            if (!(used[adj[a][i]])){
                fila.push(adj[a][i]);
                used[adj[a][i]] = true;
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    
    string edge = "!";
    while (t--){
        char max;
        int n;
        if (edge[0] == '!') {
            cin >> max;
            n = max - 'A' + 1;
        }else{
            cout << "\n";
            n = edge[0] - 'A' + 1;
        }

        vector<vector<int> > adj(n);
        vector<bool> used (n);


        while(cin >> edge){
            if (edge.size() > 1){
                adj[edge[0]- 'A'].push_back(edge[1]- 'A');
                adj[edge[1]- 'A'].push_back(edge[0]- 'A');
            }else{
                break;
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++){
            if (!used[i]){
                bfs(i, adj, used);
                count++;
            }
        }

        cout << count << endl;
    }
    
}