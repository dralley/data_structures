# FLAGS
CC = gcc
DEBUG = -g
CFLAGS = -Wall -std=c99 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
COVER_FLAGS = -ftest-coverage -fprofile-arcs

OBJECTS = listTest.o arrayList.o singlyLinkedList.o doublyLinkedList.o
TEST_TARGETS = ArrayListTest SinglyLinkedListTest DoublyLinkedListTest

# COMMANDS
all: tests
clean:
	rm -f $(TEST_TARGETS)
	rm -f $(OBJECTS)
tests: $(TEST_TARGETS)

# HEADER DEPENDENCIES
listTest.o: listTest.c list.h
arrayList.o: arrayList.c list.h
singlyLinkedList.o: singlyLinkedList.c list.h
doublyLinkedList.o: doublyLinkedList.c list.h

# BUILD RULES
ArrayListTest: listTest.o arrayList.o
	$(CC) $(CFLAGS) $^ -o $@

SinglyLinkedListTest: listTest.o singlyLinkedList.o
	$(CC) $(CFLAGS) $^ -o $@

DoublyLinkedListTest: listTest.o doublyLinkedList.o
	$(CC) $(CFLAGS) $^ -o $@
