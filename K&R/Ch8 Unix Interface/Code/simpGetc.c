#include <sys/syscall.h>
#include <stdio.h>

#undef getchar

int getchar() {
	char c;
	int n;
	return (n = read(0, &c, sizeof(char)))  == 1 ? (unsigned char)c : EOF;
}

int main() {
	printf("%c", getchar());
	return 0;
}
