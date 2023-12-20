# Makefile for a simple C program

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Source files and target executable
SRCS = main.c
TARGET = cgames

# Rules
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lSDL2

clean:
	rm -f $(TARGET)

.PHONY: all clean
