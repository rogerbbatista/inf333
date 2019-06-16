#include <bits/stdc++.h>
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1095
using namespace std;

int key;
unordered_map<long long int, int> solved;

long long int hashh(string uses, int k){
    long long aux = 0;
    for (auto &i: uses){
        aux += (i-'0') * k;
    }
    return aux;
}

int solve (vector< vector<int> > &turtles, vector<bool> &used, string uses, int w = 999999999){
    if (!w) return 0;

    int m = 0;
    for (int i = 0; i < turtles.size(); i++){
        if (!used[i]){
            if (turtles[i][0] <= w){
                stringstream ss;
                ss << i;
                uses.push_back(ss.str()[0]);
                used[i] = true;
                
                int wAux = min(turtles[i][1], w);
                if (wAux - turtles[i][0] >= 0)
                    m = max(m, 1+solve(turtles, used, uses, wAux - turtles[i][0]));

                uses.pop_back();
                used[i] = false;
            }
        }
    }

    return m;
}

int main(){
    int w, s;
    vector< vector<int> > turtles;
    while (cin >> w >> s){
        turtles.push_back({w, s});
    }
    key = turtles.size()+1;
    vector<bool> used(turtles.size());
    string uses = "";
    int sol = solve(turtles, used, uses);

    cout << sol << endl;
}