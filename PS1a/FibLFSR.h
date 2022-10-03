// Thomas Freeman
// implementation of FibLFSR.h
// Simple header file to prevent building
// this register from becoming a nightmare.



#ifndef FIBLFSR_H
#define FIBLFSR_H
#include <iostream>
#include <exception>

class FibLFSR {
public:
	FibLFSR(std::string seed);  
	//Constructor creates LFSR with a given seed and set of tap bits

	explicit FibLFSR(FibLFSR& copyLFSR);
	explicit FibLFSR(FibLFSR&& moveLFSR) noexcept;
	~FibLFSR();
	FibLFSR& operator=(const FibLFSR& rvalue);
	FibLFSR& operator=(FibLFSR&& rvalue) noexcept;

	int step();            // Shows one step in the algorithm and returns a bit 
	int generate(int k);   // Shows a given number of steps (k) and returns a value. 

	// Displays the register
	friend std::ostream& operator<<(std::ostream& out, const FibLFSR& flfsr);

private:
	int size;               // Register size
	int* reg;               // Defines register as an array of integers
};
#endif