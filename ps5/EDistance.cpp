// Copyright 2021 Thomas Freeman

#include "EDistance.hpp"

EDistance::EDistance() : M(0), N(0) {}

EDistance::EDistance(std::string x, std::string y) {
    _x = x; _y = y;
    M = static_cast<int>(_x.length());
    N = static_cast<int>(_y.length());

    // initialize vector matrix of ints
    opt = std::vector<std::vector<int> >(M+2, std::vector<int>(N+2, 0));

    // base cases for M and N
    for (int i = M; i >= 0; i--) {
        opt[i][N+1] = opt[i+1][N+1] + 2;
    }
    for (int j = N; j >= 0; j--) {
        opt[M+1][j] = opt[M+1][j+1] + 2;
    }
}

// when both chars are the same return 0, else return 1
int EDistance::penalty(char a, char b) {
    if (a == b)
        return 0;
    else
        return 1;
}

// returns distance based on the minimum int
int EDistance::min(int a, int b, int c) {
    if (b < a && b < c)
        return b;
    if (c < a && c < b)
        return c;
    else
        return a;
}

int EDistance::optDistance() {
    // fill matrix with values
    for (int i = M; i >= 0; i--) {
        for (int j = N; j >= 0; j--) {
            opt[i][j] = min(opt[i+1][j+1] + penalty(_x[i], _y[j]),
            opt[i+1][j] + 2, opt[i][j+1] + 2);
        }
    }
    return opt[0][0];
}

std::string EDistance::alignment() {
    std::string result;

    if (M != 0 && N != 0) {
        // checks for empty string in M and N
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // tracing is done diagonaly
                if (opt[i][j] == opt[i + 1][j + 1] && _x[i] == _y[j]) {
                    result.push_back(_x[i]);
                    result.append(" ");
                    result.push_back(_y[j]);
                    result.append(" 0\n");
                    i++;
                } else if (opt[i][j] == opt[i + 1][j + 1] + 1) {
                    result.push_back(_x[i]);
                    result.append(" ");
                    result.push_back(_y[j]);
                    result.append(" 1\n");
                    i++;
                } else if (opt[i][j] == opt[i + 1][j] + 2) {
                    // move down
                    result.push_back(_x[i]);
                    result.append(" — 2\n");
                    i++;
                    j--;
                } else if (opt[i][j] == opt[i][j + 1] + 2) {
                    // move right
                    result.append("— ");
                    result.push_back(_y[j]);
                    result.append(" 2\n");
                }
            }
        }
    } else if (M != 0 && N == 0) {
        result.append("String y is empty, returning string x: ");
        result.append(_x);
        result.append("\n");
    } else if (M == 0 && N != 0) {
        result.append("String x is empty, returning string y: ");
        result.append(_y);
        result.append("\n");
    } else {
        result.append("No two strings provided\n");
    }
    return result;
}

std::istream& operator>>(std::istream& in, EDistance& ed) {
    std::string x;
    std::string y;

    in >> x;
    in >> y;
    ed = EDistance(x, y);

    return in;
}
