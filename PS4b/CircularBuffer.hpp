// copyright 2021 Thomas Freeman

#ifndef CIRCULARBUFFER_HPP   //NOLINT
#define CIRCULARBUFFER_HPP   //NOLINT

#include <stdint.h>
#include <iostream>
#include <exception>

class CircularBuffer {
 public:
    explicit CircularBuffer(int capacity);
    // ring buffer is made empty
    // with its own max capacity
    CircularBuffer(const CircularBuffer& copyCB);
    CircularBuffer(CircularBuffer&& moveCB) noexcept;
    ~CircularBuffer();

    int size() const;         // return elements in the buffer
    int capacity() const;     // return capacity of buffer
    bool isEmpty() const;     // checks if size = 0
    bool isFull() const;      // checks if size = capacity
    void enqueue(int16_t x);  // adds an item
    int16_t dequeue();        // deletes an item
    int16_t peek();           // returns the frontmost item
    void empty();             // set size to 0

    CircularBuffer& operator=(const CircularBuffer& rightSide);
    CircularBuffer& operator=(CircularBuffer&& rvalue) noexcept;

 private:
    int _size;
    int _capacity;
    int _first;
    int _last;
    int16_t* _buffer;
};
#endif  //NOLINT