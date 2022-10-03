// Copyright 2021 Thomas Freeman

#ifndef STRINGSOUND_HPP   //NOLINT
#define STRINGSOUND_HPP  //NOLINT

#include <math.h>
#include <vector>
#include <string>
#include <random>
#include <SFML/Audio/SoundBuffer.hpp>
#include "CircularBuffer.hpp"

// sample rate is measured in hertz
#define SAMPLE_RATE 44100
#define DECAY_FACTOR 0.996

class StringSound {
 public:
    // default constructor
    StringSound();

    // creates stringSound at given frequency
    explicit StringSound(double frequency);

    // Vector gives initial string size and values from Int16
    explicit StringSound(std::vector<sf::Int16> init);

    StringSound(const StringSound& copySS);
    StringSound(StringSound&& moveSS) noexcept;
    ~StringSound();

    // pluck then replaces random values in the buffer
    // tic advances by one step, returning the sample
    // time returns the number of times tic executed
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();

    StringSound& operator=(const StringSound& rightSide);
    StringSound& operator=(StringSound&& rvalue) noexcept;

 private:
    CircularBuffer* _rb;
    int _time;
};
#endif  //NOLINT
