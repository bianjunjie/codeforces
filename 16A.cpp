#include <iostream>
#include <string>
using namespace std;

bool check_same(string &s)
{
    char ch=s[0];
    for(int i=1; i<s.size(); i++)
        if(s[i]!=ch)return false;
    return true;
}
int main()
{
    int n,m; cin>>n>>m;
    int last=-1;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        if(!check_same(s)){
            cout<<"NO"<<endl;
            return 0;
        }
        if(last!=-1 && (s[0]-'0')==last){
            cout<<"NO"<<endl;
            return 0;
        }
        last = s[0]-'0';
    }
    cout<<"YES"<<endl;
    return 0;
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

