obj = main.o core/sort.o readwritelines/readwritelines.o readwritelines/getaline.o
debug = -g
arg = -Wall # -I flag tells it where to look for header file

sort: $(obj)
	gcc $(debug) $(arg) -o sort $(obj)

main.o: main.c core/sort.h
	gcc $(debug) $(arg) -c main.c

.PHONY: sort readwritelines clean
core:
	$(MAKE) -C core

readwritelines:
	$(MAKE) -C readwritelines

clean:
	rm -rf main.o
	$(MAKE) -C core clean
	$(MAKE) -C readwritelines clean
