#
# Builds libForeignObjects.dynlib
#

CC=gcc
CFLAGS=-Iinclude -Wall -O2 -g
TARGET=libForeignObjects.dylib
INC_DIR=include/ForeignObjects
HEADERS=$(INC_DIR)/Class.h $(INC_DIR)/Object.h $(INC_DIR)/String.h $(INC_DIR)/StringBuilder.h $(INC_DIR)/LispList.h

all: $(TARGET)

$(TARGET): String.o Lisp.o
	$(CC) -dynamiclib -o $(TARGET) String.o Lisp.o -L/opt/local/lib -lgc

String.o: String.c $(HEADERS)

Lisp.o: Lisp.c $(HEADERS)

clean:
	rm *.o $(TARGET)

