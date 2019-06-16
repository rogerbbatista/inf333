// Dupla:
// Róger Vieira Batista - 92538
// 

#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i = 0; i < n; i++)

vector<int> last(2);
vector<int> first(2);

bool solve(vector< vector<int> > pieces, int next, int spaces){
    if (spaces == 0){
        if (next == last[0]) return true;
        else return false;
    }

    f(i, pieces.size()){
        if (pieces[i][0] == next){
            vector<int> actual = pieces[i];
            pieces[i][0] = pieces[i][1] = -1;
            if (solve(pieces, actual[1], spaces-1)){
                return true;
            }
            pieces[i] = actual;
        } else if (pieces[i][1] == next){
            vector<int> actual = pieces[i];
            pieces[i][0] = pieces[i][1] = -1;
            if (solve(pieces, actual[0], spaces-1)){
                return true;
            }
            pieces[i] = actual;
        }
    }

    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    while (n){
        cin >> first[0] >> first[1];
        cin >> last[0] >> last[1];

        vector< vector<int> > pieces(m, vector<int>(2));
        f(i, m) cin >> pieces[i][0] >> pieces[i][1];
        
        if (solve(pieces, first[1], n)){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";

        cin >> n >> m;
    }
}