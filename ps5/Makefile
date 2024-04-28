CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
OUTPUT=ps5
SOURCES=main.c backpack.c command.c container.c game.c item.c parser.c room.c world.c

.PHONY: tests clean

all: $(OUTPUT)

codeanalysis: $(SOURCES)
	cppcheck --enable=unusedFunction --error-exitcode=1 $^

$(OUTPUT): main.o backpack.o command.o container.o game.o item.o parser.o room.o world.o
	echo "Running complication"
	cppcheck --enable=unusedFunction --error-exitcode=1 $(SOURCES)
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@
	
backpack.o: backpack.c
	echo "Building object file backpack.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@ 

command.o: command.c
	echo "Building object file command.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@ 

container.o: container.c
	echo "Building object file container.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@
	
game.o: game.c
	echo "Building object file game.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@ 

item.o: item.c
	echo "Building object file item.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@ 

parser.o: parser.c
	echo "Building object file parser.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@
	
room.o: room.c
	echo "Building object file room.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@ 

world.o: world.c
	echo "Building object file world.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@ 

tests: bmp.o tests/test_reverse.c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o test_reverse


clean:
	rm -rf *.o $(OUTPUT)

push:
	git commit -m "ps5"
	git push
 
