#include <iostream>
using namespace std;
#define N 1000
int main()
{
    char line[N+10] = {0};
    cin.getline(line, N+10);

    int occ[26]={0};
    for(int i=0; line[i]; i++)
    {
        if(line[i]>='a' && line[i]<='z')
        {
            occ[ line[i] - 'a' ]++;
        }
    }
    int total = 0;
    for(int i=0; i<26; i++)
    {
        if(occ[i]>0) total++;
    }
    cout<<total<<endl;
    return 0;
}
