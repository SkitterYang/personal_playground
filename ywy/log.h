#ifndef YWY_LOG_H
#define YWY_LOG_H

#include <stdint.h>
#include <sys/time.h>

#include <stdio.h>
#include <string>

#define LOG(type, str) fprintf(stderr, "%s line %d: [%s] %s\n", __FILE__, __LINE__, type, str)

uint64_t usecond();

namespace ywy {
}

#endif // YWY_LOG_H
