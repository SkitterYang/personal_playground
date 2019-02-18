#include "playground.h"
#include "../ywy/log.h"

#include <sstream>
#include <iostream>
#include <ctime>

namespace playground {
    int DateTime::trans_idx() {
        std::stringstream log_ss;
        log_ss.str("");
        LOG("NOTICE", "trans_idx");
        int32_t idx(0);
        for (idx = 0; idx <= 1440; idx++) {
            log_ss.str("");
            log_ss << idx << " : " 
                << trans_idx_by_time(idx);
            LOG("NOTICE", log_ss.str().c_str());
        }
        return 0;
    }

    int64_t DateTime::trans_idx_by_time(int32_t idx) {
        int64_t ret(0);
        int minute = idx % 60;
        int hour = idx / 60;
        ret += minute +
            hour * 100;
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        int32_t now_idx = now->tm_min + 
            now->tm_hour * 60;
        while (now_idx != idx) {
            t -= 60;
            now = std::localtime(&t);
            now_idx = now->tm_min + 
                now->tm_hour * 60;
        }
        ret += (now->tm_year + 1900) * 1E8 +
            now->tm_mon * 1E6 + 
            now->tm_mday * 1E4;
        return ret;
    }

} // namespace playground
