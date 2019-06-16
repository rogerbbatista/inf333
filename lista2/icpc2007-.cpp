#include <bits/stdc++.h>
//Não faço ideia do que está dando errado
using namespace std;

int main(){
    string sentence;
    getline(cin, sentence);

    while (sentence[0] != '#'){
        stack<char> tags;

        char wrong = '-';
        char out = '-';
        for (int i = 0; i < sentence.size(); i++){
            if (sentence[i] == '<'){
                if (sentence[i+1] == '/' && (sentence[i+2] >= 'A' && sentence[i+2] <= 'Z') && sentence[i+3] == '>'){
                    if (tags.empty()){
                        wrong = sentence[i+2];
                        out = '#';
                        break;
                    }
                    if (tags.top() == sentence[i+2]){
                        tags.pop();
                    }else{
                        wrong = sentence[i+2];
                        out = tags.top();
                        break;
                    }
                }else{
                    if (sentence[i+1] >= 'A' && sentence[i+1] <= 'Z' && sentence[i+2] == '>'){
                        tags.push(sentence[i+1]);
                        i += 2;
                    }
                }
            }else if (sentence[i] == '#'){
                if (!tags.empty()){
                    out = tags.top();
                    wrong = '#';
                }
            }
        }

        if (wrong == '-') cout << "Correctly tagged paragraph" << endl;
        else {
            if (out == '#') cout << "Expected " << out << " found </" << wrong << ">" << endl;
            else if (wrong == '#') cout << "Expected </" << out << "> found " << wrong << endl;
            else cout << "Expected </" << out << "> found </" << wrong << ">" << endl;
        }

        getline(cin, sentence);
    }
}