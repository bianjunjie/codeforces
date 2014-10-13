/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file 416A.cpp
 * @author bianjunjie(com@baidu.com)
 * @date 2014/04/14 21:42:03
 * @brief 
 *  
 **/
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n; cin>>n;
    int l=INT_MIN, r=INT_MAX;
    while(n--){
        string op;
        char yn;
        int val;
        cin>>op>>val>>yn;
        if((op==">" && yn=='Y') || (op=="<=" && yn=='N')){
            l=max(l,val+1);
        }
        else if((op==">=" && yn=='Y') || (op=="<" && yn=='N')){
            l=max(l,val);
        }
        else if((op=="<" && yn=='Y') || (op==">=" && yn=='N')){
            r = min(r, val-1);
        }
        else{
            r = min(r,val);
        }
    }
    if(r<l||l>2e9 || r<-2e9){
        cout<<"Impossible"<<endl;
    }else{
        if(l<-2e9)l=(int)(-2e9);
        cout<<l<<endl;
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
