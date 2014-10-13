#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

//#include "prettyprint.hpp"
using namespace std;

#define MAX 100000
#define N 26


int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        char cards[MAX+2]={0};
        cin>>cards;
        vector<int64_t> letter(N,0);
        for(int i=0; cards[i]; i++)
        {
            letter[cards[i]-'A']++;
        }
        sort(letter.begin(), letter.end(), greater<int>());

 //       cout<<letter<<endl;

        int i=0;
        int64_t sum=0;
        while(k>0)
        {
            if(letter[i] >= k){
                sum += (int64_t)k * (int64_t)k; break;
            }else{
                sum += letter[i] * letter[i];
                k-=letter[i];
                i++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
