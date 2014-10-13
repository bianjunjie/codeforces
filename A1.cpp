/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file A1.cpp
 * @author bianjunjie(com@baidu.com)
 * @date 2014/04/23 13:52:46
 * @brief 
 *  
 **/
#include <cmath>
#include <iostream>
using namespace std;
int main(){
    int n,m,a; cin>>n>>m>>a;
    
    int p = (int) ceil(n*1.0/a);
    int q = (int) ceil(m*1.0/a);
    cout<<p*q<<endl;
    return 0;

}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
