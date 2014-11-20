#include <iostream>
#include <bitset>
using namespace std;

#define MAX 100000
bool stop(int a, int m)
{
    bitset<MAX+1> b;
    while(true)
    {
        int p = a%m;
        if(p == 0){
            return true;
        }
        if(b[p])return false;
        b[p] = 1;
        a = (a+p)%m;
    }
    return false;
}
int main()
{
    int a,m;
    cin>>a>>m;
    if(stop(a,m)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
