CC=clang
CFLAGS=-g -Wall -pedantic -fPIC
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

EXECUTABLE=nohex

PACKAGEDIR=package
PACKAGE=$(PACKAGEDIR)/nohex.tar.gz

.PHONE: always tar clean

always: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) $(OBJS)
	rm -rf $(EXECUTABLE)
	$(CC) $(OBJS) -o $(EXECUTABLE)

$(OBJ)/%.o: $(SRC)/%.c $(SRC)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir $@

tar: $(PACKAGE)

$(PACKAGE): $(EXECUTABLE) $(PACKAGEDIR)
	tar -czvf $(PACKAGE) $(EXECUTABLE)

$(PACKAGEDIR):
	mkdir $@

clean:
	rm -rf $(EXECUTABLE)
	rm -rf $(PACKAGEDIR)/*
