// Thomas Freeman
// test.cpp for PS1a
// Provided test file that I modified with my own Boost tests

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

	FibLFSR l("1011011000110110");
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 1);

	FibLFSR l2("1011011000110110");
	BOOST_REQUIRE(l2.generate(9) == 51);

}

// First test case shows simple input and output using the 
// test value from the initial test case.
BOOST_AUTO_TEST_CASE(my_test1) {

	std::cout << "First Test" << std::endl;
	FibLFSR lfsr("1011011000110110");
	std::cout << " Original seed: " << lfsr << std::endl;

	int result = lfsr.generate(5);
	BOOST_REQUIRE(result == 3);

	std::cout << "After generate(5): " << lfsr << " " << result << std::endl;
	std::cout << std::endl;
}

	// This test is meant to show when an input seed
	// is too long or too short. 
	BOOST_AUTO_TEST_CASE(my_test2) {

		std::cout << "\n Test Case #2" << std::endl;
		std::string testSeed1 = "111000110";
		std::string testSeed2 = "00000000000000000001";

		std::cout << "Seed is less than 16 bits : "
			<< std::endl;
		BOOST_REQUIRE_THROW(FibLFSR("0101100101"), std::invalid_argument);

		std::cout << "Seed is more than 16 bits :  "
			"0111011000110110101100" << std::endl;
		BOOST_REQUIRE_THROW(FibLFSR("0111011000110110101100"),
			std::invalid_argument);
	}