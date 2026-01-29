CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
OBJCOPY=arm-none-eabi-objcopy

CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib -ffreestanding -Iinclude -MMD -MP -O0 -g3 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
ASFLAGS=-mcpu=cortex-m4 -mthumb 
LDFLAGS=-T linker.ld -nostdlib -Wl,--gc-sections -mcpu=cortex-m4 -mthumb

c_source := $(shell find src -type f -name "*.c")
s_source := $(shell find src -type f -name "*.s")
source := $(s_source) $(c_source)
object := $(patsubst src/%,bin/%,$(source:.c=.o))
object := $(object:.s=.o)
dependecy := $(object:.o=.d)

.PHONY: all
all: bin/firmware.bin

bin/firmware.bin: bin/firmware.elf
	@mkdir -p bin
	@printf "coping binary   %-40s" "$<"
	@$(OBJCOPY) -O binary bin/firmware.elf bin/firmware.bin
	@printf "done\n"
	
bin/firmware.elf: $(object)
	@mkdir -p bin
	@printf "linking         %-40s" "$<"
	@$(CC) $(object) $(LDFLAGS) -o bin/firmware.elf
	@printf "done\n"

bin/%.o: src/%.c
	@printf "compling        %-40s" "$<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "done\n"

bin/%.o: src/%.s
	@printf "assembling      %-40s" "$<"
	@mkdir -p $(dir $@)
	@$(AS) $(ASFLAGS) -c $< -o $@
	@printf "done\n"
	
-include $(dependecy)

.PHONY: flash
flash: bin/firmware.bin
	st-flash write bin/firmware.bin 0x08000000
	st-flash reset
.PHONY: clean
clean:
	rm -rf bin/*
