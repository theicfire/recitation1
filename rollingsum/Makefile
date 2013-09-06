CC := gcc
CFLAGS := -Wall
LDFLAGS := -lrt

all: rollingsum

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

ktiming.o: ktiming.c
	$(CC) $(CFLAGS) -c ktiming.c

sum.o: sum.c
	$(CC) $(CFLAGS) -c sum.c

rollingsum: main.o ktiming.o sum.o
	$(CC) -o rollingsum main.o ktiming.o sum.o $(LDFLAGS)

clean:
	rm -f rollingsum *.o

