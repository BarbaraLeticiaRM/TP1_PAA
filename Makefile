all: funcoes.o ordenacao.o main.cpp
	g++ -o main main.cpp funcoes.o ordenacao.o

funcoes.o: funcoes.cpp
	g++ -o funcoes.o -c funcoes.cpp

ordenacao.o: ordenacao.cpp
	g++ -o ordenacao.o -c ordenacao.cpp
	
clean:
	rm -f *.o main
		
run:
	./main
