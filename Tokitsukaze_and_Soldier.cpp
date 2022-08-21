#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#define js ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
int n;
struct node{
    int v, s;
}a[1000500];

bool cmp(node a, node b){
    return a.s > b.s;
}

priority_queue<ll, vector<ll>, greater<ll> > q;

int main(){
    //input data
    js;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].v >> a[i].s;
    }
    //sort by the size
    sort(a + 1, a + 1 + n, cmp);
    ll ans = 0, res = 0;
    for(int i = 1; i <= n; i++){
        q.push(a[i].v);
        ans+=a[i].v;
        while(q.size() > a[i].s){
            ans -= q.top();
            q.pop();
        }
        res = max(res, ans);
    }

    cout << res << endl;
    return 0;
}