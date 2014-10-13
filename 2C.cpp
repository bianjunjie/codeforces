//
// learned from other people's algorithm -O-
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#define EPS 1e-8
#define feq(x,y) (abs(x-y)<EPS)
#define P(x) ((x)*(x))
#define Rep(i,n) for(int i=0; i<n; i++)
#define dist(x1,y1,x2,y2) sqrt(P(x1-x2)+P(y1-y2))
using namespace std;

double x[3],y[3],r[3];
double F(double dx, double dy)
{
    double t[3]={0};
    Rep(i,3){ 
        t[i] = (dist(dx,dy, x[i],y[i]))/r[i];
    }
    double cost = 0;
    Rep(i,3) cost += P(t[i]-t[(i+1)%3]);
    return cost;
}

struct Element{
    double x;
    double y;
    double val;
    Element(double _x,double _y,double _val){
        x=_x; y=_y; val=_val;
    }
    Element(){
        x=0; y=0; val = 0;
    }
    bool operator < (const Element& e2){
        return this->val < e2.val;
    }
};
int main()
{
    Rep(i,3) cin>>x[i]>>y[i]>>r[i];
    double dx=0,dy=0;
    Rep(i,3) { dx += x[i]/3; dy += y[i]/3 ;}
    double s = 1, ratio = 0.75;
    while(s > EPS)
    {
        vector<Element> v;
        v.push_back(Element(dx, dy, F(dx,dy)));
        v.push_back(Element(dx+s, dy, F(dx+s,dy)));
        v.push_back(Element(dx-s, dy, F(dx-s,dy)));
        v.push_back(Element(dx, dy+s, F(dx,dy+s)));
        v.push_back(Element(dx, dy-s, F(dx,dy-s)));

        vector<Element>::iterator it = min_element(v.begin(), v.end());
        if(it == v.begin())
        {
            s = s*ratio;
        }else{
            dx = it->x; dy = it->y;
        }
        //cout<<"dx = "<<dx<<",  dy = "<<dy<<",  F(dx,dy) = "<<F(dx,dy)<<endl;
        //cout<<"s = "<<s<<endl;
    }
    if(F(dx,dy) < 1e-5){
        cout<<fixed<<setprecision(5)<<dx<<" "<<dy<<endl;
    }
    return 0;
}
