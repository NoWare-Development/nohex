CC=clang
CFLAGS=-g -Wall -pedantic -fPIC
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BUILDDIR=build
EXECUTABLE=$(BUILDDIR)/nohex

always: $(EXECUTABLE)

$(EXECUTABLE): $(BUILDDIR) $(OBJ) $(OBJS)
	rm -rf $(EXECUTABLE)
	$(CC) $(OBJS) -o $(EXECUTABLE)

$(OBJ)/%.o: $(SRC)/%.c $(SRC)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir $@

$(BUILDDIR):
	mkdir $@

clean:
	rm -rf $(BUILDDIR)/*
