// Copyright 2021 Thomas Freeman

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <boost/regex.hpp>
#include <boost/date_time.hpp>

// boost libraries for regular expression
using boost::regex;
using boost::regex_search;
using boost::smatch;
using boost::posix_time::ptime;
using boost::posix_time::time_duration;
using boost::posix_time::time_from_string;

int main(int argc, char* argv[]) {
    int lineNum = 1, bootStartCount = 0, bootCompleteCount = 0;
    bool bootStarted = false;
    const std::string bootStartMsg = "(log.c.166) server started";
    const std::string bootCompleteMsg = "oejs.AbstractConnector:Started "
    "SelectChannelConnector@0.0.0.0:9080";

        // this regular expressions captures the date and time
        std::string s;
        std::string fileName;
        std::ifstream inputFile;
        std::ofstream outputFile;
        regex e("^\\d{4}[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]"
        "|3[01])\\s\\d{2}[:]\\d{2}[:]\\d{2}");
        smatch m;
        // t1 and t2 determine start and complete times
        ptime t1, t2;

    if (argc != 2) {
        std::cerr << "Usage: ./ps7 device1_intouch.log" << std::endl;
        return -1;
    }

    // setup file I/O
    inputFile.open(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open file: " << argv[1] << std::endl;
        return -1;
    }
    s = fileName = argv[1];
    outputFile.open(s.append(".rpt.tmp"));
    fileName = fileName.substr(fileName.find_last_of("\\/") + 1);

    // scans boot info from log file, transfers info to report file.
    while (std::getline(inputFile, s)) {
        if (bootStarted) {
            if (s.find(bootCompleteMsg) != std::string::npos) {
                // device boot completes
                regex_search(s, m, e);
                // we then get the date and time
                t2 = ptime(time_from_string(m[0]));
                // and total boot time
                time_duration td = t2 - t1;
                outputFile << lineNum << "(" << fileName << ") " << m[0]
                << " Boot Completed" << std::endl
                << "\tBoot Time: " << td.total_milliseconds() << "ms"
                << std::endl << std::endl;
                bootStarted = false;
                bootCompleteCount++;
            } else if (s.find(bootStartMsg) != std::string::npos) {
                // boot start reports after unsuccessful boot
                regex_search(s, m, e);
                t1 = ptime(time_from_string(m[0]));
                outputFile << " Incomplete boot" << std::endl <<
                std::endl
                << " Device boot" << std::endl
                << lineNum << "(" << fileName << ") " << m[0]
                << " Boot Start" << std::endl;
                bootStartCount++;
            }
        } else if (s.find(bootStartMsg) != std::string::npos) {
            // boot start reports again
            regex_search(s, m, e);
            t1 = ptime(time_from_string(m[0]));
            outputFile << "=== Device boot ===" << std::endl
            << lineNum << "(" << fileName << ") " << m[0]
            << " Boot Start" << std::endl;
            bootStarted = true;
            bootStartCount++;
        }
        lineNum++;
    }
    inputFile.close();
    outputFile.close();

    // add .rpt and .tmp to report file
    s = argv[1];
    s.append(".rpt");
    outputFile.open(s);

    s.append(".tmp");
    inputFile.open(s);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open file: " << s << std::endl;
        return -1;
    }

    outputFile << "Device Boot Report" << std::endl << std::endl
    << "InTouch log file: " << fileName << std::endl
    << "Lines Scanned: " << lineNum - 1 << std::endl << std::endl
    << "Device boot count: initiated: " << bootStartCount << ", completed: "
    << bootCompleteCount << std::endl << std::endl << std::endl;

    outputFile << inputFile.rdbuf();    // copies the data

    inputFile.close();
    outputFile.close();

    // removes the temp file
    if (std::remove(s.c_str()) != 0) {
        std::cerr << "Error deleting temp file: " << s << std::endl;
        return -1;
    }

    return 0;
}
