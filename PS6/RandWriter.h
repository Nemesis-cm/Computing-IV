// copyright 2021 Thomas Freeman

#ifndef RANDWRITER_H  //NOLINT
#define RANDWRITER_H  //NOLINT

#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <utility>
#include <random>

class RandWriter {
 public:
    // creates markov model of order k based on the text file
    RandWriter(std::string text, int k);

    // returns Korder
    int kOrder() const;

    // returns input text
    std::string getText() const;

    // Returns the table map
    std::map<std::string, std::map<char, int>> getMTable() const;

    // returns the number of times K_gram occours in the text
    // throws exception if K_gram is not length K
    int freq(std::string k_gram) const;


    // returns how many times char c follows k_gram
    // throws exception if k_gram is not length K
    int freq(std::string k_gram, char c) const;


    // returns random character following k_gram
    // throws exception if k_gram is not length K
    // or if there's no k_gram
    char kRand(std::string k_gram) const;


    // generates string of length L by simulating the markov chain
    // first k characters of the new string are K_gram since L is close to K
    // throws exception otherwise
    std::string generate(std::string k_gram, int L) const;

    // overloaded stream insertion operator to show the models state
    friend std::ostream& operator<<(std::ostream& out, const RandWriter&
    randwriter);

 private:
    int _k;             // order of Markov Model
    std::string _text;  // text to analyze

    // map of k_gram to map of frequency of next char
    std::map<std::string, std::map<char, int>> mtable;
};
#endif   //NOLINT