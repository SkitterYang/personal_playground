#include <iostream>

#include <sstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <map>
#include <queue>

#include "ywy/utils.h"

template<typename T>
struct ClassNameHelper {
    T name;
};

class ConfType {
    std::string _conf_string;
    std::vector<std::string> _conf_vector;
public:
    ConfType(){}
    ~ConfType(){}
    const bool init(const std::string& conf_string){
        _conf_string = conf_string;
        _conf_vector.clear();
        int begin_idx = 0;
        int end_idx = conf_string.find_first_of(',');
        while (end_idx != std::string::npos) {
            _conf_vector.push_back(conf_string.substr(begin_idx, end_idx));
            begin_idx += end_idx + 1;
            end_idx = (conf_string.substr(begin_idx, conf_string.size())).find_first_of(',');
        }
        _conf_vector.push_back(conf_string.substr(begin_idx));
        log_self();
        return true;
    }

    void log_self(){
        std::cout << "conf_string: "
            << std::endl
            << _conf_string
            << std::endl;
        std::cout << "conf_vector: "
            << std::endl;
        for (std::vector<std::string>::const_iterator it = _conf_vector.begin();
                it != _conf_vector.end();
                ++it) {
            std::cout << *it
                << std::endl;
        }
    }

    void search_str(const std::string& str) {
        std::cout << "------" << std::endl;
        std::cout << "search: " << str << std::endl;
        std::cout << "string conf" << std::endl;
        uint64_t begin_t;
        uint64_t end_t;
        begin_t = ywy::usecond();
        if (_conf_string.find(str) != std::string::npos) {
            std::cout << "success " << std::endl;
        }
        else {
            std::cout << "fail" << std::endl;
        }
        end_t = ywy::usecond();
        std::cout << "time: " << end_t - begin_t << std::endl;
        std::cout << "vector conf" << std::endl;
        begin_t = ywy::usecond();
        bool success(false);
        for (std::vector<std::string>::const_iterator it = _conf_vector.begin();
                it != _conf_vector.end();
                ++it) {
            if (*it == str) {
                std::cout << "success" << std::endl;
                success = true;
                break;
            }
        }
        if (!success) {
            std::cout << "fail" << std::endl;
        }
        end_t = ywy::usecond();
        std::cout << "time: " << end_t - begin_t << std::endl;
        std::cout << "------" << std::endl;
    }

    void test() {
        std::string manul_str = "carnet,lalala,hahhahahwheo,hasdo";
        std::string test_str = ywy::random_str_list(10) +
            manul_str;
        init(test_str);
        search_str("carnet");
        search_str("hasdo");
        search_str("hadasdo");
    }
};

class QueueTest{
    public:
    QueueTest(){}
    ~QueueTest(){}
    void test(){
        std::queue<int*> testqueue;
        int* i = new int();
        *i = 100;
        testqueue.push(i);
        int* j;
        j = testqueue.front();
        if (j == NULL){
            std::cout << "j is NULL"
                << std::endl;
        } else {
            std::cout << "j is:"
                << *j
                << std::endl;
        }
    }
};

bool vaild_coord(const char *str){
    std::cout << str << std::endl;
    if (strncmp(str, "wgs84", 5) != 0 and strncmp(str, "bd09", 4) != 0){
        std::cout << "step 1 false" << std::endl;
        return false;
    }
    int len = strlen(str);
	if (strcmp(str + len - 2, "ll") != 0 and strcmp(str + len - 2, "mc") != 0) {
        std::cout << "step 2 false" << std::endl;
        return false;
    }
    return true;
}

int main() {
    struct ClassNameHelper<std::string> test;

    std::cout << "test start" << std::endl;
    std::string teststr = "wgs84ll";
    if (vaild_coord(teststr.c_str())){
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
    std::cout << std::endl;
    int testint = 0;
    if (not testint) {
        std::cout << "not -1" << std::endl;
    }
    std::cout << "test finish" << std::endl;

    ConfType conftype;
    // conftype.test();

    QueueTest queuetest;
    queuetest.test();
    return 0;
}
