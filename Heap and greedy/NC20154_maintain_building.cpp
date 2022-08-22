/*
這一題跟Tokitsukaze and Soldier 是一樣的邏輯, 修建築有deadline這個變量限制.
但是deadline這個限制越晚, 那麼你可以選擇修的建築就越多, 因為你可以取捨在當前一刻deadline的
子集, 每個deadline 都是比他晚的deadline的子集, 只要把所有子集最優, 那麼整個集合就是最優的.
所以, 我們把deadline 排序, 從小到大的排, 我們先處理最小的子集, 當時間往後走, 每當有新的元素進來,
形成新的集合, 我們就按情況取捨.
取捨的策略必然是把較小子集的修理時間最長的建築拿走, 因為修理時間越長貢獻越少.
這裡可以採用最大堆.
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
struct node{
    ll deadline, maintain;
}a[150030];

bool cmp(node a, node b){
    return a.deadline < b.deadline;
}
ll n;
priority_queue<ll> q;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].maintain >> a[i].deadline;
    }

    sort(a + 1, a + 1 + n, cmp);
    ll total = 0;
    for(int i = 1; i <= n; i++){
        total += a[i].maintain;
        q.push(a[i].maintain);
        if(total > a[i].deadline){
            total-=q.top();
            q.pop();
        }
    }
    cout << q.size() << endl;
    return 0;
}