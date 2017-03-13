// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#ifndef UNION_FIND_H_
#define UNION_FIND_H_

#include <iostream>
#include <vector>

class UnionFind {
public:
	UnionFind(int);
	void union_op(int, int);
	int find_op(int);
	bool connected(int, int);
	void print_node_status() const;
	int get_count() const { return counter; }
private:
    // 连通分量的id
	std::vector<int> id;
	// 连通分量的个数
	int counter;
};


#endif // UNION_FIND_H_
