/* cache swich 
To computer CPU can only switch the data with Cache directly. when the needed data 
is not in Cache, CPU needs to move the data from main storage to Cache. If, the current 
capacity of cache is full, then it must remove a data from Cache and replace it with new data.
E.g. If the capacity of the Cache is 3, Cache=>[20, , 10], CPU needs 10 and 10 is in the Cache, we say
this is Cache hit. Then, when CPU needs 21, but it is not in the Cache, we say this is Cache Miss. 
Now the Cache=> [20, 21, 10].
20 21 10 20 21 1 21 21 20 4 5 6 7 10 10 10 10 10 10 10 10  
But this algorithm is not efficient, as if you need to find 31, you have to move one of the element out from the Cache.
Now the Cache=> [20, 21, 31].
Let say, Now CPU needs to find 10, then we have one more Cache Miss. LRU Cache, is an algorithm moving out the element base on the times of usage,
the less it got visited, the higher chances got moving out. However, LRU Cache is not that efficient when facing the situation i just wrote that above.
You need to design an algorithm, that can reduce the Cache missing times.
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int n, m;
map<int, int> mp;
vector<bool> bo(100060, 0);
vector<int> nexti(100060, 0);
int arr[100060];
priority_queue<int> q;
int num = 0, ans = 0;
void work(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = n; i >= 1; i--){
		//if no similar
		if(mp[arr[i]] == 0){
			nexti[i] = 100050;
		}else{
			nexti[i] = mp[arr[i]];
		}
		//discretization 
		mp[arr[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		//item not in cache
		if(bo[i] == 0){
			ans++;
			//cache has spaces
			if(num < m){
				num++;
				//mark exist in the cache
				bo[nexti[i]] = 1;
				//priority queue takes out the max element, no need to delete yet
				q.push(nexti[i]);
			}else{
				int del = q.top();
				bo[del] = 0;
				q.pop();
				bo[nexti[i]] = 1;
				q.push(nexti[i]);
			}
		}else{
			//update the next pos
			bo[nexti[i]] = 1;
			q.push(nexti[i]);
		}
	}
	cout << ans << endl;
}
int main(){
	work();
	return 0;
}