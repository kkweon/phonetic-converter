TARGET = phonetic
CC = g++ 
CFLAGS = -Wall -Wextra -std=c++1z

BINDIR = bin


OBJECTS = $(patsubst src/%.cpp, src/%.o, $(wildcard src/*.cpp))
HEADERS = $(wildcard src/*.hpp)

all: $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) $(CFLAGS) -o bin/$@

$(BINDIR):
	mkdir $(BINDIR)

run:
	$(BINDIR)/$(TARGET) src/data/NATO.txt

.PHONY: clean
clean:
	-rm -f src/*.o
	-rm -f $(TARGET)
	-rm -rf $(BINDIR)
