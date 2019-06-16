#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while (n){
        int a, b;
        cin >> a >> b;
        if (n == 2) {
            cout << 2 << endl;
            cin >> n;
            continue;
        }

        bool up;
        if (a < b) up = true;
        else up = false;

        int first = a;
        int second = b;
        int pike = 0;
        for (int i = 2; i < n; i++){
            cin >> a;
            if (a < b && up){
                pike++;
                up = !up;
            }
            if (a > b && !up){
                pike++;
                up = !up;
            }
            
            b = a;
        }
        if (a > first && up){
            pike++;
            up = !up;
        }
        if (a < first && !up){
            pike++;
            up = !up;
        }
        if (first > second && up){
            pike++;
        }
        if (first < second && !up){
            pike++;
        }
        cout << pike << endl;
        cin >> n;
    }
}