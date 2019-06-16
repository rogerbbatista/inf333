#include <bits/stdc++.h>

using namespace std;

int main(){
    double take, have;
    string um, name;
    vector<string> needMore;

    cin >> take >> um >> have;
    cin.ignore();
    getline(cin, name);

    while (take >= 0){
        int percentage = (take) ? take/have*100 : 0;
        if (percentage){
            cout << name << " " << setprecision(1) << fixed << take << " " << um << " " << percentage << "%"<< endl;
        }else{
            needMore.push_back(name);
        }
        cin >> take >> um >> have;
        cin.ignore();
        getline(cin, name);
    }
    
    cout << "Provides no significant amount of:" << endl;
    for (int i = 0; i < needMore.size(); i++){
        cout << needMore[i] << endl;
    }
}