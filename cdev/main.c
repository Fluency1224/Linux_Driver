#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	
	fd = open("/dev/hello", O_RDWR);
	if(fd < 0)
	{
		printf("open hello fail\n");
		return -1;
	}
	
	close(fd);
	return 0;
}