// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#include "PercolationStats.h"
#include <cmath>

void PercolationStats::run() {
    prob = runExperiment(n, trials);
}

double PercolationStats::mean() {
    for(int i =0; i < trials; ++i)
        mean_val += prob[i] / trials;
    return mean_val;
}

double PercolationStats::stddev() {
    for(int i =0; i < trials; ++i) {
        stddev_val += std::pow(prob[i] - mean_val, 2) / (trials - 1);
    }
    stddev_val = std::sqrt(stddev_val);

    return stddev_val;
}

double PercolationStats::confidenceHi() {
    return mean_val + (1.96 * stddev_val) / std::sqrt(trials);
}

double PercolationStats::confidenceLo() {
    return mean_val - (1.96 * stddev_val) / std::sqrt(trials);
}

