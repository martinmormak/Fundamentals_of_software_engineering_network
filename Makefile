CC = gcc
CFLAGS = -std=gnu11 -Wall -pedantic
LDFLAGS = 

TARGET = notwork
MODULES = wall.o post.o

# Main tasks
.PHONY: all clean

all: $(TARGET)

clean:
	rm *.o $(TARGET)

# Dependencies
$(TARGET): notwork.o $(MODULES)
notwork.o: notwork.c wall.h post.h
wall.o: wall.c wall.h post.h
post.o: post.c post.h

# Machinery
%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<
%: %.o
	$(CC) -o $@ $(LDFLAGS) $^
