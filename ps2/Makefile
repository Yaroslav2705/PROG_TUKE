CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
OUTPUT=ps1
SOURCES=main.c k.c ui.c hof.c

.PHONY: tests clean

all: $(OUTPUT)

codeanalysis: $(SOURCES)
	cppcheck --enable=unusedFunction --error-exitcode=1 $^

$(OUTPUT): main.o k.o ui.o
	echo "Running complication"
	cppcheck --enable=unusedFunction --error-exitcode=1 $(SOURCES)
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@
	
k.o: k.c
	echo "Building object file k.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@ 

ui.o: ui.c
	echo "Building object file ui.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@ 

hof.o: hof.c
	echo "Building object file hof.o"
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@ 

clean:
	rm -rf *.o $(OUTPUT)

push:
	git commit -m "ps2"
	git push
 
