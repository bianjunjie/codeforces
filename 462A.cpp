#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool single(vector<string>& b, int i, int j)
{
    int n = b.size();
#define INSIDE(N,a,b) (a>=0 && a<N && b>=0 && b<N)
    
    int num =0;
    for(int p=-1; p<=1; p++)
        for(int q=-1; q<=1; q++)
        {
            if(p==0&&q==0) continue;
            if(p==q || p+q==0)continue;
            if(!INSIDE(n,i+p,j+q))continue;
            if(b[i+p][j+q]=='o') num++;
        }
    if(num%2)return false;
    return true;
}
bool check_even(vector<string>& board)
{
    int n = board.size();
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            bool even = single(board, i,j);
            if(!even)
                return false;
        }

    return true;
}
int main()
{
    int n; cin>>n;
    vector<string> board;
    for(int i=0; i<n; i++)
    {
        string s; cin>>s;
        board.push_back(s);
    }
    if(check_even(board)) 
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;

    return 0;
}
