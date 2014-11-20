#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#define PRINT(v) do{\
    cout<<"[";\
    for(int i=0; i<v.size(); i++)\
        cout<<v[i]<<",";\
    cout<<"]"<<endl;\
}while(0)
#define MAX 5000

struct Rect{
    int h;
    int w;
    int index;
    friend bool operator > (const Rect &r1, const Rect r2)
    {
        return r1.h > r2.h && r1.w > r2.w;
    }
    friend bool operator < (const Rect &r1, const Rect r2)
    {
        return r1.h < r2.h && r1.w < r2.w;
    }
};
/*
int LIS(vector<int>& v)
{
    int n = v.size();
    if(n==0) return 0;
    vector<int> s;
    s.push_back(v[0]);

    vector<int>::iterator it;
    for(int i=1; i<v.size(); i++)
    {
        if(v[i] > s[s.size() -1]) 
            s.push_back(v[i]);
        else{
            it = lower_bound(s.begin(), s.end(), v[i]);
            if(it == s.end())continue;
            *it = v[i];
        }
    }

    PRINT(s);
    return s.size();
}
*/
bool less_h(const Rect& r1, const Rect& r2)
{
    if(r1.h < r2.h) return true;
    if(r1.h > r2.h) return false;
    return r1.w < r2.w;
}

int get_position(Rect card[], int tail[], int len, Rect& r)
{
    auto it = lower_bound(card, card+
}

int LIS(Rect card[], int size)
{
    int tail[MAX+1]={0}, prev[MAX+1]={-1};
    vector<Rect> v; v.push_back(card[0]);
    
    int len = 1;
    for(int i=1; i<size; i++)
    {
        if(card[i] > card[tail[len-1]])
        {
            tail[len] = i;
            prev[i] = tail[len-1];
            v.push_back( card[i] );
            len++;
        }
        else if(card[i] < card[tail[0]])
        {
            tail[0] = i;
            v[0] = card[i];
        }
        else
        {
            int pos = get_position(v, card[i]);
            auto it = lower_bound(v.begin(), v.end(), card[i]);
            if(it == v.end())

            prev[i] = tail[pos-1];
            tail[pos] = i;
        }
    }
}

int dp(int v)
{
    if(d[v]) return d[v];
    d[v] = 1;
    for(int i=0; i<n; i++)
        if(w[i] > w[v] && h[i] > h[v])
            if(dp(i) + 1 > d(v)) 
                to[v]=i,d[v]=d[i]+1;
    return d[v];
}
int main()
{
    int n,w,h;
    cin>>n>>w>>h;
    Rect card[Max+1];
    int size = 0;
    for(int i=0; i<n; i++)
    {
        int _w,_h; cin>>_w>>_h;
        if(_w < w || _h < h) continue;

        card[size].h = _h;
        card[size].w = _w;
        card[size].index = i+1;
        size++;
    }
    sort(card, card+size, less_h);

    // now we have size cards, sorted by height
    // we need to get LIS 

    LIS(card, size);
    return 0;

}
