/*
 * Algorithm:
 * For odd n, F(n) = -n + n/2
 * For even n, F(n) = n/2;
 */
#include <iostream>
using namespace std;
int main()
{
    int64_t n; cin>>n;
    
    if(n%2)
    {
        cout<<n/2 - n<<endl;
    }else
    {
        cout<<n/2<<endl;
    }
    return 0;
}
