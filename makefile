FCC = gcc
LDC = gcc
LD_FLAGS=
FLAGS=
PROG = parallelMatrix 
RM = /bin/rm
OBJS = mm-student.o

#all rule
all: $(PROG)

$(PROG): $(OBJS)
	$(LDC) $(LD_FLAGS) $(OBJS) -o $(PROG)

%.o: %.c
	$(FCC) $(FLAGS) -c $<

#clean rule
clean:
	$(RM) -rf *.o $(PROG) *.mod
