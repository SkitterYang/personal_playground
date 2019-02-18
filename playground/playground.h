#ifndef PLAYGROUND_PLAYGROUND_H
#define PLAYGROUND_PLAYGROUND_H

#include <stdint.h>

namespace playground {
    
class DateTime {
public:
    DateTime() {}
    ~DateTime() {}

    int trans_idx();
    int64_t trans_idx_by_time(int32_t idx);
};

} // class DateTime

#endif // PLAYGROUND_PLAYGROUND_H
