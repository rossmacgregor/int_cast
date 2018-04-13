//
//          Copyright Ross MacGregor 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
#include <limits>
#include <assert.h>
#include <stdint.h>

#include "int_cast.h"

#define ASSERT assert

#define THROWS(statement) \
    try { statement; assert(false); } catch (std::exception &e) { }

int main(int, char *[])
{
    using namespace std;

    int16_t i16_min= numeric_limits<int16_t>::min();
    int16_t i16_neg = -777;
    int16_t i16_zer = 0;
    int16_t i16_pos = 777;
    int16_t i16_max = numeric_limits<int16_t>::max();

    uint16_t u16_zer= 0;
    uint16_t u16_pos = 777;
    uint16_t u16_max = numeric_limits<uint16_t>::max();

    int32_t i32_min = numeric_limits<int32_t>::min();
    int32_t i32_neg = -777;
    int32_t i32_zer = 0;
    int32_t i32_pos = 777;
    int32_t i32_max = numeric_limits<int32_t>::max();

    uint32_t u32_zer= 0;
    uint32_t u32_pos = 777;
    uint32_t u32_max = numeric_limits<uint32_t>::max();

    int64_t i64_min = numeric_limits<int64_t>::min();
    int64_t i64_neg = -777;
    int64_t i64_zer = 0;
    int64_t i64_pos = 777;
    int64_t i64_max = numeric_limits<int64_t>::max();

    uint64_t u64_zer= 0;
    uint64_t u64_pos = 777;
    uint64_t u64_max = numeric_limits<uint64_t>::max();


    // test int16_t
    //
    ASSERT(int_cast<int16_t>(i16_min) == i16_min);
    ASSERT(int_cast<int16_t>(i16_neg) == i16_neg);
    ASSERT(int_cast<int16_t>(i16_zer) == i16_zer);
    ASSERT(int_cast<int16_t>(i16_pos) == i16_pos);
    ASSERT(int_cast<int16_t>(i16_max) == i16_max);

    ASSERT(int_cast<int16_t>(u16_zer) == i16_zer);
    ASSERT(int_cast<int16_t>(u16_pos) == i16_pos);
    THROWS(int_cast<int16_t>(u16_max));

    THROWS(int_cast<int16_t>(i32_min));
    ASSERT(int_cast<int16_t>(i32_neg) == i16_neg);
    ASSERT(int_cast<int16_t>(i32_zer) == i16_zer);
    ASSERT(int_cast<int16_t>(i32_pos) == i16_pos);
    THROWS(int_cast<int16_t>(i32_max));

    ASSERT(int_cast<int16_t>(u32_zer) == i16_zer);
    ASSERT(int_cast<int16_t>(u32_pos) == i16_pos);
    THROWS(int_cast<int16_t>(u32_max));

    // test uint16_t
    //
    THROWS(int_cast<uint16_t>(i16_min));
    THROWS(int_cast<uint16_t>(i16_neg));
    ASSERT(int_cast<uint16_t>(i16_zer) == u16_zer);
    ASSERT(int_cast<uint16_t>(i16_pos) == u16_pos);
    ASSERT(int_cast<uint16_t>(i16_max) == static_cast<uint16_t>(i16_max));

    ASSERT(int_cast<uint16_t>(u16_zer) == u16_zer);
    ASSERT(int_cast<uint16_t>(u16_pos) == u16_pos);
    ASSERT(int_cast<uint16_t>(u16_max) == u16_max);

    THROWS(int_cast<uint16_t>(i32_min));
    THROWS(int_cast<uint16_t>(i32_neg));
    ASSERT(int_cast<uint16_t>(i32_zer) == u16_zer);
    ASSERT(int_cast<uint16_t>(i32_pos) == u16_pos);
    THROWS(int_cast<uint16_t>(i32_max));

    ASSERT(int_cast<uint16_t>(u32_zer) == u16_zer);
    ASSERT(int_cast<uint16_t>(u32_pos) == u16_pos);
    THROWS(int_cast<uint16_t>(u32_max));

    // test int64_t
    //
    ASSERT(int_cast<int64_t>(i32_min) == i32_min);
    ASSERT(int_cast<int64_t>(i32_neg) == i32_neg);
    ASSERT(int_cast<int64_t>(i32_zer) == i32_zer);
    ASSERT(int_cast<int64_t>(i32_pos) == i32_pos);
    ASSERT(int_cast<int64_t>(i32_max) == i32_max);

    ASSERT(int_cast<int64_t>(u32_zer) == i64_zer);
    ASSERT(int_cast<int64_t>(u32_pos) == i64_pos);
    ASSERT(int_cast<int64_t>(u32_max) == static_cast<int64_t>(u32_max));

    ASSERT(int_cast<int64_t>(i64_min) == i64_min);
    ASSERT(int_cast<int64_t>(i64_neg) == i64_neg);
    ASSERT(int_cast<int64_t>(i64_zer) == i64_zer);
    ASSERT(int_cast<int64_t>(i64_pos) == i64_pos);
    ASSERT(int_cast<int64_t>(i64_max) == i64_max);

    ASSERT(int_cast<int64_t>(u64_zer) == i64_zer);
    ASSERT(int_cast<int64_t>(u64_pos) == i64_pos);
    THROWS(int_cast<int64_t>(u64_max));

    // test uint64_t
    //
    THROWS(int_cast<uint64_t>(i32_min));
    THROWS(int_cast<uint64_t>(i32_neg));
    ASSERT(int_cast<uint64_t>(i32_zer) == u64_zer);
    ASSERT(int_cast<uint64_t>(i32_pos) == u64_pos);
    ASSERT(int_cast<uint64_t>(i32_max) == static_cast<uint64_t>(i32_max));

    ASSERT(int_cast<uint64_t>(u32_zer) == u64_zer);
    ASSERT(int_cast<uint64_t>(u32_pos) == u64_pos);
    ASSERT(int_cast<uint64_t>(u32_max) == static_cast<uint64_t>(u32_max));

    THROWS(int_cast<uint64_t>(i64_min));
    THROWS(int_cast<uint64_t>(i64_neg));
    ASSERT(int_cast<uint64_t>(i64_zer) == u64_zer);
    ASSERT(int_cast<uint64_t>(i64_pos) == u64_pos);
    ASSERT(int_cast<uint64_t>(i64_max) == static_cast<uint64_t>(i64_max));

    ASSERT(int_cast<uint64_t>(u64_zer) == u64_zer);
    ASSERT(int_cast<uint64_t>(u64_pos) == u64_pos);
    ASSERT(int_cast<uint64_t>(u64_max));

    return 0;
}
