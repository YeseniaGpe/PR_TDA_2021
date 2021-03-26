#Esta línea tiene como objetivo "examen.exe", ejecuta un comando de gcc para obtener el ejecutable

examen.exe: examen.o funcionesExamen.o

	gcc examen.o funcionesExamen.o -o examen.exe -lm

#Esta línea es para lograr el objetivo de "examen.o"

examen.o: examen.c

	gcc  -c examen.c

#Los demás objetivos

funcionesExamen.o: funcionesExamen.c

	gcc -c funcionesExamen.c
