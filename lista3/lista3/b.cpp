#include <bits/stdc++.h>
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1102
using namespace std;

int main(){
    int n;
    cin >> n;
    
    while (n){
        int pos = sqrt(n);
        pos += (pos*pos - n) ? 1 : 0;

        int dif = pos*pos - n;

        int x = (dif >= pos) ? pos : dif + 1;
        int y = (dif >= pos) ? 2*pos - dif - 1 : pos;

        if (pos % 2 == 0) cout << y << " " << x;
        else cout << x << " " << y;

        cout << endl;


        cin >> n;
    }
}