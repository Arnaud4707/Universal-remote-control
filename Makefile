TARGET = main
SRC    = $(TARGET).c start.S
OBJ    = $(TARGET).o start.o
ELF    = $(TARGET).elf
LDSCRIPT = esp8266.ld
HEADER = include/esp8266.h include/gpio.h

PREFIX  = xtensa-lx106-elf-
CC      = $(PREFIX)gcc
SIZE    = $(PREFIX)size
ESPTOOL = esptool          # ou esptool.py selon ce que `which` te donne

F_CPU      = 80000000UL
PORT       = /dev/ttyUSB0
BAUD       = 460800        # 115200 si 460800 rate
FLASH_SIZE = 4MB
FLASH_MODE = dio           # D1 mini / ESP-12F : dio. Si ça ne boot pas : qio
FLASH_FREQ = 40m

CFLAGS  = -std=c11 -Os -Wall
CFLAGS += -DF_CPU=$(F_CPU)
# specifie pouvoir des appeles memoire longue porté  / concerne les litérale, spécifique a xtensia
CFLAGS += -mlongcalls \
		-mtext-section-literals
CFLAGS += -ffunction-sections -fdata-sections # cree des sexions pour les fonctions / data
CFLAGS += -nostdlib -fno-builtin # evite d'inclure libstd et les builtin fonction

ASFLAGS = -mlongcalls -mtext-section-literals

LDFLAGS  = -nostdlib -nostartfiles -Wl,--gc-sections # Wl: envoie des arguments au binaire/ ,--gc-sections: supprime les sexions inutiles
LDFLAGS += -Wl,-T,$(LDSCRIPT) # -T remplace le linker script par défaut de ld
LDFLAGS += -Wl,-Map,$(TARGET).map # -Map memory map
all: $(TARGET)-0x00000.bin # addresse en memoire de l'endroi où ecrire le code

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S 
	$(CC) $(ASFLAGS) -c $< -o $@

$(ELF): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@
	$(SIZE) $@

$(TARGET)-0x00000.bin: $(ELF)
	$(ESPTOOL) --chip esp8266 elf2image \
		--flash-mode $(FLASH_MODE) \
		--flash-size $(FLASH_SIZE) \
		--flash-freq $(FLASH_FREQ) \
		-o $(TARGET)- $<

flash: $(TARGET)-0x00000.bin
	$(ESPTOOL) --chip esp8266 --port $(PORT) --baud $(BAUD) \
		write_flash --flash_mode $(FLASH_MODE) \
		--flash_size $(FLASH_SIZE) --flash_freq $(FLASH_FREQ) \
		0x00000 $(TARGET)-0x00000.bin

clean:
	rm -f $(OBJ) $(ELF) $(TARGET)-0x*.bin $(TARGET).map

id:
	$(ESPTOOL) --chip esp8266 --port $(PORT) flash_id

monitor:
	picocom -b 74880 $(PORT)