all: funcoes.o ordenacao.o main.c
	gcc -o main main.c funcoes.o ordenacao.o

funcoes.o: funcoes.c
	gcc -o funcoes.o -c funcoes.c

ordenacao.o: ordenacao.c
	gcc -o ordenacao.o -c ordenacao.c
	
clean:
	rm -f *.o main
		
run:
	./main
