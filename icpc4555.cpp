#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int id;
        cin >> id;
        int count;
        cin >> count;
        if (!count){
            cout << id << " " << 1 << endl;
            cout << 0 << endl;
            continue;
        }
        priority_queue<int> left;
        priority_queue<int> right;
        
        int aux;
        int saida = count/2 + 1;
        int saidaAux = 0;
        bool first = true;
        bool lastBreak = false;
        cout << id << " " << saida << endl;
        for (int k = 0; k < count; k++){
            cin >> aux;
            if (left.empty()) left.push(aux);
            else if (aux > left.top()){
                if (right.size() == left.size() +1){
                    left.push(-right.top());
                    right.pop();
                    right.push(-aux);
                }else{
                    right.push(-aux);
                }
            }else{
                if (right.size() == left.size() -1){
                    right.push(-left.top());
                    left.pop();
                    left.push(aux);
                }else{
                    left.push(aux);
                }
            }

            if (k%2 == 0){             
                if (saidaAux && saidaAux % 10 == 0){
                    if (saidaAux == saida - 11){
                        lastBreak = true;
                    }
                    cout << endl;
                    first = true;
                }
                if (!first){
                    if (right.size() > left.size()) cout << " " << -right.top();
                    else cout << " " << left.top();
                }else{
                    if (right.size() > left.size()) cout << -right.top();
                    else cout << left.top();
                    first = false;
                }

                if (lastBreak && saidaAux == saida - 2)
                    if (right.size() > left.size()) cout << endl << -right.top();
                    else cout << endl << left.top();

                saidaAux++;
            }
        }

        cout << endl;
    }
}
