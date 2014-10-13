#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void split_to_vec(int &n, vector<int>& v)
{
    while(n){
        v.push_back(n%10);n/=10;
    }
    sort(v.begin(), v.end());
    return ;
}

int get_from_vec(vector<int>& v)
{
    int len = v.size();
    if(v[0]==0)
    {
        int i;
        for(i=0; i<len; i++)
            if(v[i]!=0) break;
        swap(v[0],v[i]);
    }
    int s=0;
    for(int i=0; i<len; i++)
        s = s*10 + v[i];
    return s;
}
int main()
{
    int n=0, m=0;
    string str_n, str_m;
    cin>>n>>str_m;
    if(str_m.size()>1 && str_m[0]=='0'){
        cout<<"WRONG_ANSWER"<<endl;
        return 0;
    }

    for(int i=0; i<str_m.size(); i++)
        m = m*10 + (str_m[i]-'0');
    

    if(n==0 && m!= 0) {
        cout<<"WRONG_ANSWER"<<endl;
        return 0;
    }
    if(n==0 && m==0){
        cout<<"OK"<<endl;
        return 0;
    }
    vector<int> v;
    split_to_vec(n, v);
    int s=get_from_vec(v);
    if(s==m) cout<<"OK"<<endl;
    else cout<<"WRONG_ANSWER"<<endl;
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
