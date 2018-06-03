# FLAGS
CC = clang
DEBUG = -g
CFLAGS = -Wall -std=c99 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
COVER_FLAGS = -ftest-coverage -fprofile-arcs

OBJECTS = listTest.o arrayList.o singlyLinkedList.o doublyLinkedList.o
TEST_TARGETS = ArrayListTest SinglyLinkedTest DoublyLinkedTest

# COMMANDS
all: tests
clean:
	rm -f $(TEST_TARGETS)
	rm -f $(OBJECTS)
tests: $(TEST_TARGETS)

# HEADER DEPENDENCIES
listTest.o: listTest.c include/list.h
arrayList.o: arrayList.c include/list.h
singlyLinkedList.o: singlyLinkedList.c include/list.h
doublyLinkedList.o: doublyLinkedList.c include/list.h

# BUILD RULES
ArrayListTest: listTest.o arrayList.o
	$(CC) $(CFLAGS) $(INC) $^ -c $@

SinglyLinkedTest: listTest.o singlyLinkedList.o
	$(CC) $(CFLAGS) $(INC) $^ -c $@

DoublyLinkedTest: listTest.o doublyLinkedList.o
	$(CC) $(CFLAGS) $(INC) $^ -c $@
