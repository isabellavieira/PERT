CC     = gcc
CFLAGS = -g
OBJS = oplista.o opgrafo.o entradaSaida.o pert.o tp2.o 
TARGET = tp2

all: $(TARGET)

tp2: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o tp2
	
tp2.o: tp2.c opgrafo.c opgrafo.h entradaSaida.c entradaSaida.h pert.c pert.h
		$(CC) $(CFLAGS) -c tp2.c
		
pert.o: pert.c pert.h opgrafo.c opgrafo.h oplista.c oplista.h
		$(CC) $(CFLAGS) -c pert.c
				
entradaSaida.o: entradaSaida.c entradaSaida.h opgrafo.c opgrafo.h
	$(CC) $(CFLAGS)  -c entradaSaida.c	

opgrafo.o: opgrafo.c opgrafo.h oplista.c oplista.h
	$(CC) $(CFLAGS)  -c opgrafo.c	

oplista.o: oplista.c oplista.h
	$(CC) $(CFLAGS)  -c oplista.c	

clean: 
	rm -rf *.o ./$(TARGET)
	
run: 
	./tp2
