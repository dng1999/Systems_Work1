compile: test.c
	gcc test.c

run: a.out
	./a.out

clean: 
	rm *~
