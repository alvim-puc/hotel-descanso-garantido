# Makefile

CC = gcc
CFLAGS = -Wall -Iinclude
SRCDIR = src
OBJDIR = obj
BINDIR = bin
LIBNAME = libhotel.a

_SRCS = main.c hotel.c
SRCS = $(patsubst %,$(SRCDIR)/%,$(_SRCS))

_OBJS = main.o hotel.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

TARGET = $(BINDIR)/main

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR)

