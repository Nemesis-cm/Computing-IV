// copyright 2021 Thomas Freeman
#include "RandWriter.h"

RandWriter::RandWriter(std::string text, int k) {
    _text = text;
    _k = k;

    if (_text.length() < static_cast<unsigned int>(_k)) {
        throw std::invalid_argument("RandWriter(string text, int k): order k"
        " must be less than or equal to text length.");
    }

    // Markov table
    unsigned int pos = 0;
    for (unsigned int i = 0; i < _text.length(); i++) {
        std::string k_gram;
        std::map<char, int> f_table;
        // maps corresponding char to its frequency

        // parses the kgrams text and gets characters
        for (unsigned int j = i; j < i + _k; j++) {
            if (j >= _text.length()) {
                pos = j - _text.length();
            } else {
                pos = j;
            }
            k_gram += _text.at(pos);
        }

        // sets up next freq table
        pos++;
        if (pos >= _text.length()) { pos -= _text.length(); }
        f_table.insert(std::make_pair(_text.at(pos), 0));

        // k_gram and frequency tables are put into the map
        if (mtable.count(k_gram) == 0) {
            mtable.insert(std::make_pair(k_gram, f_table));
        }

        // update next char in freq table
        mtable[k_gram][_text.at(pos)]++;
    }
}

int RandWriter::kOrder() const { return _k; }
std::string RandWriter::getText() const { return _text; }
std::map<std::string, std::map<char, int>> RandWriter::getMTable() const {
    return mtable;
}

int RandWriter::freq(std::string k_gram) const {
    if (k_gram.length() < static_cast<unsigned int>(_k)) {
        throw std::runtime_error("freq(string k_gram): k_gram must be of"
        " length greater than or equal to order k.");
    }
    int count = 0;
    for (unsigned int i = 0; i < _text.length(); i++) {
        unsigned int pos = 0;
        std::string kg;
        // parse input text for kgrams
        for (unsigned int j = i; j < i + _k; j++) {
            // get characters for kgrams
            if (j >= _text.length()) {
                pos = j - _text.length();
            } else {
                pos = j;
            }
            kg += _text.at(pos);
        }
        if (k_gram == kg) { count++; }
    }
    return count;
}

int RandWriter::freq(std::string k_gram, char c) const {
    if (k_gram.length() < static_cast<unsigned int>(_k)) {
        throw std::runtime_error("freq(string k_gram, char c): k_gram must be"
        " of length greater than or equal to order k.");
    }
    return mtable.at(k_gram).at(c);
}

// exceptions for k_gram
char RandWriter::kRand(std::string k_gram) const {
    if (k_gram.length() < static_cast<unsigned int>(_k)) {
        throw std::runtime_error("kRand(string k_gram): k_gram must be of"
        " length greater than or equal to order k.");
    }
    if (mtable.count(k_gram) == 0) {
        throw std::runtime_error("kRand(string k_gram): k_gram does not"
        " exist.");
    }
    // next chars stored as a string
    std::string alphabet;
    for (auto const &var1 : mtable) {
        if (var1.first == k_gram) {
            for (auto const &var2 : var1.second) {
                alphabet += var2.first;
            }
        }
    }
    std::random_device device;
    std::mt19937 mt_rand(device());
    std::uniform_int_distribution<int> distribution(0, alphabet.length()
    - 1);

    return alphabet[distribution(mt_rand)];
}

std::string RandWriter::generate(std::string k_gram, int L) const {
    if (k_gram.length() < static_cast<unsigned int>(_k)) {
        throw std::runtime_error("generate(string k_gram, int L): k_gram must"
        " be of length greater than or equal to order k.");
    }
    std::string generated = k_gram;
    // new characters generated based on k_gram
    for (int i = _k; i < L; i++) {
        generated += kRand(generated.substr(i - _k, _k));
    }
    return generated;
}

std::ostream& operator<<(std::ostream& out, const RandWriter& randwriter) {
    out << "Markov Model\tOrder: " << randwriter._k << std::endl;
    out << "k_gram:\tfrequency:\tfrqncy of next char:\tprob of next char:" <<
    std::endl;

    for (auto const &var1 : randwriter.mtable) {
        // var1.first = k_gram
        out << var1.first << "\t";
        out << randwriter.freq(var1.first) << "\t\t";
        for (auto const &var2 : var1.second) {
        // var2.first = next char
        // var2.second = data
            out << var2.first << ":" << var2.second << " ";
        }
        out << "\t\t\t";
        for (auto const &var2 : var1.second) {
            out << var2.first << ":" << var2.second << "/" <<
            randwriter.freq(var1.first) << " ";
        }
        out << std::endl;
    }
    return out;
}
