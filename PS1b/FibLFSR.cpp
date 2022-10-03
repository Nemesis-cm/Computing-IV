//Thomas Freeman
//Implementation of FibLFSR.cpp
//Tweaked from the first part to allow for
//the intended tap bits to work with the register.
//this allows each shift to help in encrypting the
//given image.


#include "FibLFSR.h"
#define TAP_BIT1 13
#define TAP_BIT2 12
#define TAP_BIT3 10

//The Constructors
FibLFSR::FibLFSR() : size(0), reg(nullptr) {}

FibLFSR::FibLFSR(std::string seed) {
    size = seed.length();
    if (size == 16) {
    reg = new int[size];
    int bit = 0;
    int count = 0;
        for (int i = size - 1; i >= 0; i--) {
            
        bit = (int)seed[count] - ASCII_OFFSET;
            if (bit == 0 || bit == 1) {
            reg[i] = bit;
            count++;
            }
            else {
                reg = nullptr;
                size = 0;
                throw std::invalid_argument("Incorrect seed, seed must be"
                " in binary form");
        }
    }
    }
    //Throws exception for strings > 16 bits
    else {
        reg = nullptr;
        size = 0;
        throw std::invalid_argument("Incorrect seed size, seed must be 16"
        " bits long");
}
}
//Most of the code doesn't change in this method
FibLFSR::FibLFSR(const FibLFSR& copyLFSR) {
    size = copyLFSR.size;
    if (size > 0) {
    reg = new int[size];
    for (int i = 0; i < size; i++) {
        reg[i] = copyLFSR.reg[i];
    }
    }
    else reg = nullptr;
}

FibLFSR::FibLFSR(FibLFSR&& moveLFSR) noexcept {
    size = moveLFSR.size;
    reg = moveLFSR.reg;
    moveLFSR.reg = nullptr;
    moveLFSR.size = 0;
}

FibLFSR::~FibLFSR() {
    if (reg != nullptr) delete[] reg;
    reg = nullptr;
    size = 0;
}

//Assignment operators need to be overloaded like lastime

FibLFSR& FibLFSR::operator=(const FibLFSR& rvalue) {
    if (this == &rvalue) return *this;
    if (reg != nullptr) delete[] reg;

    size = rvalue.size;
    if (size > 0) {
    reg = new int[size];
    for (int i = 0; i < size; i++) {
    reg[i] = rvalue.reg[i];
    }
    }
    return *this;
}

FibLFSR& FibLFSR::operator=(FibLFSR&& rvalue) noexcept {
    if (this == &rvalue) return *this;
    if (reg != nullptr) delete[] reg;

    size = rvalue.size;
    reg = rvalue.reg;
    rvalue.reg = nullptr;
    rvalue.size = 0;

    return *this;
}

//Substitute the Tap bits into the step function
int FibLFSR::step() {
    int rightmostBit = reg[size - 1] ^ reg[TAP_BIT1];
    rightmostBit ^= reg[TAP_BIT2];
    rightmostBit ^= reg[TAP_BIT3];

    //Still shifts the bits from left to right
    for (int i = size - 1; i >= 1; i--) {
    reg[i] = reg[i - 1];
    }
    reg[0] = rightmostBit;  //assigns the rightmost bit

    return rightmostBit;
}

//generate method remains the same
int FibLFSR::generate(int k) {
    int result = 0;
    for (int i = k; i > 0; i--) {
    result *= 2;
    result += step();
    }
    return result;
}

// Stream insertion operator doesn't change again
std::ostream& operator<<(std::ostream& out, const FibLFSR& flfsr) {
    for (int i = flfsr.size - 1; i >= 0; i--) {
    out << flfsr.reg[i];
}
    return out;
}