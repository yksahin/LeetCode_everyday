
#include <stdio.h>

int main()
{
   int data[] = {0xAABBCCDD};

   unsigned char bytes[4];
   bytes[0] = (unsigned char) (data[0] >> 24);
   bytes[1] = (unsigned char) (data[0] >> 16);
   bytes[2] = (unsigned char) (data[0] >> 8);
   bytes[3] = (unsigned char) data[0];


   for(int i =0 ; i < 4; i++) printf("%02X\n", bytes[i]);
    return 0;
}