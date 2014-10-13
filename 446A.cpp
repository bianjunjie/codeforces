#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval(int s,int e):start(s),end(e){}
    Interval():start(0),end(0){}
    int len(){
        return end-start+1;
    }
};

int n;
vector<int> seq(n);
int solve_seq(vector<Interval>& inters, int k)
{
    int len = inters.size();
    //with before
    int s1=0,s2=0;
    if(k!=0)
    {
        s1 = inters[k-1].len()+1;
        int back_up = seq[inters[k].start];
        seq[inters[k].start] = seq[inters[k-1].end]+1;
        for(int i=inters[k].start+1; i<seq.size();i++)
            if(seq[i]>seq[i-1])s1++;
        seq[inters[k].start] = back_up;
    }
    if(k!=inters.size()-1)
    {
        s2 = inters[k+1].len()+1;
        int back_up = seq[inters[k].end];
        seq[inters[k].end] = seq[inters[k+1].start]-1;
        for(int i=inters[k].end-1; i>=0; i--)
            if(seq[i+1]>seq[i])s2++;
        seq[inters[k].end]=back_up;
    }
    return max(s1,s2);
}
int main()
{
    int n;cin>>n;
    seq.resize(n);
    vector<Interval> inters;
    for(int i=0; i<n; i++) {
        cin>>seq[i];
        if(i==0){
            Interval in(0,0); inters.push_back(in);
        }else{
            Interval& last = inters[inters.size() -1];
            if(seq[i] > seq[last.end]) last.end = i;
            else inters.push_back(Interval(i,i));
        }
    }
    for(int i=0; i<inters.size(); i++){
        cout<<inters[i].start<<","<<inters[i].end<<endl;
    }


    int maxlen = -1;
    for(int i=0; i<inters.size(); i++){
        int len = solve_seq(inters, i);
        cout<<"len = "<<len<<",  i="<<i<<endl;
        if(len > maxlen) maxlen = len;
    }
    cout<<maxlen<<endl;
}
