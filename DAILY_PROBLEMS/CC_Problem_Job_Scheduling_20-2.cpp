#include <bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

void jobschedule(vector<Job>& v1){
    int cnt_job=0;
    int totalprofit=0;
    int n=v1.size();
    // find max deadline
    int maxDeadline = 0;
    for(int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, v1[i].deadline);
    }
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<v1.size();i++){
        pq.push({v1[i].profit,v1[i].deadline});
    }
    
    vector<int> hash(maxDeadline,0);
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        for(int i=it.second-1;i>=0;i--){
            if(hash[i]==0) {
                cnt_job++;
                totalprofit+=it.first;
                hash[i]=1;
                break;
            }
        }
    }
    cout<<"total jobs scheduled:" << cnt_job<<endl;
    cout<<"total profit:" << totalprofit;
}
int main() {
	// your code goes here
	int N;
	cin>>N;
	vector<Job> v1(N);
	for(int i=0;i<N;i++){
	    cin>>v1[i].id>>v1[i].deadline>>v1[i].profit;
	}
	jobschedule(v1);
	return 0;
}
