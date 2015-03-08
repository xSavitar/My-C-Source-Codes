#include<stdio.h>

int main(int argc, char **argv){
	long l = 0xdeadbeef;
	short s = l;
	char c = l;
	printf("long: %x\n", l);
	printf("short: %x\n", s);
	printf("Char: %x\n", c);
	
	return 0;
}
