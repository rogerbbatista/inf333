#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    while (n--){
        int size;
        cin >> size;

        vector<int> all(size);
        for (int i = 0; i < size; i++){
            cin >> all[i] ;
        }

        set<int> tree;
        tree.insert(all[0]);
        int count = 0;

        for (int i = 1; i < size; i++){
            tree.insert(all[i]);

            set<int>::iterator it = tree.upper_bound(all[i]);
            count += distance(it, tree.end());
        }

        cout << count << endl;
    }
}