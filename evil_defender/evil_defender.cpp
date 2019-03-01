#include <iostream>
#include <fstream>
#include <vector>

namespace defender {

typedef struct {
    std::string tag;
    int times;
} EvilStruct;

typedef std::vector<EvilStruct> EvilList;

class EvilCounter{
    public:
        EvilCounter(const std::string data_loc)
            :_data_loc(data_loc) {}
        ~EvilCounter() {}
        const bool init() {
            read_file();
            return true;
        }
        void run() {
            std::string cmd_str;
            log_status();
            while (std::getline(std::cin, cmd_str)) {
                if (cmd_str == _quit_str) {
                    break;
                }
                dealt_cmd(cmd_str);
                log_status();
            }
        }
    private:
        void log_status() {
            read_file();
            std::cout << "=================="
                << std::endl;
            for (EvilList::const_iterator it = _evil_list.begin();
                    it != _evil_list.end();
                    ++it) {
                std::cout << it->tag
                    << "    "
                    << it->times
                    << std::endl;
            }
            std::cout << "please enter cmd, enter \""
                << _quit_str
                << "\" to quit"
                << std::endl;
        }

        void dealt_cmd(const std::string& cmd_str) {
            std::cout << "============="
                << std::endl;
            EvilStruct* evil_struct_ptr;
            EvilList::iterator it;
            bool found(false);
            for (it = _evil_list.begin();
                    it != _evil_list.end();
                    ++it) {
                if (it->tag == cmd_str) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                EvilStruct evil_struct;
                evil_struct_ptr = &evil_struct;
                evil_struct_ptr->tag = cmd_str;
                evil_struct_ptr->times = 1;
                _evil_list.push_back(evil_struct);
            } else {
                it->times++;
            }
            write_file();
        }
        void read_file(){
            _evil_list.clear();
            std::ifstream file;
            file.open(_data_loc);
            std::string line;
            while (std::getline(file, line)) {
                std::string tag = line.substr(0, line.find(" "));
                std::string times_str = line.substr(line.find(" ") + 1);
                EvilList::iterator it;
                bool found(false);
                for (it = _evil_list.begin();
                        it != _evil_list.end();
                        ++it) {
                    if (it->tag == tag) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    EvilStruct evil_struct;
                    evil_struct.tag = tag;
                    evil_struct.times = std::stoi(times_str);
                    _evil_list.push_back(evil_struct);
                } else {
                    it->times += std::stoi(times_str);
                }
            }
        }
        void write_file(){
            std::ofstream file(_data_loc);
            for (EvilList::const_iterator it = _evil_list.begin();
                    it != _evil_list.end();
                    ++it) {
                file << it->tag
                    << " "
                    << it->times
                    << std::endl;
            }
            file.close();
        }
    private:
        EvilList _evil_list;
        const std::string _data_loc;
        const std::string _quit_str = "quit";
};

} // namespace defender

int main() {
    std::cout << "init evil defender" << std::endl;
    defender::EvilCounter evil_counter("data/defender.txt");
    evil_counter.run();
    return 0;
}
