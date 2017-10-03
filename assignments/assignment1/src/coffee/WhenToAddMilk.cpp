#include "WhenToAddMilk.hpp"

namespace math3090 {

    // -- Constructor --
    AddingMilkModel::AddingMilkModel(Real u0, Real uRoom, Real uFinal, Real c,
                                     Real tStar, Real uMilk, Real rho)
        : u0(u0),
          uRoom(uRoom),
          uFinal(uFinal),
          c(c),
          tStar(tStar),
          uMilk(uMilk),
          rho(rho) {}

    // -- runSimulation function --
    pair<vector<Real>, vector<Real>> AddingMilkModel::runSimulation(
        Real t0, Real tEnd, Real dt) {
        assert(tEnd > t0);
        assert(dt > 0.0);
        assert( fmod( tStar, dt ) == 0.0 );

        vector<Real> t, u;

        t.push_back( t0 );
        u.push_back( u0 );

        if( tStar == t0 ) {
            auto uMix = ( u0 + rho * uMilk ) / ( 1.0 + rho );
            u.back() = uMix;
        }

        for (int k = 1; k * dt <= tEnd; k++) {
            auto tCur = k * dt;
           

            auto uCur = u.back() + c * dt * ( uRoom - u.back() );

            t.emplace_back( tCur );
            u.emplace_back( uCur );
           
            if( tStar == tCur ) {
                auto uMix = ( uCur + rho * uMilk ) / ( 1.0 + rho );
                t.emplace_back( tCur );
                u.emplace_back( uMix );
            }
        }

        return make_pair(t, u);
    }

    pair<vector<Real>, vector<Real>> AddingMilkModel::analyticSolution(
        Real t0, Real tEnd, Real dt) {
        auto a0 = u0 - uRoom;

        vector<Real> t;
        vector<Real> u;

        for (int k = 0; t0 + k * dt <= tStar && t0 + k * dt <= tEnd; k++) {
            auto tCur = t0 + dt * k;
            auto uCur = a0 * std::exp(-c * tCur) + uRoom;
            t.emplace_back(tCur);
            u.emplace_back(uCur);

        }

        if (tEnd >= tStar) {
            auto uStar = a0 * std::exp(-c * tStar) + uRoom;
            auto uMix = (uStar + rho * uMilk) / (1.0 + rho);
            t.emplace_back(tStar);
            u.emplace_back(uMix);

            // cout << "uStar=" << uStar << endl;
            // cout << "uMix=" << uMix << endl;

            auto b0 = uMix - uRoom;

            for (int k = 1; tStar + k * dt <= tEnd; k++) {
                auto tCur = tStar + dt * k;
                auto uCur = b0 * std::exp(-c * (tCur - tStar)) + uRoom;
                t.emplace_back(tCur);
                u.emplace_back(uCur);
            }
        }

        //for (size_t iRow = 0; iRow < t.size(); iRow++) {
            //// cout << iRow << ": " << t[iRow] << "   --   " << u[iRow] << endl;
        //}

        return make_pair(t, u);
    }

    // if (tEnd < tStar) {
    // for (int k = 0; k * dt <= tEnd; k++) {
    // auto tCur = dt * k;
    // auto uCur = a0 * std::exp(-c * tCur) + uRoom;
    // t.emplace_back(tCur);
    // u.emplace_back(uCur);
    //}
    //} else if (tEnd == tStar) {
    // for (int k = 0; k * dt <= tEnd; k++) {
    // auto tCur = dt * k;
    // auto uCur = a0 * std::exp(-c * tCur) + uRoom;
    // t.emplace_back(tCur);
    // u.emplace_back(uCur);
    //}
    // auto uMix = (u.back() + rho * uMilk) / (1.0 + rho);
    // t.emplace_back(tStar);
    // u.emplace_back(uMix);
    //}

}  // namespace math3090
