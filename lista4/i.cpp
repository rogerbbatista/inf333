#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	cin >> k;
	
	while (k--){
		int n, m;
		cin >> m >> n;

        vector<long long int> numsVec(m);
		for (int i = 0; i < m; i++) cin >> numsVec[i];

        map<long long int, int> numsSet;
        int command;
        int start = 0;
        for (int i = 0; i < n; i++) {
            cin >> command;
            for (int j = start; j < command; j++){
                numsSet[numsVec[j]]++;
            }
            start = command;
            map<long long int, int>::iterator it = numsSet.begin();
            for (int j = 0; j < i; j++){
                if ((it++)->second > 1){
                    it--;
                    j = j + it->second - 1;
                    if (j < i) it++;
                }
            }
            cout << it->first << endl;
        }
        if (k) cout << endl;
	}
}