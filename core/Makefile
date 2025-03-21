debug = -g
arg = -Wall
obj = sort.o

.PHONY: all
all: $(obj)

sort.o: sort.c sort.h
	gcc $(debug) $(arg) -c sort.c

.PHONY: clean
clean:
	rm -rf $(obj)
