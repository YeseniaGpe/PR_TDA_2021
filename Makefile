#Makefile for Array (sirve ya para todos los programas)

#Pones los targets que no van a generar files
.PHONY = all CLEAN

#Variables:
CC = gcc
world := hola #variable estatica 
CFLAGS = -C0 -s -lm
linkers = -lm -lpthread

#Functions
deps = $(wildcard *.c) #DEPENDECIES aqui van los .c esa fun. trae todos los .c
depsh = $(wildcard *.h)
BINS = $(deps: %.c = %.o) #del contenido de deps, copia todo lo que es .c y pegalo, pero concatenale .o


all: ${BINS} eje
#TARGET : {DEPENDENCIES ...}
#<tab> RULE

BINS: $(deps)  #trae todo lo que tenga .c $^ del lado derecho @$ del lado izquerdo
	${CC} -c $^ ${CFLAGS}
	@echo "Generating binary objects"


eje: ${BINS} 
	${CC} -o $@ $^ ${linkers}
	@echo "Generating excecutable"

PRINT:
	@echo $(deps) $(BINS)

CLEAN:
	rm -rvf *.o TEST_ARRAY
	@echo "Removing all binary objects and excecutables"