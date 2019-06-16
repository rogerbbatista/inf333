#include <bits/stdc++.h>

using namespace std;

#define f(n) for (long long i = 0; i < n; i++)
#define ff(n) for (long long j = 0; j < n; j++)
#define f2(n) for (long long j = 1; j < n; j++)

typedef vector<long long> vi;
typedef vector< vector<long long> > vvi;

long long n;

long long solve (vvi &grid, long long i, long long j, vvi &solved){
    if (i >= n || j >= n) return 0;
    if (solved[i][j] != -1) return solved[i][j];
    if (i == n-1 && j == n-1) return 1;
    if (grid[i][j] == 0) return 0;

    long long total = 0;
    total += solve(grid, i+grid[i][j], j, solved);
    total += solve(grid, i, j+grid[i][j], solved);

    solved[i][j] = total;
    return total;
}


int main(){

    cin >> n;
    while (n > 0){
        vvi grid(n, vi(n));

        string aux;
        f(n){
            cin >> aux;
            ff(n){
                grid[i][j] = aux[j]-48;
            }
        }
        vvi solved(n, vi(n, -1));
        long long total = solve(grid, 0, 0, solved);
        cout << total << endl;

        cin >> n;
    }
}