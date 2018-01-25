CC = gcc

INCDIR = -I../include
SRCDIR = -I../src

RELEASE = -c -O3
DEBUG = -c -g
CFLAGS = $(RELEASE)

TARGET = example

$(TARGET): example.o HashTable.o
	$(CC) $^ -o $@

example.o: example.c
	$(CC) $(CFLAGS) $(INCDIR) $< -o $@

HashTable.o: ../src/HashTable.c
	$(CC) $(CFLAGS) $(SRCDIR) $(INCDIR) $< -o $@

clean:
	rm -f *.o
	rm -f $(TARGET)