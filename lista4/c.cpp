#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    while (n--){
        int count;
        cin >> count;
        vector<int> snowflakes(count);
        int aux;
        for (int i = 0; i < count; i++){
            cin >> snowflakes[i];
        }
        long long int total = 0;
        long long int answer = 0;
        int j = 0;
        while (j != count){
            map<int, int> uniqueSnowflakes;
            for (int i = j; i < count; i++){
                if (uniqueSnowflakes[snowflakes[i]] == 0){
                    uniqueSnowflakes[snowflakes[i]] = i ? i : -1;
                    total++;
                }else{
                    if (total > answer) answer = total;
                    total = 0;
                    if (uniqueSnowflakes[snowflakes[i]] > 0) j = uniqueSnowflakes[snowflakes[i]]  + 1;
                    else j = 1;
                    break;
                }
                if (i == count-1){
                    if (total > answer) answer = total;
                    total = 0;
                    j = count;
                }
            }
        }
        cout << answer << endl;
    }
}