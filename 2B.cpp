#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i, n) for(int i=0; i<n; i++)
#define MAXN 1000

int matrix[MAXN+1][MAXN+1];
char path2[MAXN+1][MAXN+1];
char path5[MAXN+1][MAXN+1];

template <class T>
void print_(T path[][MAXN+1], int n)
{
    FOR(i, n){
        FOR(j,n){
            cout<<path[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
int numpow(int num, int val)
{
    int s = 0;
    if(num==0) return 1;
    while(num && num%val==0){
        s++; num/=val;
    }
    return s;
}

int grid[MAXN+1][MAXN+1];
void DP(int n, int val, int &num, char path[][MAXN+1])
{
    num = 0;
    memset(grid, 0, sizeof(grid));

    grid[0][0] = numpow(matrix[0][0], val);
    for(int i=1; i<n; i++){
        grid[0][i] = grid[0][i-1] + numpow(matrix[0][i], val);
        path[0][i] = 'R';
    }

    for(int i=1; i<n; i++){
        grid[i][0] = grid[i-1][0] + numpow(matrix[i][0], val);
        path[i][0] = 'D';
        for(int j=1; j<n; j++)
        {
            int minval = min(grid[i-1][j], grid[i][j-1]);
            if( minval == grid[i-1][j] ) path[i][j] = 'D';
            else                         path[i][j] = 'R';

            grid[i][j] = minval + numpow(matrix[i][j], val);
        }
    }

    num = grid[n-1][n-1];
    //print_(grid, n);
}

vector<char> parse_path(char path[][MAXN+1], int n)
{
    int i=n-1,j=n-1;
    vector<char> p;
    while(!(i==0&&j==0)){
        if(path[i][j]=='D'){
            i--; p.push_back('D');
        }else{
            j--; p.push_back('R');
        }
    }
    reverse(p.begin(), p.end());
    return p;
}
void output(int num, char path[][MAXN+1], int n)
{
    cout<<num<<endl;
    vector<char> p = parse_path(path, n);
    for(int i=0; i<p.size(); i++)
        cout<<p[i];
    cout<<endl;
}
int main()
{
    int n; cin>>n;

    int zerox, zeroy, has_zero=0;
    FOR(i, n){ 
        FOR(j, n){
            cin>>matrix[i][j];
            if(matrix[i][j] == 0){
                has_zero = 1;
                zerox = i; zeroy = j;
            }
        }
    }

    int num2=0, num5=0;
    DP(n, 2, num2, path2);
    DP(n, 5, num5, path5);

    if(has_zero && num2>1 && num5>1){
        cout<<"1"<<endl;
        for(int i=0; i<zerox; i++)
            cout<<"D";
        for(int j=0; j<n-1; j++)
            cout<<"R";
        for(int i=zerox+1; i<n; i++)
            cout<<"D";
        cout<<endl;
        return 0;
    }
    
    if(num2 < num5)
    {
        output(num2, path2, n);
    }else{
        output(num5, path5, n);
    }
    return 0;
}
