#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000
int main()
{
    int n; cin>>n;
    int64_t x[N+1], y[N+1];
    for(int i=0; i<n; i++)
        cin>>x[i]>>y[i];
    int64_t dx = *max_element(x,x+n) - *min_element(x,x+n);
    int64_t dy = *max_element(y,y+n) - *min_element(y,y+n);
    cout<<max(dx,dy) * max(dx,dy)<<endl;
    return 0;
}
