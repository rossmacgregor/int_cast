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

#define THROWS(statement) \
    try { statement; assert(false); } catch (std::exception &e) { }

int main(int, char *[])
{
    using namespace std;

    int16_t s16_min= numeric_limits<int16_t>::min();
    int16_t s16_neg = -777;
    int16_t s16_zero = 0;
    int16_t s16_pos = 777;
    int16_t s16_max = numeric_limits<int16_t>::max();

    uint16_t u16_zero= 0;
    uint16_t u16_pos = 777;
    uint16_t u16_max = numeric_limits<uint16_t>::max();

    int32_t i32_min = numeric_limits<int32_t>::min();
    int32_t i32_neg = -777;
    int32_t i32_zero = 0;
    int32_t i32_pos = 777;
    int32_t i32_max = numeric_limits<int32_t>::max();

    uint32_t u32_zero= 0;
    uint32_t u32_pos = 777;
    uint32_t u32_max = numeric_limits<uint32_t>::max();

    int64_t i64_min = numeric_limits<int64_t>::min();
    int64_t i64_neg = -777;
    int64_t i64_zero = 0;
    int64_t i64_pos = 777;
    int64_t i64_max = numeric_limits<int64_t>::max();

    uint64_t u64_zero= 0;
    uint64_t u64_pos = 777;
    uint64_t u64_max = numeric_limits<uint64_t>::max();


    // test int16_t
    //
    assert(int_cast<int16_t>(s16_min) == s16_min);
    assert(int_cast<int16_t>(s16_neg) == s16_neg);
    assert(int_cast<int16_t>(s16_zero) == s16_zero);
    assert(int_cast<int16_t>(s16_pos) == s16_pos);
    assert(int_cast<int16_t>(s16_max) == s16_max);

    assert(int_cast<int16_t>(u16_zero) == u16_zero);
    assert(int_cast<int16_t>(u16_pos) == u16_pos);
    THROWS(int_cast<int16_t>(u16_max));

    THROWS(int_cast<int16_t>(i32_min) == i32_min);
    assert(int_cast<int16_t>(i32_neg) == i32_neg);
    assert(int_cast<int16_t>(i32_zero) == i32_zero);
    assert(int_cast<int16_t>(i32_pos) == i32_pos);
    THROWS(int_cast<int16_t>(i32_max) == i32_max);

    assert(int_cast<int16_t>(u32_zero) == u32_zero);
    assert(int_cast<int16_t>(u32_pos) == u32_pos);
    THROWS(int_cast<int16_t>(u32_max));

    // test uint16_t
    //
    THROWS(int_cast<uint16_t>(s16_min));
    THROWS(int_cast<uint16_t>(s16_neg));
    assert(int_cast<uint16_t>(s16_zero) == s16_zero);
    assert(int_cast<uint16_t>(s16_pos) == s16_pos);
    assert(int_cast<uint16_t>(s16_max) == s16_max);

    assert(int_cast<uint16_t>(u16_zero) == u16_zero);
    assert(int_cast<uint16_t>(u16_pos) == u16_pos);
    assert(int_cast<uint16_t>(u16_max) == u16_max);

    THROWS(int_cast<uint16_t>(i32_min) == i32_min);
    THROWS(int_cast<uint16_t>(i32_neg) == i32_neg);
    assert(int_cast<uint16_t>(i32_zero) == i32_zero);
    assert(int_cast<uint16_t>(i32_pos) == i32_pos);
    THROWS(int_cast<uint16_t>(i32_max) == i32_max);

    assert(int_cast<uint16_t>(u32_zero) == u32_zero);
    assert(int_cast<uint16_t>(u32_pos) == u32_pos);
    THROWS(int_cast<uint16_t>(u32_max));

    // test int64_t
    //
    assert(int_cast<int64_t>(i32_min) == i32_min);
    assert(int_cast<int64_t>(i32_neg) == i32_neg);
    assert(int_cast<int64_t>(i32_zero) == i32_zero);
    assert(int_cast<int64_t>(i32_pos) == i32_pos);
    assert(int_cast<int64_t>(i32_max) == i32_max);

    assert(int_cast<int64_t>(u32_zero) == u32_zero);
    assert(int_cast<int64_t>(u32_pos) == u32_pos);
    assert(int_cast<int64_t>(u32_max) == u32_max);

    assert(int_cast<int64_t>(i64_min) == i64_min);
    assert(int_cast<int64_t>(i64_neg) == i64_neg);
    assert(int_cast<int64_t>(i64_zero) == i64_zero);
    assert(int_cast<int64_t>(i64_pos) == i64_pos);
    assert(int_cast<int64_t>(i64_max) == i64_max);

    assert(int_cast<int64_t>(u64_zero) == u64_zero);
    assert(int_cast<int64_t>(u64_pos) == u64_pos);
    THROWS(int_cast<int64_t>(u64_max));

    // test uint64_t
    //
    THROWS(int_cast<uint64_t>(i32_min) == i32_min);
    THROWS(int_cast<uint64_t>(i32_neg) == i32_neg);
    assert(int_cast<uint64_t>(i32_zero) == i32_zero);
    assert(int_cast<uint64_t>(i32_pos) == i32_pos);
    assert(int_cast<uint64_t>(i32_max) == i32_max);

    assert(int_cast<uint64_t>(u32_zero) == u32_zero);
    assert(int_cast<uint64_t>(u32_pos) == u32_pos);
    assert(int_cast<uint64_t>(u32_max) == u32_max);

    THROWS(int_cast<uint64_t>(i64_min) == i64_min);
    THROWS(int_cast<uint64_t>(i64_neg) == i64_neg);
    assert(int_cast<uint64_t>(i64_zero) == i64_zero);
    assert(int_cast<uint64_t>(i64_pos) == i64_pos);
    assert(int_cast<uint64_t>(i64_max) == i64_max);

    assert(int_cast<uint64_t>(u64_zero) == u64_zero);
    assert(int_cast<uint64_t>(u64_pos) == u64_pos);
    assert(int_cast<uint64_t>(u64_max));

    return 0;
}
