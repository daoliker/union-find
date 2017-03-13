// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#ifndef WEIGHTED_QUICK_UNION_UF_H_
#define WEIGHTED_QUICK_UNION_UF_H_

#include <iostream>
#include <vector>

// 应用点:小鳄鱼爱洗澡

class WeightedQuickUnionUF {
public:
	WeightedQuickUnionUF(int);
	void union_op(int, int);
	// find root
	int find_op(int);
	bool connected(int, int);
	void print_node_status() const;
	int get_count() const { return counter; }
private:
    // 连通分量的id
	std::vector<int> id;
	// 各个根节点所对应的分量的大小
	std::vector<int> sz;
	// 连通分量的个数
	int counter;
};

#endif // WEIGHTED_QUICK_UNION_UF_H_
