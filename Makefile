all:
	clear
	gcc ./headers/include.h	   main.c	-lncurses	-lm  -o	 exec
	./exec
	

wind:
	clear
	gcc ./headers/include.h	 	   main.c	-lm  -o	 exec
	./exec	

clean:
	rm -rf *.o ./exec
	clear
