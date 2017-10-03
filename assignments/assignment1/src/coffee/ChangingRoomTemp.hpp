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

    class ChangingRoomTempModel {
    public:
        ChangingRoomTempModel(Real u0, Real uRoom0, Real c);

        Real getRoomTemp(Real t);

        pair<vector<Real>, vector<Real>> runSimulation(Real t0, Real tEnd,
                                                       Real dt);

        pair<vector<Real>, vector<Real>> getRoomTempSeries( Real t0, Real tEnd, Real dt );

    private:
        Real u0, uRoom0, uFinal;
        Real c;
        Real tStar, uMilk, rho;
    };
}  // namespace math3090
