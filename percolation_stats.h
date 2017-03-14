// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#ifndef PERCOLATION_STATS_H_
#define PERCOLATION_STATS_H_

#include "monte_carlo_simulation.h"

class PercolationStats {

friend void runExperiment(int n, int num_iters, std::vector<double>& prob);

public:
    // perform trials independent experiments on an n-by-n grid
    PercolationStats(int n, int trials) : n(n), trials(trials) { }
    // run Experiments
    void run();
    // get mean value
    double mean();
    // get standard deviation
    double stddev();
    // get 95% confidence low value
    double confidenceLo();
    // get 95% confidence high value
    double confidenceHi();

private:
    // probability array
    std::vector<double> prob;
    // n-by-n grid
    int n;
    // number of trials
    int trials;
    // mean value
    double mean_val;
    // standard deviation value
    double stddev_val;
};

// friend function declaration
void runExperiment(int n, int num_iters, std::vector<double>& prob);

#endif // PERCOLATION_STATS_H_
