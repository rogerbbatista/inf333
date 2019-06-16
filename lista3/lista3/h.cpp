#include <bits/stdc++.h>
//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=87
using namespace std;

int main(){
    string aux;
    getline(cin, aux);
    auto compare = [](string a, string b) {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a < b;
        };

    while (aux[0] != '.'){
        stringstream line(aux);
        vector<string> words;
        vector<int> nums;
        vector<bool> numword;  

        string word;
        while (line >> word){
            if (word[0] <= '9'){
                numword.push_back(true);
                nums.push_back(stoi(word.substr(0, word.size()-1)));
            }else{
                numword.push_back(false);
                words.push_back(word.substr(0, word.size()-1));
            }
        }

        sort(nums.begin(), nums.end());
        sort(words.begin(), words.end(), compare);

        int itNum = 0;
        int itWord = 0;
        int i = 0;
        while(itNum < nums.size() || itWord < words.size()){
            if (i) cout << ", ";
            if (numword[i]){
                cout << nums[itNum];
                itNum++;
            }else{
                cout << words[itWord];
                itWord++;
            }
            i++;
        }

        cout << '.' << endl;

        getline(cin, aux);
    }
}