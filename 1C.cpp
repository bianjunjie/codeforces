// Note, this code can only pass case 1~ case 27
// A fix might be like follows 
//     for(n = 3; n < MAX_ANGLES; n++)
//     {
//         double cur_angle = 360.0/n;
//         check whether feq(fmod(angle_i, cur_angle), 0)
//      }
//  this can avoid GCD for double numbers
// 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.1415926535898
#define EPS 1e-4
struct Point{
    double x;
    double y;
};

double dist(Point& p1, Point& p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double Heron(double d1, double d2, double d3)
{
    double s = (d1+d2+d3)/2;
    return sqrt(s*(s-d1)*(s-d2)*(s-d3));
}

bool feq(double d1, double d2)
{
    return abs(d1-d2) < EPS;
}

double fmod(double d1, double d2){
    int n = (int)( d1/d2 );
    return d1 - d2*n;
}
double fgcd(double d1, double d2)
{
    //cout<<"d1= "<<d1<<", d2="<<d2<<endl;
    if( feq(d1, d2) ) return d1;
    if(d1 < d2) 
        return fgcd(d2, d1);

    if(feq(d2/d1, 0)) return d1;
    if( feq(fmod(d1, d2), 0) ){
        return d2;
    }
    return fgcd(d2, fmod(d1, d2));
}
int main()
{
    Point p[3];
    for(int i=0; i<3; i++)
        cin>>p[i].x>>p[i].y;
    double len[3];
    for(int i=0; i<3; i++){
        len[i] = dist(p[i], p[(i+1)%3]);
    }

    double area = Heron(len[0], len[1], len[2]);
    double r = (len[0]*len[1]*len[2]) / (4*area); //外接圆半径

    double angle[3];
    for(int i=0; i<3; i++){
        angle[i] = asin(len[i]/(2*r)) * 180/PI * 2;
    }

    double min_angle = 360;
    for(int i=0; i<3; i++)
    {
        min_angle = fgcd(angle[i], min_angle);
    }

//    int N = int(360/min_angle + 0.5);
    double N = 360/min_angle;
    cout<<fixed<<setprecision(8)<<N*0.5*r*r*sin(min_angle*PI/180)<<endl;

//    cout<<"N = "<<360/min_angle <<endl;
    return 0;
}
