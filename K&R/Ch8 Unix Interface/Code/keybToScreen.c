#include <sys/syscall.h>

#define BUFFSIZE 20

int main() {
	char buffer[BUFFSIZE];
	int n;

	while((n = read(0, buffer, BUFFSIZE)) > 0)
		write(1, buffer, n);
	return 0;
}
