#include <iostream>

#include <sstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

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
};

int main() {
    struct ClassNameHelper<std::string> test;
    ConfType conftype;
    std::string manul_str = "carnet,lalala,hahhahahwheo,hasdo";
    std::string test_str = ywy::random_str_list(10000) +
        manul_str;
    conftype.init(test_str);
    conftype.search_str("carnet");
    conftype.search_str("hasdo");
    conftype.search_str("hadasdo");
    return 0;
}
