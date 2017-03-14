// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#include "union_find.h"

UnionFind::UnionFind(int N){
    counter = N;
    for(int i=0; i < N; ++i)
        id.push_back(i);
}

int UnionFind::find_op(int p){
    return id[p];
}

void UnionFind::union_op(int p, int q){
    int pID = find_op(p);
    int qID = find_op(q);

    if(pID == qID) return;

    for(unsigned i = 0; i < id.size(); ++i)
        if(id[i] == pID) id[i] = qID;
    counter--;
}

bool UnionFind::connected(int p, int q){
    return find_op(p) == find_op(q);
}

void UnionFind::print_node_status() const{
    std::cout << "| id | root |" << std::endl;
    for(unsigned i=0; i < id.size(); ++i)
        std::cout << "| "<< i << " | " << id[i] << " |" << std::endl;
}
