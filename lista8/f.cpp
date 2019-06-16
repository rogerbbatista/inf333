#include <bits/stdc++.h>
//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=1380
using namespace std;

int resolve(deque<int> left, deque<int> right, int p, int l, int r, vector< vector<int> > &solved){
    if (solved[l][r]){
        return solved[l][r];
    }
    if (left.size() == 0){
        if(right.size() == 1){
            return 0;
        }
        for (int i = 0; i < right.size()/2; i++){
            left.push_back(right.back());
            right.pop_back();
        }
    } else if(right.size() == 0){
        if(left.size() == 1){
            return 0;
        }
        for (int i = 0; i < left.size()/2; i++){
            right.push_back(left.back());
            left.pop_back();
        }
    }
    if (p){
        if (left.front() >= right.front()){
            left.pop_front();
            solved[l+1][r] = resolve(left, right, 0, l+1, r, solved);
            return solved[l+1][r];
        }else{
            right.pop_front();
            solved[l][r+1] = resolve(left, right, 0, l, r+1, solved);
            return solved[l][r+1];
        }
    }else{
        int a = left.front();
        left.pop_front();
        int s1 = a + resolve(left, right, 1, l+1, r, solved);
        left.push_front(a);
        
        a = right.front();
        right.pop_front();
        int s2 = a + resolve(left, right, 1, l, r+1, solved);
        if (s1 >= s2){
            solved[l][r] = s1;
            return s1;
        }else{
            solved[l][r] = s2;
            return s2;
        }
    }
}

int main(){
    int n;
    int count = 1;

    cin >> n;
    while (n){
        vector< vector<int> > solved(n, vector<int>(n));
        cout << "In game " << count++ << ", the greedy strategy might lose by as many as ";

        deque<int> left;
        deque<int> right;
        int aux;
        int total = 0;
        for (int i = 0; i < n/2; i++){
            cin >> aux;
            total += aux;
            left.push_back(aux);
        }
        for (int i = n/2; i < n; i++){
            cin >> aux;
            total += aux;
            right.push_front(aux);
        }

        int l = 0;
        int r = 0;

        int max = resolve(left, right, 0, l, r, solved);

        cout << 2*max-total;
        cout << " points.\n";
        
        cin >> n;
    }
}