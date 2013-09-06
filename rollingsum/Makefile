CC := gcc

CFLAGS := -Wall -g -O3 -DNDEBUG
LDFLAGS := -lrt


ifeq ($(DEBUG), 1)
	CFLAGS := -Wall -g -O0 -fprofile-arcs -ftest-coverage
	LDFLAGS := -lrt -fprofile-arcs -ftest-coverage
endif

ifeq ($(PROFILE), 1)
	CFLAGS := -Wall -g -O3 -DNDEBUG -pg 
	LDFLAGS := -lrt -pg
endif


all: rollingsum

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

ktiming.o: ktiming.c
	$(CC) $(CFLAGS) -c ktiming.c

sum.o: sum.c
	$(CC) $(CFLAGS) -c sum.c

rollingsum: main.o ktiming.o sum.o
	$(CC) -o rollingsum main.o ktiming.o sum.o $(LDFLAGS)
ifeq ($(PROFILE), 1)
	./rollingsum > /dev/null
	mv gmon.out gmon.sum
	./rollingsum > /dev/null
	gprof -s ./rollingsum gmon.out gmon.sum
	gprof ./rollingsum gmon.sum > gprof-profile
endif

clean:
	rm -f rollingsum *.o
	rm -f rollingsum *.gcda
	rm -f rollingsum *.gcno
	rm -f rollingsum *.gcov
	rm -f gmon.out
	rm -f gprof-profile
	
