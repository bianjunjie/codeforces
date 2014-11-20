#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    int d, sumTime;
    cin>>d>>sumTime;

    vector<int> minTime(d);
    vector<int> maxTime(d);
    
    for(int i=0; i<d; i++)
        cin>>minTime[i]>>maxTime[i];

    int minSum = accumulate(minTime.begin(), minTime.end(), 0);
    int maxSum = accumulate(maxTime.begin(), maxTime.end(), 0);

    if(sumTime >= minSum && sumTime <=maxSum)
    {
        vector<int> result = minTime;
        int extra = sumTime - minSum;
        for(int i=0; i<d; i++)
        {
            int budget = maxTime[i] - minTime[i];
            if(budget >= extra){
                result[i] += extra;
                extra = 0;
                break;
            }else{
                result[i] = maxTime[i];
                extra -= budget;
            }
        }
        cout<<"YES"<<endl;
        for(int i=0; i<d; i++)
            cout<<result[i]<<" ";
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
