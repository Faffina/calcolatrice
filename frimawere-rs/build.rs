fn main() {
    cc::Build::new()
        .file("start.s") 
        .compile("start"); 

    println!("cargo:rerun-if-changed=startup.s");
    println!("cargo:rerun-if-changed=linker.ld");
}
