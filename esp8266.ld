INCLUDE linkcmds.memory

ENTRY(_start)

SECTIONS
{
  .text : ALIGN(4) SUBALIGN(4)
  {
    _start_text = .;
    KEEP(*(.text.entry))
    . = ALIGN(4);
    *(.text)
    *(.text.*)
    _end_text = .;
  } > iram AT > REGION_TEXT

  .rodata : ALIGN(4)
  {
    *(.rodata .rodata.*)
    _end_rodata = .;
  } > REGION_RODATA

  .data : ALIGN(4)
  {
    _data_start = .;
    *(.data .data.*)
    _data_end = .;
  } > REGION_DATA AT > irom

  _data_load = LOADADDR(.data);
  
  .bss : ALIGN(4)
  {
    _start_bss = .;
    *(.bss .bss.*)
    *(COMMON)
    _end_bss = .;
  } > REGION_BSS

  _stack_top = 0x3FFE8000 + 0x14000;
  _start_stack = _stack_top;
  __stack_size = 0x2000;
  _end_stack = _start_stack - __stack_size;
  __heap_size = 0x14000 - (SIZEOF(.data) + SIZEOF(.bss)) - __stack_size;
  _start_heap = _end_bss;
  _end_heap = _end_stack;

}
  ASSERT(_end_bss <= _end_stack, "Error: No room left for the stack");