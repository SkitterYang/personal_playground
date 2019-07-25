#include <iostream>
#include <glog/logging.h>

int main(int argc, char* argv[]){
    google::InitGoogleLogging(argv[0]);
    LOG(INFO) << "test";
    return 0;
}
