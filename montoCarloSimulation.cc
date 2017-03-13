// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#include "monteCarloSimulation.h"
#include <algorithm>
#include <cmath>

double monteCarloSimulation(int n, std::vector<int>& index) {
    // Initialize all sites to be blocked
    Percolation perc(n);
    // random shuffle the index
    std::random_shuffle(index.begin(), index.end());
    int row = 0, col = 0, counter = 0;
    double n_double = n;
    // Repeat the loop until the system percolates
    while(!perc.percolates()) {
        row = std::ceil(index[counter] / n_double);
        col = index[counter] - (row - 1) * n;
        perc.open(row, col);
        ++counter;
    }

    // perc.printGridSnapshot();

    return counter / std::pow(n_double, 2);
}

std::vector<double> runExperiment(int n, int num_iters) {
    std::vector<int> index;
    std::vector<double> prob;

    for(int i = 0; i < n * n; ++i)
        index.push_back(i + 1);

    for(int i = 0; i < num_iters; ++i) {
        prob.push_back(monteCarloSimulation(n, index));
    }
    return prob;
}
