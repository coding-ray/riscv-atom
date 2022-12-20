#include <stdio.h>

void decode(char *str, unsigned int length)
{
    unsigned int i = 0;
    while(i < length) 
    {
        char chr = str[i];
        for(int j=0; j<str[i+1]; j++)
            putchar(chr);
        i+=2;
    }
}

int main()
{
    serial_init(UART_BAUD_115200);

    char code[270] = 
    {
        0x20,   0xe,    0x76,   0x20,   0xa,    0x1,    0x20,   0x12,   0x76,   0x1c,   0xa,    0x1,    0x72,   0xd,    0x20,   0x7,    0x76,   0x1a, 
        0xa,    0x1,    0x72,   0x10,   0x20,   0x6,    0x76,   0x18,   0xa,    0x1,    0x72,   0x12,   0x20,   0x4,    0x76,   0x18,   0xa,    0x1, 
        0x72,   0x12,   0x20,   0x4,    0x76,   0x18,   0xa,    0x1,    0x72,   0x12,   0x20,   0x4,    0x76,   0x18,   0xa,    0x1,    0x72,   0x10, 
        0x20,   0x6,    0x76,   0x16,   0x20,   0x2,    0xa,    0x1,    0x72,   0xd,    0x20,   0x7,    0x76,   0x16,   0x20,   0x4,    0xa,    0x1, 
        0x72,   0x2,    0x20,   0x10,   0x76,   0x16,   0x20,   0x6,    0xa,    0x1,    0x72,   0x2,    0x20,   0xc,    0x76,   0x18,   0x20,   0x6, 
        0x72,   0x2,    0xa,    0x1,    0x72,   0x4,    0x20,   0x6,    0x76,   0x1a,   0x20,   0x6,    0x72,   0x4,    0xa,    0x1,    0x72,   0x6, 
        0x20,   0x6,    0x76,   0x16,   0x20,   0x6,    0x72,   0x6,    0xa,    0x1,    0x72,   0x8,    0x20,   0x6,    0x76,   0x12,   0x20,   0x6, 
        0x72,   0x8,    0xa,    0x1,    0x72,   0xa,    0x20,   0x6,    0x76,   0xe,    0x20,   0x6,    0x72,   0xa,    0xa,    0x1,    0x72,   0xc, 
        0x20,   0x6,    0x76,   0xa,    0x20,   0x6,    0x72,   0xc,    0xa,    0x1,    0x72,   0xe,    0x20,   0x6,    0x76,   0x6,    0x20,   0x6, 
        0x72,   0xe,    0xa,    0x1,    0x72,   0x10,   0x20,   0x6,    0x76,   0x2,    0x20,   0x6,    0x72,   0x10,   0xa,    0x1,    0x72,   0x12, 
        0x20,   0xa,    0x72,   0x12,   0xa,    0x1,    0x72,   0x14,   0x20,   0x6,    0x72,   0x14,   0xa,    0x1,    0x72,   0x16,   0x20,   0x2, 
        0x72,   0x16,   0xa,    0x2,    0x20,   0x7,    0x49,   0x1,    0x4e,   0x1,    0x53,   0x1,    0x54,   0x1,    0x52,   0x1,    0x55,   0x1, 
        0x43,   0x1,    0x54,   0x1,    0x49,   0x1,    0x4f,   0x1,    0x4e,   0x1,    0x20,   0x1,    0x53,   0x1,    0x45,   0x1,    0x54,   0x1, 
        0x53,   0x1,    0x20,   0x1,    0x57,   0x1,    0x41,   0x1,    0x4e,   0x1,    0x54,   0x1,    0x20,   0x1,    0x54,   0x1,    0x4f,   0x1, 
        0x20,   0x1,    0x42,   0x1,    0x45,   0x1,    0x20,   0x1,    0x46,   0x1,    0x52,   0x1,    0x45,   0x2,    0xa,    0x2,    0x0,    0x1
    };

    decode(code, 270);
}