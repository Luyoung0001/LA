OUTPUT_ARCH(loongarch)
ENTRY(_start)
SECTIONS
{
  . = 0x1c000000;
  .text :
  {
    _start = .;
    *(.text)
    *(.rodata*)
  } =0
}
