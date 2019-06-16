#include <bits/stdc++.h>

using namespace std;

#define f(n) for (long long i = 0; i < n; i++)
#define ff(n) for (long long j = 0; j < n; j++)
#define f2(n) for (long long j = 1; j < n; j++)

typedef vector<long long> vi;
typedef vector< vector<long long> > vvi;

int verify(vector<bool> &bits, int i, int n){
    return -1;
}

void solve (vector<bool> &bits, int i, int n){
    int area = verify(bits, i, n);
    if (area == -1){
        int q = (n-i)/4;
        cout << 'D';
        solve(bits, 0, q);
        solve(bits, q, 2*q);
        solve(bits, 2*q, 3*q);
        solve(bits, 3*q, 4*q);

    }else{
        cout << area;
    }
}

int main(){
    char type;

    cin >> type;
    while (type != '#'){
        int r, c;
        cin >> r >> c;
        if (type == 'D'){
            vector<bool> bits(r*c);
            int size = r*c;
            //while (size )
        }

        cin >> type;
    }
}