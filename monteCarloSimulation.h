// Copyright (c) 2017 The Authors. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file, See the AUTHORS file for names of contributors.

#ifndef MONTE_CARLO_SIMULATION_H_
#define MONTE_CARLO_SIMULATION_H_

#include "Percolation.h"

double monteCarloSimulation(int n, std::vector<int>& index);
std::vector<double> runExperiment(int n, int num_iters);

#endif // MONTE_CARLO_SIMULATION_H_
