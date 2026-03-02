#include "flash.hxx"
#include "mmio.hxx"

namespace flash {
    struct reg_t {
        volatile u32 accessControl;
        volatile u32 key;
        volatile u32 optionKey;
        volatile u32 status;
        volatile u32 control;
        volatile u32 optionControl;
    };

    volatile reg_t* __registers__ = (volatile reg_t*) MM_FLASH_IR;

    static inline bool isBusy() {
        return (__registers__->status & (1 << 16)) > 0;
    }

    template <u8 numberWaitState>
    static inline void setWaitState() {
        static_assert(numberWaitState <= 7, "flash wait sate > 7");
        __registers__->accessControl &= 3;
        __registers__->accessControl |= numberWaitState;
    }

    static inline void enablePrefetch() {
        __registers__->accessControl |= (1 << 8);
    }

    static inline void disablePrefetch() {
        __registers__->accessControl &= ~(1 << 8);
    }

    static inline void enableCodeCache() {
        __registers__->accessControl |= (1 << 9);
    }

    static inline void disableCodeCache() {
        __registers__->accessControl &= ~(1 << 9);
    }

    static inline void enableDataCache() {
        __registers__->accessControl |= (1 << 10);
    }

    static inline void disableDataCache() {
        __registers__->accessControl &= ~(1 << 10);
    }
}
