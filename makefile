CC=gcc
CFLAGS=-c -Wall -Wextra -std=c++11
LDFLAGS = -lstdc++
INCLUDES=-Iinclude
SRCDIR=src
OBJDIR=obj

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
MAINOBJ=$(OBJDIR)/principal.o
EXECUTABLE=principal

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(MAINOBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

$(MAINOBJ): principal.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)
