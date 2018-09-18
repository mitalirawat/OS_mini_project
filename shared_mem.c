#include <sys/types.h>
#include <sys/mman.h>
int fd; 
caddr_t result; 
if ((fd = open("/dev/zero", O_RDWR)) == -1) 
   return ((caddr_t)-1); 

result = mmap(0, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); 
(void) close(fd);
