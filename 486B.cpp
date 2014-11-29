#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
#define Rep(i, n) for(int i=0; i<n; i++)
int main()
{
    int m,n; cin>>m>>n;
    int A[MAX+1][MAX+1], B[MAX+1][MAX+1];

    vector<int> zm,zn;
    Rep(i, m)Rep(j, n){
        cin>>B[i][j];
        if(B[i][j] == 0){
            zm.push_back(i);
            zn.push_back(j);
        }
        A[i][j] = 1;
    }
    for(int i=0; i<zm.size(); i++)
    {
        int row = zm[i];
        for(int j=0; j<n; j++)
            A[row][j] = 0;
    }
    for(int i=0; i<zn.size(); i++)
    {
        int col = zn[i];
        for(int j=0; j<m; j++)
            A[j][col] = 0;
    }

    vector<int> rowA(m,0), colA(n,0);
    Rep(i,m)Rep(j,n){
        if(A[i][j]==1){
            rowA[i] = 1;
            colA[j] = 1;
        }
    }
    
    
    bool flag = true;
    Rep(i,m)Rep(j,n){
        if (B[i][j] == 1)
        {
            if (rowA[i] == 0 && colA[j] == 0) {
                flag = false;
                goto end;
            }
        }
    }
end:;
    if (!flag) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
