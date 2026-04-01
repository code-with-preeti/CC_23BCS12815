#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n; //size of array
	vector<int> arr(n);
	for(int i=0;i<arr.size();i++){
	    cin>>arr[i];
	}
	int res=0;
	for(int i=0;i<=31;i++){
	    int count=0;
	    for(auto x : arr){
	        if(((x>>i) & 1)==1) count+=1;
	    }
	    if(count%3!=0){
	        res=res|(1<<i);
	    }
	}
	cout<<res;
}
