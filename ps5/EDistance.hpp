// copyright 2021 Thomas Freeman

#ifndef EDistance_HPP    //NOLINT
#define EDistance_HPP    //NOLINT

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class EDistance {
 public:
    EDistance();

    // edit distance is made from two strings
    EDistance(std::string x, std::string y);

    // penalties for char's in strings x and y
    static int penalty(char a, char b);

    // returns minimum value of a,b,c
    static int min(int a, int b, int c);

    // fills the matrix
    int optDistance();

    // traces the matrix, returns alignment
    std::string alignment();

    // overload stream operator
    friend std::istream& operator>>(std::istream& in, EDistance& ed);

 private:
    // M is for string x, N for string y
    int M;
    int N;
    std::string _x, _y;

    // measures the sequence alignment
    std::vector<std::vector<int> > opt;
};
#endif  //NOLINT
