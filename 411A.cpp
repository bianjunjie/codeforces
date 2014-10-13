/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file 411A.cpp
 * @author bianjunjie(com@baidu.com)
 * @date 2014/04/15 12:10:45
 * @brief 
 *  
 **/
#include <iostream>
#include <cstring>
using namespace std;
bool check(char *pw){
    int len = strlen(pw);
    if(len<5)return false;
    bool big=false, small=false, digit=false;
    for(int i=0; pw[i]; i++){
        if(pw[i]>='A' && pw[i]<='Z')big=true;
        else if(pw[i]>='a' && pw[i]<='z')small=true;
        else if(pw[i]>='0' && pw[i]<='9')digit=true;
        else;
    }
    return big&&small&&digit;
}
int main()
{
    char pw[101]={0}; cin>>pw;
    if(check(pw)){
        cout<<"Correct"<<endl;
    }else{
        cout<<"Too weak"<<endl;
    }
    return 0;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
