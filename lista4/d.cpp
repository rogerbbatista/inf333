#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    while (n--){
        char aux;
        cin >> aux;

        string auxKey;
        string auxValue;
        map<string, string> dict;

        bool key = true;
        cin >> aux;
        while (aux != '}'){
            if (aux == ':'){
                key = !key;
                cin >> aux;
            }
            if (aux == ','){
                key = !key;
                cin >> aux;
                dict[auxKey] = auxValue;
                auxKey.resize(0);
                auxValue.resize(0);
            }
            if (key){
                auxKey.push_back(aux);
            } else {
                auxValue.push_back(aux);
            }
            cin >> aux;
        }
        dict[auxKey] = auxValue;


        cin >> aux;
        auxKey.resize(0);
        auxValue.resize(0);
        set<string> changed;
        set<string> plus;

        key = true;
        cin >> aux;
        while (aux != '}'){
            if (aux == ':'){
                key = !key;
                cin >> aux;
            }
            if (aux == ','){
                key = !key;
                cin >> aux;
                if (dict.find(auxKey) == dict.end()){
                    plus.insert(auxKey);
                } else {
                    if (dict[auxKey] != auxValue){
                        changed.insert(auxKey);
                    }
                    dict[auxKey] = "-1";
                }
                auxKey.resize(0);
                auxValue.resize(0);
            }
            if (key){
                auxKey.push_back(aux);
            } else {
                auxValue.push_back(aux);
            }
            cin >> aux;
        }
        if (dict.find(auxKey) == dict.end()){
            plus.insert(auxKey);
        } else {
            if (dict[auxKey] != auxValue){
                changed.insert(auxKey);
            }
            dict[auxKey] = "-1";
        }

        bool change = false;

        auxKey.resize(0);
        auxKey.push_back('+');
        for (auto &x: plus){
            if (x != ""){
                change = true;
                auxKey += x + ',';
            }
        }
        if (auxKey != "+") cout << auxKey.substr(0, auxKey.length() - 1) << endl;

        auxKey.resize(0);
        auxKey.push_back('-');
        for (auto &x: dict){
            if (x.second != "-1"){
                if (x.second != ""){
                    auxKey += x.first + ',';
                    change = true;
                }
            }
        }
        if (auxKey != "-") cout << auxKey.substr(0, auxKey.length() - 1) << endl;

        auxKey.resize(0);
        auxKey.push_back('*');
        for (auto &x: changed){
            if (x != ""){
                change = true;
                auxKey += x + ',';
            }
        }
        if (auxKey != "*") cout << auxKey.substr(0, auxKey.length() - 1) << endl;

        if (!change) cout << "No changes" << endl;
        cout << endl;
    }
}