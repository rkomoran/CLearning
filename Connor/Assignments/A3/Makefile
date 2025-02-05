GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRCS = string_stuff.c
OBJS = $(SRCS:%.c=%.o) # string_stuff.o

program: $(OBJS)
	$(GCC) $(CFLAGS) -o program $(OBJS)  # linking here, notice no -c

.c.o:
	$(GCC) $(CFLAGS) -c $*.c  # compile all .c to .o

clean:
	/bin/rm -f *.o program *~ *bak output*
