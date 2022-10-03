// Thomas Freeman
// implementation of FibLFSR.cpp
// This code is what builds and allows the
// sixteen bit linear feedback register to perform operations
// along with allowing tests to be used via the boost library's.
// I did this by using an array to store the string of bits and
// wrote out the step and generate functions. 


#include "FibLFSR.h"
#define ASCII_OFFSET 48

// Our FibLFSR constructor, uses a 16 character
// string as input
FibLFSR::FibLFSR(std::string seed) {

	size = seed.length();
	if (size == 16) {
	reg = new int[size];

		int count = 0;
		for (int i = size - 1; i >= 0; i--) {
		reg[i] = (int)seed[count] - ASCII_OFFSET;
		count++;
		}
	}
	
	else {

		reg = nullptr;
		size = 0;
		//No try-catch block for BOOST tests
		throw std::invalid_argument(
			"Seeds are sixteen bits only!");
	}
}

FibLFSR::FibLFSR(FibLFSR& copyLFSR) {

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


// The Assignment operators for 
// Assigning new values.
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


// Step allows us to show one step of the register, specifically the
// exclusive or operation on the leftmost bit. Returning the rightmost bit.
int FibLFSR::step() {

	int rightmostBit = reg[15] ^ reg[13];
	rightmostBit ^= reg[12];
	rightmostBit ^= reg[10];

	// shifts each bit left except for the rightmost bit
	for (int i = size - 1; i >= 1; i--) {
		reg[i] = reg[i - 1];
	}
	reg[0] = rightmostBit;  
	// As a result, we create a new rightmost bit

	return rightmostBit;
}


// Generate takes an int K and generates k number of steps for the LFSR to produce int k 
int FibLFSR::generate(int k) {

	int result = 0;
	for (int i = k; i > 0; i--) {
		result *= 2;
		result += step();
	}
	return result;
}

// Operator displays bits from highest to lowest index by overloading the stream insertion operator
std::ostream& operator<<(std::ostream& out, const FibLFSR& flfsr) {

	for (int i = flfsr.size - 1; i >= 0; i--) {
		out << flfsr.reg[i];
	}
	return out;
}