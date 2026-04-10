CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -Iinclude

SRC := main.cpp
OBJ := $(SRC:.cpp=.o)
BIN := app

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean run
