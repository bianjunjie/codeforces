#include <iostream>
using namespace std;

bool found = false;
int m,n;
int chess[100][100]={0};


bool inside(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void output()
{
    char p[5]=".-WB";
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++)
            cout<<p[chess[i][j]];
        cout<<endl;
    }
}
//0 => .
//1 => _
//2 => W
//3 => B
void put(int x, int y)
{
    if(found) return ;
    if(y==m){
        y=0;x+=1;
    }

    if(x==n){
        found = true;
        output();
        return ;
    }

    if(chess[x][y] == 1)
        put(x, y+1);
    else
    {
        int p[4]={0};
        if(inside(x-1,y))
            p[chess[x-1][y]]++;
        if(inside(x,y-1))
            p[chess[x][y-1]]++;
        for(int i=2; i<=3; i++)
            if(p[i]==0) {
                chess[x][y]=i;
                put(x,y+1);
                chess[x][y]=0;
            }
    }
}

int main()
{
    cin>>n>>m;
    char board[101]={0};
    for(int i=0; i<n; i++){
        cin>>board;
        for(int j=0; j<m;j++)
            if(board[j]=='-')
                chess[i][j] = 1;
    }
    put(0,0);
    return 0;
}
