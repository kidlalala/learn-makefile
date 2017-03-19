test : main.o student.o organization.o help.o save.o relation.o
		gcc main.o student.o organization.o help.o save.o relation.o -o test
main.o : main.c main.h student.h organization.h relation.h save.h
			gcc -c main.c
student.o : student.c main.h
			gcc -c student.c
organization.o : organization.c main.h
					gcc -c organization.c
help.o : help.c main.h
			gcc -c help.c
save.o : save.c main.h
			gcc -c save.c
relation.o : relation.c main.h student.h organization.h
				gcc -c relation.c
clean : 
			rm main.o student.o organization.o help.o save.o relation.o test
