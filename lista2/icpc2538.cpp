#include <bits/stdc++.h>

using namespace std;

int main(){
    int beds;
    cin >> beds;
    while (beds){
        string customers;
        cin >> customers;
        vector<bool> cost(26, false);

        int away = 0;
        for (int i = 0; i < customers.size(); i++){
            if (cost[customers[i]]){
                cost[customers[i]] = false;
                beds++;
            }else{
                if (beds){
                    cost[customers[i]] = true;
                    beds--;
                }else{
                    away++;
                    i++;
                }
            }
        }

        if (!away) cout << "All customers tanned successfully." << endl;
        else cout << away << " customer(s) walked away." << endl;

        cin >> beds;
    }
}