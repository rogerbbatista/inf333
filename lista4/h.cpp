#include <bits/stdc++.h>

using namespace std;

long long int resolve(vector<long long int> &a, vector<long long int> &b){
    long long int dif = 0;
    long long int total = 0;
    int aS = a.size();
    int bS = b.size();

    int j = 0;
    int jSave = 0;
    for (int i = 0; i < a.size(); i++){
        //cout << a[i] << "/" << total << endl;
        if (j == b.size()){
            dif = 0;
            total++;
            aS--;
            j = jSave;
        }else if (a[i] == b[j]){
            j++;
            jSave = j;
            total += dif;
            bS -= dif;
            dif = 0;
        }else{
            j++; i--;
            dif++;
        }
    }
    return total + abs(aS - bS);
}


int main(){
    int n;
    cin >> n;

    while (n--){
        int firstSize, secondSize;
        cin >> firstSize >> secondSize;
        long long int dif = 0;

        long long int aux;
        vector<long long int> firstVec(firstSize);
        for (int i = 0; i < firstSize; i++){
            cin >> aux;
            firstVec[i] = aux;
        }

        vector<long long int> secondVec(secondSize);
        for (int i = 0; i < secondSize; i++){
            cin >> aux;
            secondVec[i] = aux;
        }

        sort (firstVec.begin(), firstVec.end());
        sort (secondVec.begin(), secondVec.end());

        if (secondSize < firstSize) dif = resolve(secondVec, firstVec);
        else dif = resolve(firstVec, secondVec);

        cout << dif << endl;
    }
}