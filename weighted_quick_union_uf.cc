// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#include "weighted_quick_union_uf.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(int N) {
    counter = N;
    for(int i=0; i < N; ++i){
        id.push_back(i);
        // 初始分量大小为１
        sz.push_back(1);
    }
}

bool WeightedQuickUnionUF::connected(int p, int q) {
    return find_op(p) == find_op(q);
}

int WeightedQuickUnionUF::find_op(int p){
    while(id[p] != p) {
        // 路径压缩
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;

}

void WeightedQuickUnionUF::union_op(int p, int q) {
    int root_p = find_op(p);
    int root_q = find_op(q);

    if(root_p == root_q) return;

    if(sz[root_p] > sz[root_q]){
        id[root_q] = root_p;
        sz[root_p] += sz[root_q];
    }else{
        id[root_p] = root_q;
        sz[root_q] += sz[root_p];
    }
    counter--;
}

void WeightedQuickUnionUF::print_node_status() const {
    std::cout << "| id | root |" << std::endl;
    for(unsigned i=0; i < id.size(); ++i)
        std::cout << "| "<< i << " | " << id[i] << " |" << std::endl;

    std::cout << "| id | component |" << std::endl;
    for(unsigned i=0; i < id.size(); ++i)
        std::cout << "|   "<< i << "   |   " << sz[i] << "   |" << std::endl;
}



