#include <iostream>

#include "log.h"

uint64_t usecond()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return uint64_t(tv.tv_sec*1E6+tv.tv_usec);
}

namespace ywy{
}
