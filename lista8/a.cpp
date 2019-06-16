#include <bits/stdc++.h>
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410
using namespace std;

void resolve (int r, int c, vector<string> &mapa){
    queue<vector<int> > fila;
    map<string, bool> used;

    long long int count = 0;
    fila.push(vector<int> {r, c});
    used[to_string(r) + '|' + to_string(c)] = true;

    while (!fila.empty()){
        vector<int> actual = fila.front();
        count++;
        //cout << actual[0] << " " << actual[1] << endl;
        fila.pop();

        int xMin = max(0, actual[0]-1);
        int yMin = max(0, actual[1]-1);
        int xMax = min(int(mapa.size()) -1, actual[0] + 1);
        int yMax = min(int(mapa[0].size()) -1, actual[1] + 1);

        for (int i = xMin; i <= xMax; i++){
            for (int j = yMin; j <= yMax; j++){
                if (mapa[i][j] == 'W'){
                    if (!(used[to_string(i) + '|' + to_string(j)])){
                        fila.push(vector<int> {i, j});
                        used[to_string(i) + '|' + to_string(j)] = true;
                    }
                }
            }
        }
    }
    
    cout << count << endl;
}

int main (){
    int t;
    cin >> t;
    string aux;
    cin >> aux;

    while (t--){
        vector<string> map;
        map.push_back(aux);

        while (cin >> aux){
            if (aux[0] != 'L' && aux[0] != 'W') break;

            map.push_back(aux);
        }
        int aux2;
        cin >> aux2;
        resolve(stoi(aux)-1, aux2-1, map);
        while (cin >> aux){
            if (aux[0] == 'L' || aux[0] == 'W') break;
            cin >> aux2;
            resolve(stoi(aux)-1, aux2-1, map);
        }

        if (t) cout << endl;
    }
}