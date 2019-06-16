#include <bits/stdc++.h>
//https://www.hackerrank.com/challenges/sam-and-substrings/problem
using namespace std;

int main(){
    string n;
    cin >> n;
    int total = 0;
    int uns = 1;
    for (int i = n.size()-1; i >= 0; i--){
        total += ((i+1) * int(number[i]) * uns) %(1000000007)
        uns = (uns*10+1)%(1000000007)
    }

    cout << total%(1000000007) << endl;
}