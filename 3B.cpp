#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

#define Rep(i,n) for(int i=0; i<n; i++)
#define MAXN 100000

struct Vehicles{
    int index;
    int type;
    int volume;
    friend bool operator > (const Vehicles& v1,const Vehicles& v2){
        return (v1.volume*2 /v1.type) > (v2.volume*2/v2.type);
    }
};
int main()
{
    int n, space; cin>>n>>space;

    vector<Vehicles> v(MAXN+1);
    Rep(i,n) {
        cin>>v[i].type>>v[i].volume;
        v[i].index = i+1;
    }
    sort(v.begin(), v.begin()+n, greater<Vehicles>());

    /*
    for(int i=0; i<n; i++)
    {
        cout<<"index = "<<v[i].index
            <<", type  = "<<v[i].type
            <<", volume= "<<v[i].volume<<endl;
    }
    */

    int i = 0, price = 0;
    vector<int> ans;
    bitset<MAXN+1> used;
    for(int i=0; i<n ;i++) used[i]=0;
    
    while(i<n){
        if(space >= v[i].type){
            space -= v[i].type;
            price += v[i].volume;
            ans.push_back(v[i].index);
            used[i] = 1;
        }
        i++;
    }
    if(space > 0 && ans.size()!=n)
    {
        for(i=n-1; i>=0; i--)
        {
            if(used[i] && v[i].type==1)break;
        }
        int j;
        for(j=0; j<n; j++){
            if(used[j]==0 && v[j].type==2)break;
        }
       // cout<<v[i].index<<"==="<<v[j].index<<endl;
        if(i!=-1 && j!=n && v[i].volume < v[j].volume){
            ans.push_back(v[j].index);
            for(int k=0; k<ans.size(); k++)
                if(ans[k] == v[i].index){
                    ans.erase(ans.begin()+k);
                    break;
                }
            price += (v[j].volume - v[i].volume);
        }
    }

    cout<<price<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
        if(i!=ans.size()-1) cout<<" ";
    }
    cout<<endl;
    return 0;
}
