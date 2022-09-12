/*
題目給定一個二維矩陣表, 當中某些格子裡面會有人, 然後會有炸彈投射到這個二維矩陣表中, 要不就是把
整行的人炸死, 要不就是把整列的人炸死, 題目給定炸彈掉落的地方和炸彈的炸裂方向, 求死了多少人?

解題思路, 我們利用map 套 multiset, 把每行哪一個地方有人用multiset 記錄起來
再利用另一個map 套multiset, 把每列哪一個地方有人用multiset 記錄起來
當有炸彈炸掉一整行的時候, 可以透過記錄那一行 哪一列有人的multiset, 把對應的列中的人消除掉
最後把map中的這一行的multiset 清空
而每次可以炸死多少人就是multiset的size
*/
#include<iostream>
#include<map>
#include<set>
using namespace std;
typedef map<int, multiset<int> > line;
map<int, multiset<int> > mx;
map<int, multiset<int> > my;
int n, m;
int bomb(line &x, line &y, int pos){
    //這一行/列總共有多少人
    int ans = x[pos].size();
    for(auto it = x[pos].begin(); it != x[pos].end(); it++){
        y[*it].erase(pos);
    }
    x[pos].clear();
    return ans;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        if(!n && !m)break;
        mx.clear();
        my.clear();
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            mx[x].insert(y);
            my[y].insert(x);
        }
        int ans;
        for(int i = 0; i < m; i++){
            //x == 0, 表示炸列, x == 1, 表示炸行, 而y 表示炸第幾行/列
            int x, y;
            cin >> x >> y;
            if(!x)ans = bomb(mx, my, y);
            else ans = bomb(my, mx, y);
            cout << ans << endl;
        }
        cout << endl;
    }
}