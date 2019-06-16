#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >> n){
        if (n == 1){
            cin >> n;
            cout << "Jolly" << endl;
            continue;
        }
        int a, b;
        bool zero = false;
        cin >> a >> b;
        int jump = 0;
        int aux = abs(b - a);
        if (!aux) zero = true;
        jump = aux;
        for (int i = 2; i < n; i++){
            cin >> a;            
            aux = abs(a - b);
            if (!aux) zero = true;
            jump += aux;
            b = a;
        }
        if (jump == (n*(n-1)/2) && !zero) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
}