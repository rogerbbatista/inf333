#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n, m;
    cin >> n >> m;
    
    while (n){
        set<long long int> cds;

        long long int aux;
        while (n--){
            cin >> aux;
            cds.insert(aux);
        }


        long long int sell = 0;
        while (m--){
            cin >> aux;
            if (cds.find(aux) != cds.end()){
                sell++;
            }
        }

        cout << sell << endl;
        cin >> n >> m;
    }
}