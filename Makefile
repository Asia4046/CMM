EXEC = cmm
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
FLAGS = -g -Wall -lm -ldl -fPIC -rdynamic

$(EXEC): $(OBJ)
	gcc $(OBJ) $(FLAGS) -o $(EXEC)

%.o: %.c include/%.h
	gcc -c $(FLAGS) $< -o $@

clean:
	- rm cmm
	- rm src/*.o

lint:
	clang-tidy src/*.c src/include/*.h