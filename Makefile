CC = gcc
RM = rm -rf
CFLAGS = -Wall -O2
CPPFLAGS = -I.
LDFLAGS = -L/usr/lib -lm

PROGNAME = prog
PACKAGE=$(PROGNAME)
HEADERS = structures.h tools.h
OBJ = main.o structures.o tools.o
SOURCES = $(OBJ:.o=.c)

all: $(PROGNAME)

$(PROGNAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROGNAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<


clean:
	$(RM) $(PROGNAME) $(OBJ)  