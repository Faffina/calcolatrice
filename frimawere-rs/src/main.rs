#![no_std]
#![no_main]

use core::panic::PanicInfo;

// This tells the compiler your assembly code will find this symbol
#[unsafe(no_mangle)]
pub extern "C" fn main() -> ! {
    let a: u32 = 324;
    let b = a & 231;
    let mut c = a + 24*b;
    unsafe { 
        core::arch::asm!("nop"); 
    }
    // Your hardware logic here
    // Example: Writing to a register using volatile_store
    loop {}
}

// Since we are no_std, we must define what happens on a panic.
#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}
