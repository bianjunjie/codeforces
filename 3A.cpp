/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file 3A.cpp
 * @author bianjunjie(com@baidu.com)
 * @date 2014/05/27 16:48:29
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define H 8
#define W 8

struct Node
{
    int h;
    int w;
    vector<string> moves;
    Node(int _h, int _w){
        h=_h;w=_w;
    }
    Node(string &s){
        h = s[1]-'1';
        w = s[0]-'a';
    }
};

bool state[H][W]={0};

vector<Node> next(Node& n)
{
    vector<Node> v;
    string moves[]={"LD","D","RD","L","?","R","LU","U","RU"};
    
    for(int i=-1; i<=1; i++)
        for(int j=-1; j<=1; j++)
        {
            if(i==0 && j==0) continue;
            if(n.h+i<0 || n.h+i>=H || n.w+j<0 || n.w+j>=W) continue;
            if(state[n.h+i][n.w+j]) continue;

            int k = (i+1)*3+(j+1);
            Node c = n; 
            c.h = n.h+i; c.w=n.w+j; c.moves.push_back(moves[k]);
            state[c.h][c.w]=true;

            v.push_back(c);
        }
    return v;
}
int main()
{
    string begin, end;
    cin>>begin>>end;
    Node n(begin);
    Node m(end);
    state[n.h][n.w]=true;
    
    queue<Node> q;q.push(n);
    while(!q.empty()){
        Node front = q.front();
        if(front.h== m.h && front.w==m.w)break;
        vector<Node> v = next(q.front());q.pop();
        for(size_t i=0; i<v.size(); i++)
            q.push(v[i]);
    }
    Node front = q.front();
    cout<<front.moves.size()<<endl;
    for(int i=0; i<front.moves.size(); i++)
        cout<<front.moves[i]<<endl;
    return 0;
    
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
