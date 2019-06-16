#include <bits/stdc++.h>

using namespace std;

int main(){
    string line;

    while (getline(cin, line)){
        stringstream ss;

        ss << line;
        vector<long long int> cs;
        long long int aux;
        while (ss >> aux){
            cs.push_back(aux);
        }

        stringstream ss2;
        getline(cin, line);

        ss2 << line;
        vector<long long int> xs;
        while (ss2 >> aux){
            xs.push_back(aux);
        }

        bool first = true;
        for (auto &i : xs){
            vector<long long int> exps(cs.size(), 1);
            for (int j = 1; j < exps.size(); j++){
                exps[j] = exps[j-1]*i;
            }

            long long int sum = 0;
            for (int j = 0; j < exps.size(); j++){
                sum += exps[j]*cs[exps.size()-1 - j];
            }
            if (!first){
                cout << " ";
            }else{
                first = false;
            }
            cout << sum;
        }
        cout << endl;
    }
}