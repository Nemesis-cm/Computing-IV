// copyright 2021 Thomas Freeman

#include "RandWriter.h"
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./TextWriter k L < input.txt" << std::endl;
        exit(-1);
    }
    int k = std::atoi(argv[1]);
    int L = std::atoi(argv[2]);

    int count = 0;
    int length = 0;
    std::string input;
    std::string output;

    // reads line by line of the input and generates
    // characters pseudorandomly
    while (std::getline(std::cin, input) && count < L) {
        if (input.length() > static_cast<unsigned int>(k)) {
            try {
                RandWriter randwriter(input, k);
                if (static_cast<int>(input.length()) > L) {
                    length = L;
                } else if (static_cast<int>(input.length()) + count > L) {
                    length = L - count;
                } else {
                    length = input.length();
                }
                output = randwriter.generate(input.substr(0, k), length);
                count += output.length();
                std::cout << output << std::endl;
            }
            catch (std::invalid_argument err) {
                std::cerr << err.what() << std::endl;
                exit(-1);
            }
            catch (std::runtime_error err) {
                std::cerr << err.what() << std::endl;
                exit(-1);
            }
        }
    }

    return 0;
}
