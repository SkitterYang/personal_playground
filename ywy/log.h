#ifndef YWY_LOG_H
#define YWY_LOG_H

#include <stdint.h>
#include <sys/time.h>

#include <stdio.h>
#include <string>
#include <iostream>

#define LOG(type, str) fprintf(stderr, "%s line %d %s: [%s] %s\n", __FILE__, __LINE__, __func__, type, str)

uint64_t usecond();

namespace ywy {
    class logger{
        logger(){}
        ~logger(){}
    };
}

#endif // YWY_LOG_H
