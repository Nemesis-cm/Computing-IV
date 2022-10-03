// Copyright 2021 Thomas Freeman

#include "CircularBuffer.hpp"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

// Initial test for Circular Buffer
BOOST_AUTO_TEST_CASE(functions_test) {
    std::cout << "\nMember Function Test " << std::endl;
    std::cout << "Testing construction of CircularBuffer(4)" << std::endl;
    BOOST_REQUIRE_NO_THROW(CircularBuffer(4));

    // Enqueue testing
    std::cout << "Testing enqueue() for CircularBuffer(4)" << std::endl;
    CircularBuffer cb(4);
    BOOST_REQUIRE_NO_THROW(cb.enqueue(1));
    BOOST_REQUIRE_NO_THROW(cb.enqueue(2));
    BOOST_REQUIRE_NO_THROW(cb.enqueue(3));
    BOOST_REQUIRE_NO_THROW(cb.enqueue(4));
    std::cout << "CircularBuffer(4) is full: " << std::boolalpha <<
    cb.isFull() << std::endl;

    // Dequeue testing
    std::cout << "Testing dequeue() for CircularBuffer(4)" << std::endl;
    BOOST_REQUIRE_NO_THROW(cb.dequeue());
    BOOST_REQUIRE_NO_THROW(cb.dequeue());
    BOOST_REQUIRE_NO_THROW(cb.dequeue());
    BOOST_REQUIRE_NO_THROW(cb.dequeue());
    std::cout << "CircularBuffer(4) is empty: " << std::boolalpha <<
    cb.isEmpty() << std::endl << std::endl;
}

// Exception test for capacity
BOOST_AUTO_TEST_CASE(excpetion_test1) {
    std::cout << "Exception Test 1: " <<
    std::endl << "Testing CircularBuffer(0) throws std::invalid_argument" <<
    std::endl << std::endl;
    BOOST_REQUIRE_THROW(CircularBuffer cb1(0), std::invalid_argument);
}

// Enqueue test exception for adding the full buffer
BOOST_AUTO_TEST_CASE(excpetion_test2) {
    std::cout << "Exception Test 2: " <<
    std::endl << "Testing if full then enqueue() throws std::runtime_error"
    << std::endl << std::endl;
    CircularBuffer cb2(4);
    cb2.enqueue(1);
    cb2.enqueue(2);
    cb2.enqueue(3);
    cb2.enqueue(4);
    BOOST_REQUIRE_THROW(cb2.enqueue(5), std::runtime_error);
}

// Tests the dequeue exception for dequeueing an empty buffer.
BOOST_AUTO_TEST_CASE(exception_test3) {
    std::cout << "Exception Test 3: " <<
    std::endl << "Testing if empty then peek() and dequeue() throw "
    "std::runtime_error" << std::endl;
    CircularBuffer cb3(1);
    BOOST_REQUIRE_THROW(cb3.peek(), std::runtime_error);
    BOOST_REQUIRE_THROW(cb3.dequeue(), std::runtime_error);
}
