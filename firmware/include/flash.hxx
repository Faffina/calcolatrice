#pragma once
#include "mmio.hxx"

namespace flash {
    struct acr_t {
        volatile u32 latency: 3;
        volatile u32 __r1__: 5;
        volatile u32 prften: 1;
        volatile u32 icen: 1;
        volatile u32 dcen: 1;
        volatile u32 icrst: 1;
        volatile u32 dcrst: 1;
        volatile u32 __r2__: 19;
    };

    static const u32 keyr_k1 = 0x45670123;
    static const u32 keyr_k2 = 0xcdef89ab;

    static const u32 optkeyr_k1 = 0x08192a3b;
    static const u32 optkeyr_k2 = 0x4c5d6e7f;

    struct sr_t {
        volatile u32 eop: 1;
        volatile u32 operr: 1;
        volatile u32 __r1__: 2;
        volatile u32 wrperr: 1;
        volatile u32 pgaerr: 1;
        volatile u32 pgperr: 1;
        volatile u32 pgserr: 1;
        volatile u32 __r2__: 8;
        volatile u32 bsy: 1;
        volatile u32 __r3__: 15;
    };

    struct cr_t {
        volatile u32 pg: 1;
        volatile u32 ser: 1;
        volatile u32 mer: 1;
        volatile u32 snb: 4;
        volatile u32 __r1__: 1;
        volatile u32 psize: 2;
        volatile u32 __r2__: 6;
        volatile u32 strt: 1;
        volatile u32 __r3__: 7;
        volatile u32 eopie: 1;
        volatile u32 errie: 1;
        volatile u32 __r4__: 5;
        volatile u32 lock: 1;
    };
}
