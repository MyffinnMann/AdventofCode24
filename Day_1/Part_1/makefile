# Define variables
CC = gcc               
CFLAGS = -Wall -Wextra  
TARGET = compiled_and_linked_program        
SRC = Puzzle_1.c            #name of C file
   
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
clean:
	rm -f $(TARGET)
run: $(TARGET)
	./$(TARGET)

rebuild: clean alll
