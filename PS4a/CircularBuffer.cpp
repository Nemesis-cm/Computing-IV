// copyright 2021 Thomas Freeman
#include "CircularBuffer.hpp"

// List of constructors
CircularBuffer::CircularBuffer(int capacity) {
    if (capacity < 1) {
        throw std::invalid_argument(" Capacity must be be greater than zero.");
    }
    _capacity = capacity;
    _size = 0;
    _first = 0;
    _last = 0;
    _buffer = new int16_t[capacity];
}

CircularBuffer::CircularBuffer(const CircularBuffer& copyCB) {
    _capacity = copyCB._capacity;
    if (_capacity > 0) {
        _size = copyCB._size;
        _first = copyCB._first;
        _last = copyCB._last;
        _buffer = new int16_t[_capacity];
        for (int i = 0; i < _size; i++) {
            _buffer[i] = copyCB._buffer[i];
        }
    } else {
        _size = 0;
        _first = 0;
        _last = 0;
        _buffer = nullptr;
    }
}

CircularBuffer::CircularBuffer(CircularBuffer&& moveCB) noexcept {
    _capacity = moveCB._capacity;
    _size = moveCB._size;
    _first = moveCB._first;
    _last = moveCB._last;
    _buffer = moveCB._buffer;
    moveCB._capacity = 0;
    moveCB._size = 0;
    moveCB._first = 0;
    moveCB._last = 0;
    moveCB._buffer = nullptr;
}

CircularBuffer::~CircularBuffer() {
    if (_buffer != nullptr) { delete[] _buffer; }
    _capacity = 0;
    _size = 0;
    _first = 0;
    _last = 0;
    _buffer = nullptr;
}

// main functions in circular buffer

int CircularBuffer::size() const { return _size; }
bool CircularBuffer::isEmpty() const { return _size == 0; }
bool CircularBuffer::isFull() const { return _size == _capacity; }

void CircularBuffer::enqueue(int16_t x) {
    if (isFull()) {
        throw std::runtime_error("enqueue: can't enqueue to a full ring.");
    }
    // we add an item to the buffer then increment
    _buffer[_last] = x;
    _last++;
    if (_last == _capacity) { _last = 0; }
    _size++;
}

int16_t CircularBuffer::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("dequeue: can't dequeue from an empty ring.");
    }
    // return the first item then index the new first item
    int16_t result = _buffer[_first];
    _first++;
    if (_first == _capacity) { _first = 0; }
    _size--;
    return result;
}

// peek exception runs, returns first item after
int16_t CircularBuffer::peek() {
    if (isEmpty()) {
        throw std::runtime_error("peek: can't peek from an empty ring.");
    }
    return _buffer[_first];
}

void CircularBuffer::empty() {
    _size = 0;
    _first = 0;
    _last = 0;
}

/** overloaded assignment operators **/
CircularBuffer& CircularBuffer::operator=(const CircularBuffer& rightSide) {
    if (this == &rightSide) { return *this; }
    if (_buffer != nullptr) { delete[] _buffer; }

    _capacity = rightSide._capacity;
    if (_capacity > 0) {
        _size = rightSide._size;
        _first = rightSide._first;
        _last = rightSide._last;
        _buffer = new int16_t[_capacity];
        for (int i = 0; i < _size; i++) {
            _buffer[i] = rightSide._buffer[i];
        }
    } else {
        _size = 0;
        _first = 0;
        _last = 0;
        _buffer = nullptr;
    }

    return *this;
}

CircularBuffer& CircularBuffer::operator=(CircularBuffer&& rvalue) noexcept {
    if (this == &rvalue) { return *this; }
    if (_buffer != nullptr) { delete[] _buffer; }

    _capacity = rvalue._capacity;
    _size = rvalue._size;
    _first = rvalue._first;
    _last = rvalue._last;
    _buffer = rvalue._buffer;
    rvalue._capacity = 0;
    rvalue._size = 0;
    rvalue._first = 0;
    rvalue._last = 0;
    rvalue._buffer = nullptr;

    return *this;
}
