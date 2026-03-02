#pragma once
#include "mmio.hxx"

namespace rcc {
    union cr_t {
        struct {
            volatile u32 __res1:4;
            volatile u32 plli2rdy:1;
            volatile u32 plli2on:1;
            volatile u32 pllrdy:1;
            volatile u32 pllon:1;
            volatile u32 __res2:4;
            volatile u32 csson:1;
            volatile u32 hsebyp:1;
            volatile u32 hserdy:1;
            volatile u32 hseon:1;
            volatile u32 hsical:8;
            volatile u32 histrim:5;
            volatile u32 __res3:1;
            volatile u32 hisrdy:1;
            volatile u32 hison:1;
        };
        volatile u32 reg;
    };

    union pllcfgr_t {
        struct {
            volatile u32 __res1:4;
            volatile u32 pllq:4;
            volatile u32 __res2:1;
            volatile u32 pllsrc:1;
            volatile u32 __res3:4;
            volatile u32 pllp:2;
            volatile u32 __res4:1;
            volatile u32 plln:9;
            volatile u32 pllm:6;
        };
        volatile u32 reg;
    };

    union cfgr_t {
        struct {
            volatile u32 mco2:2;
            volatile u32 mco2per:3;
            volatile u32 mco1per:3;
            volatile u32 i2sscr:1;
            volatile u32 mco1:2;
            volatile u32 rtcpre:4;
            volatile u32 pper2:2;
            volatile u32 ppre1:2;
            volatile u32 __res1:2;
            volatile u32 hpre:4;
            volatile u32 sws:2;
            volatile u32 sw:2;
        };
        volatile u32 reg;
    };

    union cir_t {
        struct {
            volatile u32 __res1:8;
            volatile u32 cssc:1;
            volatile u32 __res2:1;
            volatile u32 plli2srdyc:1;
            volatile u32 pllrdyc:1;
            volatile u32 hserdyc:1;
            volatile u32 hsirdyc:1;
            volatile u32 lserdyc:1;
            volatile u32 lisrdyc:1;
            volatile u32 __res3:2;
            volatile u32 pll2srdyie:1;
            volatile u32 pllrdyie:1;
            volatile u32 hserdyie:1;
            volatile u32 hisrdyie:1;
            volatile u32 lserdyie:1;
            volatile u32 lsirdyie:1;
            volatile u32 cssf:1;
            volatile u32 __res4:1;
            volatile u32 plli2srdf:1;
            volatile u32 pllrdyf:1;
            volatile u32 hserdyf:1;
            volatile u32 hisrdyf:1;
            volatile u32 lserdyf:1;
            volatile u32 lsirdyf:1;
        };
        volatile u32 reg;
    };

    union ahb1rstr_t {
        struct {
            volatile u32 __res1:2;
            volatile u32 otghsrst:1;
            volatile u32 __res2:3;
            volatile u32 ethmacrst:1;
            volatile u32 __res3:2;
            volatile u32 dma2rst:1;
            volatile u32 dma1rst:1;
            volatile u32 __res4:8;
            volatile u32 crcrst:1;
            volatile u32 __res5:3;
            volatile u32 gpioirst:1;
            volatile u32 gpiohrst:1;
            volatile u32 gpiofrst:1;
            volatile u32 gpioerst:1;
            volatile u32 gpiodrst:1;
            volatile u32 gpiocrst:1;
            volatile u32 gpiobrst:1;
            volatile u32 gpioarst:1;
        };
        volatile u32 reg;
    };
}
