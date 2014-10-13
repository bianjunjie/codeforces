#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <iterator>
#include <climits>
using namespace std;

struct Record{
    string name;
    int score;
};
int main()
{
    int T;cin>>T;
    vector<Record> v;
    map<string, int> m;
    map<string, int>::iterator it;
    
    int max_score = INT_MIN;
    while(T--)
    {
        Record r;
        cin>>r.name>>r.score;
        v.push_back(r);
        if(m.find(r.name) == m.end()){
            m[r.name] = r.score;
        }else{
            m[r.name] += r.score;
        }

    }

    set<string> ans_name;
    for(it = m.begin(); it!=m.end(); it++){
        if( it->second > max_score){
            max_score = it->second;
            ans_name.clear();
            ans_name.insert(it->first);
        }
        else if(it->second == max_score){
            ans_name.insert(it->first);
        }
        else;
    }
    if(ans_name.size() == 1){
        cout<<*(ans_name.begin())<<endl;
    }else {
        m.clear();
        set<string>::iterator set_it;
        for(set_it = ans_name.begin(); set_it != ans_name.end(); set_it++)
            m[*set_it]=0;

        int i;
        for(i=0; i<v.size(); i++){
            if( ans_name.find(v[i].name) == ans_name.end()) continue;
            m[v[i].name] += v[i].score;
            if(m[ v[i].name ] >= max_score)
                break;
        }
        cout<<v[i].name<<endl;
    }
    return 0;
}
