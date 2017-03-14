// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#include <iostream>
#include "percolation_stats.h"
#include <string>
#include <algorithm>

using namespace std;

bool is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

int main(int argc, char *argv[])
{
    if(argc != 3)
        throw invalid_argument("Argument number should be 2.");
    if(!is_digits(argv[1]) || !is_digits(argv[2]))
        throw invalid_argument("Argument type only should be number.");

    int n = std::stoi(argv[1]);
    int trials = std::stoi(argv[2]);

    PercolationStats ps(n, trials);

    ps.run();
    cout << "mean                    = " << ps.mean() << endl;
    cout << "stddev                  = " << ps.stddev() << endl;
    cout << "95% confidence interval = [" <<
            ps.confidenceLo() << "," <<
            ps.confidenceHi() << "]" << endl;

    return 0;
}
