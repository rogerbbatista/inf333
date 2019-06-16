#include <bits/stdc++.h>

using namespace std;

int timeDif(int a, int b){
    return min(abs(a - b), 24 - abs(a - b));
}

int main(){
    int n;
    while(cin >> n){
        vector<int> people(n);
        for(int i = 0; i < n; i++){
            cin >> people[i];
        }
        sort(people.begin(),people.end());

        int result, total1 = 0, total2;
        if(n == 2){
            result = timeDif(people[0], people[1]);
        }else{            
            for(int i = 0; i < n; i += 2){
                total1 += abs(people[i] - people[i+1]);
            }
            total2 = 24 - abs(people[0] - people[n-1]);
            for(int i = 1; i < n - 1; i += 2){
                total2 += abs(people[i] - people[i+1]);
            }
            result = min(total1, total2);
        }

        cout << result << endl;
    }

}