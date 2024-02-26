# Makefile for the World Cup Database

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c11 -g

# Linker flags
LDFLAGS = -lm

# Executable name
EXE = wc

# Source files
SRC = worldcup_player.c worldcup_team.c worldCupDB.c

# Header files
HDR = worldcup_player.h worldcup_team.h worldCupDB.h

# Object files
OBJ = $(SRC:.c=.o)

# Build the executable
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Build the object files
%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -f $(OBJ) $(EXE)

# Run the executable
run: $(EXE)
	./$<

# Run the executable with valgrind
valgrind: $(EXE)
	valgrind --leak-check=full --show-leak-kinds=all ./$<
