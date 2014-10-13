// Note: this code execute differently between my laptop and codeforce, and it cannot pass codeforce
// test
//
#include <iostream>
#include <cmath>
#include <map>
#include <cstdio>
#include <array>
#include <ctime>
using namespace std;
#define MAX 1000000
typedef array<int, 6> ARR;
ARR cord[MAX+1];
#define N 26

string ARR2string(ARR &a)
{
    string s;
    int len = a.size();
    for(int i=len-1; i>=0; i--){
        if(a[i]==0)continue;
        s +=(a[i]+'A'-1);
    }
    return s;
}
map<string, int> m;
string c[MAX+1];
void init()
{

    for(int i=0; i<=MAX; i++)
        cord[i].fill(0);
    for(int i=1; i<=N; i++)
        cord[i][0] = i;
    for(int i=27; i<=MAX; i++)
    {
        ARR last = cord[i-1];
        last[0]++;
        for(int j=0; j<5; j++){
            if(last[j] == N+1){
                last[j]=1;last[j+1]++;
            }
        }
        cord[i] = last;
    }
}
/*
 * 0: R24C44
 * 1: AB24
 */
int check_type(string& s){
    for(int i=0; i<s.length()-1 ;i++)
    {
        if(isdigit(s[i]) && s[i+1]=='C')
            return 0;
    }
    return 1;
}

int str2num(string s){
    int num = 0;
    for(int i=s.size()-1; i>=0; i--)
    {
        int p = s.size()-1-i;
        num += (int)pow(26, p) * (s[i]-'A'+1);
    }
    return num;
}
void solve_type0(string &s)
{
    int row,col;
    sscanf(s.c_str(), "R%dC%d", &row, &col);
    cout<<ARR2string(cord[col])<<row<<endl;
    return ;
}
void solve_type1(string &s)
{
    string data;
    int num=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            data += s[i];
        else
            num = num*10+(s[i]-'0');
    }
    cout<<"R"<<num<<"C"<<str2num(data)<<endl;
}
int main()
{
    init();
    int n; cin>>n;
    while(n--) {
        string input; cin>>input;
        switch(check_type(input))
        {
            case 0:
                solve_type0(input);
                break;
            case 1:
                solve_type1(input);
                break;
            default:
                break;
        }
    }
    return 0;
}
