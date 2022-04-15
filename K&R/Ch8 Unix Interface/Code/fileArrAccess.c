#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <fcntl.h>

int get(int fd, long pos, char *buf, int n) {
	if(lseek(fd, pos, 0) >= 0)
		return read(fd, buf, n);
	return -1;
}

int main(int argc, char* argv[]) {
	assert(argc == 2);

	char buffer[BUFSIZ];
	printf("Read %d characters from %s\n", get(open(argv[1], O_RDONLY), (long)0, buffer, BUFSIZ), argv[1]);
	printf("%s\n", buffer);	
	return 0;
}
