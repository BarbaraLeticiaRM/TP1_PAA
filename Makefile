all: funcoes.o ordenacao.o main.c
	gcc -o main main.c funcoes.o ordenacao.o -lm

funcoes.o: funcoes.c
	gcc -o funcoes.o -c funcoes.c -lm

ordenacao.o: ordenacao.c
	gcc -o ordenacao.o -c ordenacao.c
	
clean:
	rm -f *.o main
		
run:
	./main
