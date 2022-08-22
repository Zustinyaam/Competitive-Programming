/*
可以知道當充電器的充電功率越高, 能保持全部電量大於或等於0的電腦數量越多.
典型 二分答案, 111100000 類型. 
因為要保持連續k分鐘所有電腦電量為正數, 每次都要將最小電量電腦充電, 可以利用MIN HEAP, 每過
一分鐘就幫一部最小電量電腦充1分鐘電.
*/
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
using namespace std;
typedef long long ll;
const ll inf=2e12;
int n, k;
ll left,right,mid,ans;
ll elec[300000], cost[300000];
struct node{
	ll hdt, elec;
    ll cost;
	node(ll HDT,ll COST, ll ELEC):hdt(HDT),cost(COST),elec(ELEC){}
	bool operator <(const node &o)const{
		if(hdt!=o.hdt)return hdt>o.hdt;
		if(cost!=o.cost)return cost<o.cost;
		return elec>o.elec;
	}
}t(0, 0, 0);

priority_queue<node> q;
bool check(ll charge){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)if(elec[i]/cost[i]<k)q.push(node(elec[i]/cost[i], cost[i], elec[i]));
	if(q.empty())return true;
	for(ll i=0;i<k;i++){
		t=q.top();q.pop();
		if(t.hdt<i)return false;
		if((t.elec+charge)/t.cost<k)q.push(node((t.elec+charge)/t.cost, t.cost, t.elec+charge));
		if(q.empty())return true;
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%I64d",&elec[i]);
	for(int i=1;i<=n;i++)scanf("%I64d",&cost[i]);
	left=0,right=inf;ans=-1;
    while(left <= right){
        mid = (left + right)/2;
        if(check(mid)){
            ans = mid, right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
	printf("%I64d\n",ans);
    return 0;
}