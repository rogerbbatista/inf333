#include <bits/stdc++.h>

using namespace std;

#define f(n) for (int i = 0; i < n; i++)
#define f2(n) for (int j = 1; j < n; j++)

vector<int> moedas(5);
/*
int troco(int n, int pos){
    if (n < 0) return 0;
    if (n == 0) return 1;

    int total = 0;
    for (int i = pos; i < 5; i++){
        total += troco(n-moedas[i], i);
    }
    
    return total;
}
*/
int main(){
    int n;
    moedas[0] = 1;
    moedas[1] = 5;
    moedas[2] = 10;
    moedas[3] = 25;
    moedas[4] = 50;

    while (cin >> n){
        
        vector<int> range(n+1, 1);
        f2(5){
            f(n){
                if (i+moedas[j] <= n) {
                    range[i+moedas[j]] += range[i];
                }
            }
        }

        cout << range[n] << endl;
    }
}
