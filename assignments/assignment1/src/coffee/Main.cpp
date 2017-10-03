// -- Calculations for assignment 1 --
// -- Cooling Coffee -----------------
// -- Math 3090 ----------------------

#include <array>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>

#include <gnuplot-iostream.h>

#include "ChangingRoomTemp.hpp"
#include "Common.hpp"
#include "WhenToAddMilk.hpp"

using std::array;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

using namespace math3090;

void question1();
void runQuestion2part1();
void runQuestion2part2();

// -- Application entry point --
int main(int argc, char *argv[]) {
    // Set simulation parameters
    // const Real dt = 10.0;   // Time step is 10 minutes
    // const Real u0 = 100.0;  // Initial coffee temperature is 100°C

    //// Hypothetical measured values used to calculate insulation coefficient c
    // const Real h = 10.0;        // Observation time is 10 minutes
    // const Real uObserv = 90.0;  // Temp. after observing for 10 minutes

    //// Lambda for changing room temperature
    // auto uSurAtTime = [&](Real t) -> Real {
    // const Real uSurStart = 20.0;
    // if (t < 2.0) {
    // return 20.0 + 3.0 * t;
    //} else {
    // return 26.0;
    //}
    //};

    question1();

    runQuestion2part1();
    runQuestion2part2();

    return EXIT_SUCCESS;
}

// -- Runs calculations for Question 1 and outputs data tables and figures --
void question1() {
    cout << "Running Question 1..." << endl;
    cout << "---------------------" << endl;

    const Real uRoom0 = 20.0;
    const Real u0 = 100.0;
    const Real uObs = 90.0;
    const Real h = 10.0;

    // Estimate thermal conduction coefficient c
    auto c = (uObs - u0) / (h * (uRoom0 - u0));

    ChangingRoomTempModel model(u0, uRoom0, c);

    const Real t0 = 0.0;
    const Real tEnd = 6.0 * 60.0;
    const Real dt = 10.0;
    auto room = model.getRoomTempSeries(t0, tEnd, dt);
    auto coffee = model.runSimulation(t0, tEnd, dt);

    auto tRoom = room.first;
    auto uRoom = room.second;

    auto tCoffee = coffee.first;
    auto uCoffee = coffee.second;

    fstream file;
    file.open("../data/table1-1.txt", std::ios::out);

    for (size_t i = 0; i < tRoom.size(); i++) {
        file << tRoom[i] << "  " << uRoom[i];
        file << "\n";
    }
    file << "\n\n";
    for (size_t i = 0; i < tCoffee.size(); i++) {
        file << tCoffee[i] << "  " << uCoffee[i];
        file << "\n";
    }
    file.close();

    Gnuplot gp;
    gp << "load '../figures/figure1-1.gp'";
    gp << endl;
}

void runQuestion2part1() {
    cout << "Running Question 2 part 1..." << endl;
    cout << "----------------------------" << endl;

    const Real u0 = 100.0;
    const Real uRoom = 22.0;
    const Real uFinal = 50.0;
    const Real c = 0.01282;
    const Real uMilk = 6.0;
    const Real rho = 0.1;
    const Real tStar = 50.0;

    AddingMilkModel model(u0, uRoom, uFinal, c, tStar, uMilk, rho);

    const Real t0 = 0.0;
    const Real tEnd = 120.0;
    const Real dt = 10.0;
    auto res = model.analyticSolution(t0, tEnd, dt);

    // Output to data file `table2-1.txt`
    fstream file;
    file.open("../data/table2-1.txt", std::ios::out);

    auto &t = res.first;
    auto &u = res.second;

    for (size_t iRow = 0; iRow < t.size(); iRow++) {
        file << t[iRow] << "  " << u[iRow] << "\n";
    }

    file.close();

    // Plot `Figure 2-1` using gnuplot
    cout << "  Ploting `Figure 2-1` using gnuplot" << endl;

    Gnuplot gp;
    gp << "load '../figures/figure2-1.gp'";
    gp << endl;

    // Program state info output
    cout << "Done." << endl << endl;
}

void runQuestion2part2() {
    cout << "Running Question 2 part 2..." << endl;
    cout << "----------------------------" << endl;

    const Real u0 = 100.0;
    const Real uRoom = 22.0;
    const Real uFinal = 50.0;
    const Real c = 0.01234;
    const Real uMilk = 6.0;
    const Real rho = 0.1;

    fstream file;
    file.open("../data/table2-2.txt", std::ios::out);
    auto tStarMax1 = c * log(u0 - uRoom);
    auto tStarMax2 = c * log(rho * (rho + 1.0) * uMilk * uFinal);
    auto tStarMax = tStarMax1 - tStarMax2;

    cout << "tStarMax=" << tStarMax << endl;

    vector<Real> tStarLocations = {0, 10, 30, 40, 50, 80};

    for (size_t i = 0; i < tStarLocations.size(); i++) {
        const Real tStar = tStarLocations[i];

        // cout << "tStar=" << tStar << endl;

        AddingMilkModel model(u0, uRoom, uFinal, c, tStar, uMilk, rho);

        const Real t0 = 0.0;
        const Real tEnd = 120.0;
        const Real dt = 2.0;
        auto res = model.runSimulation(t0, tEnd, dt);

        auto &t = res.first;
        auto &u = res.second;

        for (size_t iRow = 0; iRow < t.size(); iRow++) {
            file << t[iRow] << "  " << u[iRow] << "\n";
        }
        file << "\n";
        file << "\n";
    }

    file.close();

    Gnuplot gp;
    gp << "load "
          "'../figures/"
          "figure2-3.gp'";
    gp << endl;

    // -- Compare analytical and discrete model
    Real tStar = 40.0;
    AddingMilkModel model(u0, uRoom, uFinal, c, tStar, uMilk, rho);

    auto seriesAnalytic = model.analyticSolution(0.0, 120.0, 2.0);

    array<Real, 4> discSteps{{40.0, 20.0, 10.0, 5.0}};

    // Write to file `table2-3.txt`
    file.open("../data/table2-3.txt", std::ios::out);
    for (size_t i = 0; i < seriesAnalytic.first.size(); i++) {
        file << seriesAnalytic.first[i];
        file << "  ";
        file << seriesAnalytic.second[i];
        file << "\n";
    }
    file << "\n\n";

    for (auto step : discSteps) {
        auto seriesDiscrete = model.runSimulation(0.0, 120.0, step);
        for (size_t i = 0; i < seriesDiscrete.first.size(); i++) {
            file << seriesDiscrete.first[i];
            file << "  ";
            file << seriesDiscrete.second[i];
            file << "\n";
        }
        file << "\n\n";
    }

    file.close();

    Gnuplot gp2;
    gp2 << "load '../figures/figure2-3.gp'";
    gp2 << endl;
}

// -- estimateInsulation function --
// Real estimateInsulation(Real u0, Real uSur, Real uObserv, Real h) {
// auto c = (uObserv - u0) / (h * (uSur - u0));
// return c;
//}

// -- tempOfCoffee function --
// Real tempOfCoffee(Real dt, uint steps, Real u0, std::function<Real(Real)>
// uSur,  Real c) {}
