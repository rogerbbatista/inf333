#include <bits/stdc++.h>

using namespace std;

int main(){
    int days;
    cin >> days;

    while (days){
        long long int total = 0;
        map<long long int, long long int> billsMap;

        while (days--){
            long long int bills;
            cin >> bills;

            long long int aux;
            while(bills--){
                cin >> aux;
                billsMap[aux]++;
            }

            total += billsMap.rbegin()->first;
            total -= billsMap.begin()->first; 
            billsMap.begin()->second--;
            billsMap.rbegin()->second--;

            if (billsMap.rbegin()->second == 0){
                billsMap.erase(billsMap.rbegin()->first);
            }
            if (billsMap.begin()->second == 0){
                billsMap.erase(billsMap.begin()->first);
            }
        }

        cout << total << endl;

        cin >> days;
    }
}