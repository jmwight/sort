debug = -g
arg = -Wall
obj = readwritelines.o getaline.o

.PHONY: all
all: $(obj)

readwritelines.o: readwritelines.c strcpy.h getaline.h
	gcc $(debug) $(arg) -c readwritelines.c

getaline.o: getaline.c
	gcc $(debug) $(arg) -c getaline.c

#strcpy.o: strcpy.c strcpy.h
#	gcc $(debug) $(arg) -c strcpy.c

.PHONY: clean
clean:
	rm -rf $(obj)
