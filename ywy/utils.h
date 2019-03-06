#include <sys/time.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>

namespace ywy {
    // const variables 
    static const std::string BASE64RANGE =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"\
        "abcdefghijklmnopqrstuvwxyz0123456789+/";
    static const double PI = 3.14159265358979323846;

    // function declaration
    const uint64_t usecond();
    const int basic_rand(const int& min = 1,
            const int& max = 10);
    const int sin_rand(const int& min = 1,
            const int& max = 10);
    const std::string random_str();
    const std::string random_str_list(const int& length = 10,
            const std::string& seperator = ",");
    const uint64_t xorshf96(void);
    const uint64_t seed_generator(void);

    // function implement
    const uint64_t usecond() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return uint64_t(tv.tv_sec*1E6+tv.tv_usec);
    }

    const int basic_rand(const int& min,
            const int& max) {
        srand(seed_generator());
        int base_rand = rand() % (max - min) + min;
        return base_rand;
    }

    const int sin_rand(const int& min,
            const int& max) {
        int base_rand = basic_rand(min, max);
        double theta = (base_rand - min) * PI / (max - min);
        double sin_value = sin(theta);
        int result = min + (max - min) * sin_value;
        return result;
    }

    const std::string random_str(){
        std::string str;
        int size = sin_rand(6, 18);
        for (int i = 0; i < size; ++i) {
            str += BASE64RANGE.substr(
                    sin_rand(0, BASE64RANGE.size() -1), 1);
        }
        return str;
    }

    const std::string random_str_list(const int& length,
            const std::string& seperator) {
        std::string str;
        str += random_str();
        for (int i = 1; i < length; ++i) {
            str += seperator + random_str();
        }
        return str;
    }

    static unsigned long seed_generator_x=123456789,
                         seed_generator_y=362436069,
                         seed_generator_z=521288629;
    const uint64_t xorshf96(void) {          //period 2^96-1
        unsigned long t;
        seed_generator_x ^= seed_generator_x << 16;
        seed_generator_x ^= seed_generator_x >> 5;
        seed_generator_x ^= seed_generator_x << 1;
        
        t = seed_generator_x;
        seed_generator_x = seed_generator_y;
        seed_generator_y = seed_generator_z;
        seed_generator_z = t ^ seed_generator_x ^ seed_generator_y;
        
        return seed_generator_z;
    }

    const uint64_t seed_generator(void) {
        return usecond() + xorshf96();
    }
}
