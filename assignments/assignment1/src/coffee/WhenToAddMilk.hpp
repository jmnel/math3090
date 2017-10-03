#pragma once

#include <cmath>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

#include "Common.hpp"

namespace math3090 {

    class AddingMilkModel {
    public:
        AddingMilkModel(Real u0, Real uRoom, Real uFinal,
                        Real c, Real tStar, Real uMilk,
                        Real rho );

        pair<vector<Real>, vector<Real>> runSimulation(Real t0, Real tEnd,
                                                       Real dt);

        pair<vector<Real>, vector<Real>> analyticSolution(Real t0, Real tEnd,
                                                          Real dt);

    private:
        Real u0, uRoom, uFinal;
        Real c;
        Real tStar, uMilk, rho;
    };
}  // namespace math3090
