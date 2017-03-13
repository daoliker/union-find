// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#include "Percolation.h"
#include <stdexcept>


Percolation::Percolation(int n) : wuf(n * n + 2) {
    if(n <= 0)
        throw std::invalid_argument("Invalid argument " \
                                    "which should greater than 0!");
    max_indice = n;
    source_indice = 0;
    sink_indice = n * n + 1;
    num_open_site = 0;
    grid.resize(n);

    for(int i = 0; i < n; ++i)
        grid[i].resize(n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            // false for site blocked
            grid[i][j] = false;
        }
    }
}

void Percolation::open(int row, int col) {
    if(row < 1 || col < 1 || row > max_indice || col > max_indice)
        throw std::out_of_range("Row or col index out of range!");
    grid[row - 1][col - 1] = true;

    // Connect to up/down/left/right site if it is open and exists
    // left
    if(col - 1 > 0 && grid[row - 1][col - 2])
        wuf.union_op((row - 1) * max_indice + col, (row - 1) * max_indice + col - 1);
    // right
    // col + 1 < max_indice + 1
    if(col < max_indice && grid[row - 1][col])
        wuf.union_op((row - 1) * max_indice + col, (row - 1) * max_indice + col + 1);
    // up
    if((row - 1 > 0 && grid[row - 2][col - 1]) || row == 1) {
        // top most
        if(row == 1)
            wuf.union_op((row - 1) * max_indice + col, source_indice);
        else
            wuf.union_op((row - 1) * max_indice + col, (row - 2) * max_indice + col);
    }
    // down
    if((row < max_indice && grid[row][col -1]) || row == max_indice) {
        // down most
        if(row == max_indice)
            wuf.union_op((row - 1) * max_indice + col, sink_indice);
        else
            wuf.union_op((row - 1) * max_indice + col, row * max_indice + col);
    }


    num_open_site++;
}

bool Percolation::isOpen(int row, int col) {
    if(row < 1 || col < 1 || row > max_indice || col > max_indice)
        throw std::out_of_range("Row or col index out of range!");
    return grid[row - 1][col - 1] == true;
}

bool Percolation::isFull(int row, int col) {
    if(row < 1 || col < 1 || row > max_indice || col > max_indice)
        throw std::out_of_range("Row or col index out of range!");
    return wuf.connected((row - 1) * max_indice + col, source_indice);
}

int Percolation::numberOfOpenSites() const {
    return num_open_site;
}

bool Percolation::percolates() {
    return wuf.connected(source_indice, sink_indice);
}

void Percolation::printGridSnapshot() {
    std::cout << std::noboolalpha;
    for(int i = 0; i < max_indice; ++i) {
        for(int j = 0; j < max_indice; ++j) {
            std::cout << " | " << grid[i][j];
        }
        std::cout << " |" << std::endl;
    }
}
