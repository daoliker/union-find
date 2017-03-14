// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#ifndef PERCOLATION_H_
#define PERCOLATION_H_

#include <vector>
#include "weighted_quick_union_uf.h"

class Percolation {
public:
    // create n-by-n grid, with all sites blocked
    Percolation(int n);
    // open site (row, col) if it is not open already
    void open(int row, int col);
    // is site (row, col) open?
    bool isOpen(int row, int col);
    // is site (row, col) full?
    bool isFull(int row, int col);
    // number of open sites
    int numberOfOpenSites() const;
    // does the system percolate?
    bool percolates();
    // print grid status snapshot
    void printGridSnapshot();

private:
    // n x n grid
    std::vector< std::vector<short> > grid;
    // maximum indice to access the grid
    int max_indice;
    // number of open sites
    int num_open_site;
    // virtual source indice
    int source_indice;
    // virtual sink indice
    int sink_indice;
public:
    // union find object
    WeightedQuickUnionUF wuf;

};

#endif // PERCOLATION_H_
