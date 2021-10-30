a.out:main_program.o command.o charmachine.o wordmachine.o help.o
	gcc main_program.o command.o charmachine.o wordmachine.o help.o
main_program.o:main_program.c
	gcc -c main_program.c
command.o:command.c
	gcc -c command.c
charmachine.o:charmachine.c
	gcc -c charmachine.c
wordmachine.o:wordmachine.c
	gcc -c wordmachine.c
help.o:help.c
	gcc -c help.c
