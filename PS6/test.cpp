// copyright 2021 Thomas Freeman

#include "RandWriter.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(base_test) {
    std::cout << "Test Case 1 " <<
    std::endl;

    int k = 2;
    std::string str = "gagggagaggcgagaaa";
    RandWriter randwriter(str, k);

    std::cout << "Printing out Markov Table for string:\n" <<
    str << std::endl << std::endl;
    std::cout << randwriter << std::endl;

        std::cout << "Testing kOrder and freq functions" << std::endl;
        BOOST_REQUIRE(randwriter.kOrder() == k);
        BOOST_REQUIRE(randwriter.freq("gg") == 3);
        BOOST_REQUIRE(randwriter.freq("ga", 'g') == 4);

        std::cout << "Testing kRand function" << std::endl;
        char rand = randwriter.kRand("aa");
        BOOST_REQUIRE(rand == 'a' || rand == 'g');

        std::cout << "Testing generate function" << std::endl << std::endl;
        BOOST_REQUIRE(randwriter.generate("ga", 10).length() == 10);
}

BOOST_AUTO_TEST_CASE(exception_test) {
    std::cout << " Test Case 2 " <<
    std::endl;
    std::cout << "Testing construction exception: RandWriter('ADF', 4)" <<
    std::endl;

    BOOST_REQUIRE_THROW(RandWriter("ADF", 4), std::invalid_argument);

    std::cout << "Testing function exceptions" << std::endl;
    RandWriter testMtable("abc", 3);
    BOOST_REQUIRE_THROW(testMtable.freq("a"), std::runtime_error);
    BOOST_REQUIRE_THROW(testMtable.freq("ab", 'b'), std::runtime_error);
    BOOST_REQUIRE_THROW(testMtable.kRand("g"), std::runtime_error);
}
