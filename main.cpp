#include <iostream>

#include "ywy/log.h"
#include "leetcode/leetcode.h"
#include "playground/playground.h"

#include <sstream>
#include <iostream>
#include <string>

// #include <glog/logging.h>

int main() {
    std::stringstream logss;
    logss.str("");

    std::string teststr("1:3;23:2");
    if (teststr.find("sadf") == std::string::npos) {
        std::cout << "not found" << std::endl;
    }
    std::cout << teststr.find(",") << std::endl;
    // LOG(INFO) << "test Glog";
    return 0;
}
