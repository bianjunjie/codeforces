/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file 429A.cpp
 * @author bianjunjie(com@baidu.com)
 * @date 2014/05/22 11:57:19
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

struct XorNode{
    int index;
    int val; //0 or 1
    vector<int> children;
};

vector<XorNode> tree;

vector<int> bfs_visit(tree);

void flip(tree, i); //flip tree at ith node




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
