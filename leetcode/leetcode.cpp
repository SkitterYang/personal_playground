#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>

#include "leetcode.h"
#include "../ywy/log.h"

namespace leetcode {
    int UnitTester::test() {
        std::cout << "this is tester" << std::endl;
        return 0;
    }

    int UnitTester::shortestSubarraytest() {
        std::cout << "shortest Subarraytest begin" << std::endl;
        std::vector<std::pair<std::vector<int>, int> > testsamples;
        std::vector<std::pair<std::vector<int>, int> >::iterator testsamples_it;
        testsamples_it = testsamples.begin();
        std::pair<std::vector<int>, int> tmp_pair;

        tmp_pair.first = {1,2};
        tmp_pair.second = 1;
        testsamples.push_back(tmp_pair);

        tmp_pair.first = {2, -1,2};
        tmp_pair.second = 3;
        testsamples.push_back(tmp_pair);

        std::ifstream infile;
        std::string filename = "data/shortestSubarraytest.txt";
        infile.open(filename.c_str());
        if (!infile) {
            std::stringstream log_ss;
            log_ss << "failed to open file " << filename << " " << strerror(errno);
            LOG("ERROR", log_ss.str().c_str());
            log_ss.str("");
        } else if (infile.is_open()) {
            std::stringstream log_ss;
            log_ss << "loaded file " << filename;
            LOG("NOTICE", log_ss.str().c_str());
            log_ss.str("");
            std::string line;
            while (getline(infile, line)) {
                std::string delimiter = "\t";
                int loc = line.find(delimiter);
                std::cout << loc << std::endl;
                std::string token = line.substr(0, loc);
                std::cout << token << std::endl;
                token = line.substr(loc + 1, line.length() - 1);
            }
        }
        Solution solution;

        testsamples_it = testsamples.begin();
        while (testsamples_it != testsamples.end()) {
            std::stringstream log_ss;
            uint64_t start_t = usecond();
            solution.shortestSubarray(testsamples_it->first, testsamples_it->second);
            uint64_t end_t = usecond();
            log_ss << end_t - start_t << " us spent" << std::endl;
            LOG("NOTICE", log_ss.str().c_str());
            testsamples_it++;
        }
        return 0;
    }

    int Solution::shortestSubarray(std::vector<int>& A, int K) {
        LOG("NOTICE", "shortestSubarray begin");
        std::stringstream log_ss;

        log_ss << "Array: [";
        for (auto& a: A)
            log_ss << a << ' ';
        log_ss << "\b]";
        // LOG("NOTICE", log_ss.str().c_str());
        log_ss.str("");

        log_ss << "K: " << K;
        LOG("NOTICE", log_ss.str().c_str());
        log_ss.str("");

        // answer begin
        int sum = 0;
        int ret = -1;
        int len = 0;
        std::vector<int>::iterator for_it = A.begin();
        std::vector<int>::iterator end_it = A.begin();


        while (for_it != A.end()) {
            sum = 0;
            sum += *end_it;
            len += 1;
            end_it++;
            if (sum >= K) {
                if (ret == -1) {

                    log_ss << "start: " << *for_it << " end: " << *end_it
                        << " len: " << len << " sum: " << sum;
                    LOG("NOTICE", log_ss.str().c_str());
                    log_ss.str("");

                    ret = len;
                }
                if (ret > len) {
                    ret = len;

                    log_ss << "start: " << *for_it << " end: " << *end_it
                        << " len: " << len << " sum: " << sum;
                    LOG("NOTICE", log_ss.str().c_str());
                    log_ss.str("");
                }
            }
            while (sum > 0 and end_it != A.end() and sum < K) {
                sum += *end_it;
                len += 1;
                end_it++;
            }
            if (sum >= K) {
                if (ret == -1) {
                    ret = len;

                    log_ss << "start: " << *for_it << " end: " << *end_it
                        << " len: " << len << " sum: " << sum;
                    LOG("NOTICE", log_ss.str().c_str());
                    log_ss.str("");
                }
                if (ret > len) {
                    ret = len;

                    log_ss << "start: " << *for_it << " end: " << *end_it
                        << " len: " << len << " sum: " << sum;
                    LOG("NOTICE", log_ss.str().c_str());
                    log_ss.str("");
                }
            }
            for_it++;
            end_it = for_it;
            sum = 0;
            len = 0;
        }
        log_ss << "result: " << ret;
        LOG("NOTICE", log_ss.str().c_str());
        log_ss.str("");
        return ret;
    }
}
