#include <bits/stdc++.h>
//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=1427
using namespace std;

int main(){
    double take, have;
    string um, name;
    vector<string> needMore;

    cin >> take >> um >> have;
    cin.ignore();
    getline(cin, name);

    while (take >= 0){
        double percentage = (take) ? take*100/have : 0;

        if (percentage >= 1){
            cout << name << " " << setprecision(1) << fixed << take << " " << um << " " << setprecision(0) << percentage << "%"<< endl;
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
