# Makefile

STD = 

OPTIONS = -Wall -Wpedantic -Wno-unused-result -O0 -g -D_FILE_OFFSET_BITS=64
# -O0: nao otimiza o codigo ao compilar
# -g:  prepara o terreno para que o gdb possa encontrar bugs

LIBRARIES = -lpthread -lm 

threads : thread_main.c
	gcc $(STD) $(OPTIONS) thread_main.c -o thread $(LIBRARIES)

clean:
	rm -f thread
