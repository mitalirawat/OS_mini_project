#include <sys/types.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static const int MAX_INPUT_LENGTH = 20
caddr_t result; 

/*you identify your shared memory segment with some kind of symbolic name, something like "/myRegion"
with shm_open you open a file descriptor on that region
with ftruncate you enlarge the segment to the size you need
with mmap you map it into your address space
*/
//or can use shm_open instead
//a lock on a shared data, read the data and then unlock the lock again.

//TODO: add code you used for pipes for different message sizes and the rdtsc code 2. how to make 2 processes use this for comm- start 1 process with read cmd line arg and other with write? 
int main(int argc, char **argv) {

	int fd;
	char *shared_mem;
	
//if ((fd = open("/dev/zero", O_RDWR)) == -1) 
	fd = open("testfile.txt", O_RDWR| O_CREAT);
	
//   return ((caddr_t)-1); 

	result = mmap(0, MAX_INPUT_LENGTH, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); 
	(void) close(fd);
	if (!strcmp(argv[1], "read")) {
		while(1) {
			shared_mem[MAX_INPUT_LENGTH-1] = '\0';
			printf("%s", shared_mem)
			sleep(1);
		}
	}
	else if (!strcmp(argv[2], "write")
 		while (1)
			fgets(shared_mem, MAX_INPUT_LENGTH, stdin);
 	else
		 printf("Unrecognized command\n")
//TODO
//munmap(result,0);
}
// unmap using munmap
//we already know this will still be expensive, not much of a perf gain over sockets
//Anyway results weren't as good as I was expecting: actually sharing a memory segment was a really expensive process, since remapping TLB entries and all the rest is quite expensive.
//Results were good only for really big messages (say more than a few megabytes), if you're working with little buffers, unix sockets are the most optimized thing you can find
