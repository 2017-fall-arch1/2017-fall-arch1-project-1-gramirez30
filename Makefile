all: bstDemo

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

bstDemo: bstree.o bstDemo.o
	cc -o $@ $^

bstree.o: bstree.c bstree.h
	cc -c $(CFLAGS) bstree.c

bstDemo.o: bstDemo.c bstree.h
	cc -c $(CFLAGS) bstDemo.c

clean:
	rm -f *.o bstDemo *~ *#

demo: bstDemo
	./bstDemo

