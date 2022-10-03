//Thomas Freeman
//Implementation of FibLFSR.cpp header file
//Sets up and displays all methods like ps1a


#include <iostream>
#include <exception>
#include <math.h>
#ifndef FIBLFSR_H
#define FIBLFSR_H
#define ASCII_OFFSET 48

class FibLFSR {
public:
    FibLFSR();
    FibLFSR(std::string seed);  // Constructor for the register
                                // with the seed and tap
    explicit FibLFSR(const FibLFSR& copyFibLFSR);
    explicit FibLFSR(FibLFSR&& moveFibLFSR) noexcept;
    ~FibLFSR();
    FibLFSR& operator=(const FibLFSR& rvalue);
    FibLFSR& operator=(FibLFSR&& rvalue) noexcept;

    int step();             // simulates a step of the register
                            
    int generate(int k);    // simulates k steps of the register

    //Register is displayed
    friend std::ostream& operator<<(std::ostream& out, const FibLFSR&
    flfsr);

private:
    int size;               // register size
    int* reg;               // integers in an array for the register
};

#endif