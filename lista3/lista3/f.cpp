#include <bits/stdc++.h>
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=56
using namespace std;

int main(){
	string nums;
	
	while (getline(cin, nums)){
		stringstream ss(nums);
		vector<int> pile;
		
		int aux;
		while (ss >> aux){
			pile.push_back(aux);
		}
		cout << pile[0];
		for (int i = 1; i < pile.size(); i++) cout << " " << pile[i];
		cout << endl;
		
		int right = 0;
		int size = pile.size();
		while (right != size){
			pair<int, int> gt(make_pair(0, 0));
			for (int i = 0; i < pile.size(); i++){
				if (gt.first < pile[i]){
					gt.first = pile[i];
					gt.second = i;
				}
			}
			if (gt.second == pile.size()-1){
				pile.resize(pile.size()-1);	
				right++;
			}else{
				if (gt.second){
					cout << pile.size() - gt.second + right << " ";
					reverse(pile.begin(), pile.begin() + gt.second + 1);
				}
				cout << right + 1 << " ";
				reverse(pile.begin(), pile.end());
			}
		}

		cout << 0 << endl;
		
	}
} 
