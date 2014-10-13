#include <iostream>
#include <algorithm>
using namespace std;

int triangle(int *a)
{
    int ans = a[0]+a[1]-a[2];
    if(ans > 0) return 1;
    if(ans ==0) return 0;
    return -1;
}
int main()
{
    int a[4]={0};
    for(int i=0; i<4; i++)
        cin>>a[i];
    sort(a,a+4);
    if(triangle(a)==1 || triangle(a+1)==1 ){
        cout<<"TRIANGLE"<<endl;
    }
    else if(triangle(a) ==0 || triangle(a+1)==0){
        cout<<"SEGMENT"<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
