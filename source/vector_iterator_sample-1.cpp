//------------------------------------------------------------------------------
// vector_iterator_sample.cpp
//
// demos use of the vector insert() function
//------------------------------------------------------------------------------
#include "Helicopter.h"

// turn off assertions 
//#define NDEBUG
// must #define NDEBUG before #including assert.h
#include <cassert>

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int NUM_HELOS = 4;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    string heloNames[] = { "Apache 7", "Huey Looey", "Black Hawk", "Marine 1", };

    // make sure the number of names matches the number of Helicopters
    assert((sizeof(heloNames) / sizeof(string)) == NUM_HELOS);

    // Note this is a vector of instances, NOT a vector of references
    std::vector<Helicopter> vHelos;

    Helicopter h;
    h.setThrottle(SPEED_SLOW);

    // need Helicopter member function to set fuel level

    for (int i = 0; i < NUM_HELOS; ++i) {
// #TODO add this function to Helicopter and FuelGauge, then uncomment this call
        h.setFuelLeft(rand() % 70 + 30);

// #TODO add this function to Helicopter, then uncomment this call
        h.setName(heloNames[i]);

        // this will generate a copy of your local Helicopter instance
        // and add it to the back of your vector
        vHelos.push_back(h);
    }

    // Now let's traverse the vector with an iterator named 'it'
    //for (std::vector<Helicopter>::iterator it = vHelos.begin(); it != vHelos.end(); ++it) {
    for (auto it = vHelos.begin(); it != vHelos.end(); ++it) {
// #TODO add this function to Helicopter, then uncomment this call
        //cout << it->getName() << "\n";
        cout << it->getName() << " has " << it->getFuelLeft() << " gallons of fuel\n";
        //cout << "Helicopter\n";
    }
    cout << '\n';

    // Reset the iterator to reference the first vector element
    auto it = vHelos.begin();

    // insert another Helicopter at index 2
// #TODO add this function to Helicopter, then uncomment this call
    h.setFuelLeft(500);
// #TODO add this function to Helicopter, then uncomment this call
    h.setName("TEST at index 2");
    vHelos.insert(it + 2, h);

    // Reset the iterator AGAIN to reference the first vector element
    it = vHelos.begin();

    // insert another Helicopter at index 0
// #TODO add this function to Helicopter and FuelGauge, then uncomment this call
    h.setFuelLeft(5);
// #TODO add this function to Helicopter, then uncomment this call
    h.setName("TEST at index 3");
    vHelos.insert(it + 3, h);

    // traverse vector with iterator again
    for (auto it = vHelos.begin(); it != vHelos.end(); ++it) {
// #TODO add these functions to Helicopter and FuelGauge, then uncomment this call
        //cout << it->getName() << "\n";
        cout << it->getName() << " has " << it->getFuelLeft() << " gallons of fuel\n";
        //cout << "2 more Helicopters\n";
    }
    cout << '\n';

    return 0;
}