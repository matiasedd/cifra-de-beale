CC = gcc
CFLAGS = -std=c99 -Wall -I $(LIBS_DIR)

SRC_DIR = src
OBJ_DIR = objects
LIBS_DIR = libs

TARGET = beale

OBJECTS = $(OBJ_DIR)/lib_utils.o $(OBJ_DIR)/lib_list.o $(OBJ_DIR)/lib_beale.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBS_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) beale.c $(OBJECTS)

clean:
	rm -f $(OBJ_DIR)/*.o 

purge: clean
	rm -f $(OBJ_DIR)/*.o $(TARGET)
