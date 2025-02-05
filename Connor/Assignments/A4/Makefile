GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRCS = as5.c matrix.c
OBJS = $(SRCS:%.c=%.o) 

program: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o program

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	/bin/rm -f *.o program *~ *bak output*
