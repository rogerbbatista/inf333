// Dupla:
// Róger Vieira Batista - 92538
// 

#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i = 0; i < n; i++)
#define fm(i,m,n) for(int i = m; i <= n; i++)

void certamenteNaoEhUmaDFS(vector< vector<int> > &hill, vector< vector<int> > &mark, pair<int, int> pos){
    int xMin = max(0, pos.first-1);
    int aux = hill.size();
    int xMax = min(aux-1, pos.first+1);
    int yMin = max(0, pos.second-1);
    aux = hill[0].size();
    int yMax = min(aux-1, pos.second+1);
    

    fm(i,xMin,xMax){
        if (i != pos.first){
            if (hill[pos.first][pos.second] > hill[i][pos.second]){
                if (mark[i][pos.second] < mark[pos.first][pos.second]+1){
                    mark[i][pos.second] = mark[pos.first][pos.second]+1;
                    certamenteNaoEhUmaDFS(hill, mark, make_pair(i, pos.second));
                }
            }else{
                if (mark[i][pos.second] == -1){
                    mark[i][pos.second] = 1;
                    certamenteNaoEhUmaDFS(hill, mark, make_pair(i, pos.second));
                }
            }
        }
    }

    fm(i,yMin,yMax){
        if (i != pos.second){
            if (hill[pos.first][pos.second] > hill[pos.first][i]){
                if (mark[pos.first][i] < mark[pos.first][pos.second]+1){
                    mark[pos.first][i] = mark[pos.first][pos.second]+1;
                    certamenteNaoEhUmaDFS(hill, mark, make_pair(pos.first, i));
                }
            }else{
                if (mark[pos.first][i] == -1){
                    mark[pos.first][i] = 1;
                    certamenteNaoEhUmaDFS(hill, mark, make_pair(pos.first, i));
                }
            }
        }
    }

}

int main(){
    int t;
    cin >> t;

    while (t--){
        string name;
        int r, c;
        cin >> name >> r >> c;

        vector< vector<int> > hill(r, vector<int>(c));
        vector< vector<int> > mark(r, vector<int>(c, -1));

        pair<int, int> pos(0,0);
        int max = -1;
        f(i, r){
            f(j, c){
                cin >> hill[i][j];
                if (hill[i][j] > max){
                    max = hill[i][j];
                    pos.first = i;
                    pos.second = j;
                }
            }
        }

        mark[pos.first][pos.second] = 1;
        certamenteNaoEhUmaDFS(hill, mark, pos);

        max = -1;
        f(i, r){
            f(j, c){
                if (max < mark[i][j]) max = mark[i][j];
            }
        }
            
        
        cout << name << ": " << max << endl;

    }
}