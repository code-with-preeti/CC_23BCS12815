#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> tokens(n);
	for(int i=0;i<tokens.size();i++){
	    cin>> tokens[i];
	}
	int power;
	cin>>power;
	int maxscore=0,score=0;
	sort(tokens.begin(),tokens.end());
	int left=0,right=tokens.size()-1;
	while(left<=right){
	    if(power>=tokens[left]){
	        power-=tokens[left];
	        left++;
	        score+=1;
	        maxscore=max(maxscore,score);
	    }
	    else if(score>0){
	        power+=tokens[right];
	        score-=1;
	        right-=1;
	    }
	    else break;
	}
	cout<< maxscore;
}
