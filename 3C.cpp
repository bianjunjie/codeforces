#include <iostream>
using namespace std;

#define N 3
char board[4][4]={0};

bool is_all(char s[], char ch){
    for(int i=0; i<N; i++)
        if(s[i]!=ch)return false;
    return true;
}
bool winx=false, win0=false;
void parse(int& numx, int& num0)
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            switch (board[i][j])
            {
                case 'X':
                    numx++;
                    break;
                case '0':
                    num0++;
                    break;
                default:
                    break;
            }
        }

    char str[4]={0};
    for(int i=0; i<N; i++){
        if(!winx && is_all(board[i], 'X'))winx=true;
        if(!win0 && is_all(board[i], '0'))win0=true;

        str[0]=board[0][i]; str[1]=board[1][i]; str[2]=board[2][i];

        if(!winx && is_all(str, 'X'))winx=true;
        if(!win0 && is_all(str, '0'))win0=true;
    }
    str[0]=board[0][0]; str[1]=board[1][1]; str[2]=board[2][2];
    if(!winx && is_all(str, 'X'))winx=true;
    if(!win0 && is_all(str, '0'))win0=true;

    str[0]=board[0][2]; str[1]=board[1][1]; str[2]=board[2][0];
    if(!winx && is_all(str, 'X'))winx=true;
    if(!win0 && is_all(str, '0'))win0=true;
}

int main()
{
    int i;
    for(i=0; i<N; i++) cin>>board[i];

    int numx=0, num0=0;
    parse(numx, num0);
    string msg;
    if(numx-num0 != 0 && numx-num0 != 1){
        cout<<"illegal"<<endl;
        return 0;
    }
    if(winx && win0){
        cout<<"illegal"<<endl;
        return 0;
    }
    if(win0 && numx-num0==1){
        cout<<"illegal"<<endl;
        return 0;
    }
    if(winx && numx-num0==0){
        cout<<"illegal"<<endl;
        return 0;
    }
    if(!winx && !win0){
        if(numx + num0 == 9){
            cout<<"draw"<<endl;
            return 0;
        }
        if(numx == num0){
            cout<<"first"<<endl;
            return 0;
        }
        else{
            cout<<"second"<<endl;
            return 0;
        }
    }
    if(winx){
        cout<<"the first player won"<<endl;
        return 0;
    }
    if(win0){
        cout<<"the second player won"<<endl;
        return 0;
    }
    return 0;

}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
