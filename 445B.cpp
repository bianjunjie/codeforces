#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int connect[60][60]={0};

int linked[60]={0};

int64_t solve(int n, int m)
{
    if(m == 0) return 1;
    
    int64_t sum = 1;

    while(true){
        int max_ele_pos = distance(linked, max_element(linked+1, linked+n+1));
        sum *= (1<< (linked[max_ele_pos]));
        linked[max_ele_pos] = 0;

        for(int i=1; i<=n; i++)
        {
            if(connect[max_ele_pos][i] == 1){
                linked[i]--;
                connect[max_ele_pos][i] = 0;
                connect[i][max_ele_pos] = 0;
            }
        }

        int acc = accumulate(linked+1, linked+n, 0);
        if(acc == 0) break;
    }
    return sum;
}
int main()
{
    int n,m; cin>>n>>m;
    int i,j;
    for(i=0; i<m; i++)
    {
        int _x,_y; cin>>_x>>_y;
        connect[_x][_y] = 1;
        connect[_y][_x] = 1;
        linked[_x]++;
        linked[_y]++;
    }

    int danger = solve(n, m);
    cout<<danger<<endl;
    return 0;

}
