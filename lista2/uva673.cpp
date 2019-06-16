#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string aux;
    getline(cin, aux);

    while (n--){
        string sequence, aux;
        getline(cin, sequence);

        if (!sequence.size()){
            cout << "Yes" << endl;
            continue;
        }
        bool wrong = false;

        stack<char> seq;
        for (int i = 0; i < sequence.size(); i++){
            if (sequence[i] == '(' || sequence[i] == '['){
                seq.push(sequence[i]);
                continue;
            }
            if (sequence[i] == ')'){
                if (seq.empty() || seq.top() != '('){
                    cout << "No" << endl;
                    wrong = true;
                    break;
                }
                seq.pop();
            }
            if (sequence[i] == ']'){
                if (seq.empty() || seq.top() != '['){
                    cout << "No" << endl;
                    wrong = true;
                    break;
                }
                seq.pop();
            }
        }

        if(!wrong)
            if (seq.size()) cout << "No" << endl;
            else cout << "Yes" << endl;
    }
}