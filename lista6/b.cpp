// Dupla:
// Róger Vieira Batista - 92538
// 

#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i = 0; i < n; i++)

vector<int> calc (string &hand){
    int first = (hand[0]-48)*10 + (hand[1]-48);
    int second = (hand[2]-48)*10 + (hand[3]-48);
    int thrash = abs(hand[4]-48 + hand[5]-48);
    return {first, second, first + second, thrash};
}

void resize (string &hand, vector<int> sum){
    f(i,hand.size()){
        if (hand[i]-48 == sum[0]/10){
            swap(hand[i], hand[hand.size()-1]);
        }
    }

    f(i,hand.size()-1){
        if (hand[i]-48 == sum[0]%10){
            swap(hand[i], hand[hand.size()-2]);
        }
    }

    f(i,hand.size()-2){
        if (hand[i]-48 == sum[1]/10){
            swap(hand[i], hand[hand.size()-3]);
        }
    }

    f(i,hand.size()-3){
        if (hand[i]-48 == sum[1]%10){
            swap(hand[i], hand[hand.size()-4]);
        }
    }

    hand.resize(hand.size()-4);
}

int main(){
    string hand;
    string draw;
    while (cin >> hand){
        cin.ignore();
        int total = 0;
        while (getline(cin, draw) && !draw.empty()){
            sort(hand.begin(), hand.end());
            vector<int> sum(4, -1);
            vector<int> aux(4);
            while (next_permutation(hand.begin(), hand.end())){
                aux = calc(hand);
                if (abs(100-sum[2]) > abs(aux[2]-100) || (abs(100-sum[2]) == abs(aux[2]-100) && sum[3] > aux[3])){
                    sum = aux;
                }
            }
            cout << ((sum[0] < 10) ? "0" : "" ) << sum[0] << "+" << ((sum[1] < 10) ? "0" : "" ) << sum[1] << "=" << ((sum[2] < 10) ? "0" : "" ) << sum[2] << endl;
            resize(hand, sum);
            f(i, draw.size()){
                hand.push_back(draw[i]);
            }
            total += abs(100-sum[2]);
        }
        sort(hand.begin(), hand.end());
        vector<int> sum(4, -1);
        vector<int> aux(4);
        while (next_permutation(hand.begin(), hand.end())){
            aux = calc(hand);
            if (abs(100-sum[2]) > abs(aux[2]-100) || (abs(100-sum[2]) == abs(aux[2]-100) && sum[3] > aux[3])){
                sum = aux;
            }
        }
        cout << ((sum[0] < 10) ? "0" : "" ) << sum[0] << "+" << ((sum[1] < 10) ? "0" : "" ) << sum[1] << "=" << ((sum[2] < 10) ? "0" : "" ) << sum[2] << endl;
        total += abs(100-sum[2]);

        cout << "score: " << total << endl;
    }
}