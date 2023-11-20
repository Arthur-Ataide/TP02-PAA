all:
	gcc ./headers/include.h	 ./headers/progDinamica.h	./headers/caverna.h	./headers/terminal.h	 ./arquivoC/progDinamica.c	./arquivoC/caverna.c	./arquivoC/terminal.c	   main.c	-lm  -o	 exec
	./exec
	

clock:
	gcc ./headers/include.h	 ./headers/progDinamica.h	./headers/caverna.h	./headers/terminal.h	 ./arquivoC/progDinamica.c	./arquivoC/caverna.c	./arquivoC/terminal.c	   mainClock.c	-lm  -o	 exec
	./exec

aleatorio:
	gcc    ./mainAleatorio.c	-lm  -o	 exec
	./exec

selecao:
	gcc    ./mainSelecao.c	-lm  -o	 exec
	./exec
