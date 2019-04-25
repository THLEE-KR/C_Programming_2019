#include<stdio.h>
int  main()
{
	signed char ch=0xff;
	unsigned char uch = 0xff;

	ch >>= 4;
	uch >>= 4;

	printf("ch = %x,  uch = %x", ch, uch);

	getchar();
	return 0;
}
