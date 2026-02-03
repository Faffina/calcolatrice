#include <stdint.h>
#include <stdbool.h>
#include "df.h"

enum class test {faffa, baffa};

int main(void) {
    test a = test::faffa;
    show_code_once(0, 2);
    while(1) {
        show_code_once(0, 1);
    }
}
