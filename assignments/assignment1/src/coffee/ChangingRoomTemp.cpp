#include "ChangingRoomTemp.hpp"

namespace math3090 {

    // -- Constructor --
    ChangingRoomTempModel::ChangingRoomTempModel(Real u0, Real uRoom0, Real c)
        : u0(u0), uRoom0(uRoom0), c(c) {}

    // -- getRoomTemp function --
    Real ChangingRoomTempModel::getRoomTemp(Real t) {
        return t < 120.0 ? uRoom0 + ( 6.0 / 120.0 ) * t : 26.0;
    }

    pair<vector<Real>, vector<Real>> ChangingRoomTempModel::getRoomTempSeries(
        Real t0, Real tEnd, Real dt) {
        vector<Real> t, u;

        for (int k = 0; t0 + k * dt <= tEnd; k++) {
            auto tCur = t0 + k * dt;

            t.emplace_back(tCur);
            u.emplace_back(getRoomTemp(tCur));
        }

        return make_pair(t, u);
    }

    // -- runSimulation function --
    pair<vector<Real>, vector<Real>> ChangingRoomTempModel::runSimulation(
        Real t0, Real tEnd, Real dt) {
        assert(tEnd > t0);
        assert(dt > 0.0);

        vector<Real> t, u;

        t.push_back(t0);
        u.push_back(u0);

        for (int k = 1; t0 + k * dt <= tEnd; k++) {
            auto tCur = t0 + k * dt;

            auto uRoom = getRoomTemp(tCur);
            auto uCur = u.back() + c * dt * (uRoom - u.back());

            t.emplace_back(tCur);
            u.emplace_back(uCur);
        }

        return make_pair(t, u);
    }

}  // namespace math3090
