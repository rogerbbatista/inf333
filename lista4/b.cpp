#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();

    while (n--){
        map<string, long long int> trees;
        string name;
        long long int total = 0;
        getline(cin, name);
        while(name != ""){
            trees[name]++;
            total++;
            getline(cin, name);
        }
        
        for (auto &x: trees){
            double percentage = (x.second * 100.0) / total;
            cout << x.first << setprecision(4) << fixed << " " << percentage << endl;
        }

        if (n >= 1) cout << endl;
    }
}