#include <bits/stdc++.h>

using namespace std;

#define f(n) for (long long i = 0; i < n; i++)
#define ff(n) for (long long j = 0; j < n; j++)
#define f2(n) for (long long j = 1; j < n; j++)

typedef vector<long long> vi;
typedef vector< vector<long long> > vvi;

long long n;

bool consegui(long long n, long long m, vi numerators){
    cout << "aaaaaaaaaaa"
    f(numerators.size()){
        if (numerators[i] == n){
            if (numerators[numerators.size()-1-i] == m){
                cout << i << " / " << numerators.size()-1-i << "\n";
                return true;
            }
        }
    }

    return false;
}

int main(){
    long long n, m;

    cin >> n >> m;
    while (n != 1 || m != 1){
        long long maior = max(n,m);
        vi numerators(1, 1);
        
        bool achei = false;
        while (true){
            long long len = numerators.size();
            numerators.resize(len * 2);
            cout << "turu\n";
            f(len){
                numerators[i+len] = numerators[i] + numerators[len-1-i]; 
            }

            if (consegui(n, m, numerators)) break;
        }
/*
        long long found = -1;
        f(numerators.size()){
            if (numerators[i] == n){
                if (numerators[numerators.size()-i-1] == m){
                    found = i;
                }
            }
        }

        list<char> ans;
        while (found > 0){
            if (found % 2) ans.push_front('R');
            else ans.push_front('L');
            found /= 2;
        }
        if (found) ans.push_front('R');
        else ans.push_front('L');

        auto it = ans.begin();
        while (it != ans.end()){
            cout << *it;
            it++;
        }
        cout << endl;*/

        cin >> n >> m;
    }
}
