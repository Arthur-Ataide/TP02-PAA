all:
	clear
	gcc ./headers/include.h	 ./headers/progDinamica.h	./headers/caverna.h	./headers/terminal.h	 ./arquivoC/progDinamica.c	./arquivoC/caverna.c	./arquivoC/terminal.c	   main.c	-lm  -o	 exec
	./exec
	

wind:
	clear
	gcc ./headers/include.h	 	   main.c	-lm  -o	 exec
	./exec	

clean:
	rm -rf *.o ./exec
	clear
