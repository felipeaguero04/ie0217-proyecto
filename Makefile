CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lstdc++fs -lsqlite3

SRC_DIR = src
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.exe)
EXECUTABLE = $(BIN_DIR)/banksys.exe
DB_FILE = banksys.db

all: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BIN_DIR)/%.exe: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

doxygen:
	firefox html/index.html

clean:
	rm $(BIN_DIR)/*.exe
	rm -f $(BIN_DIR)/*.exe $(EXECUTABLE) $(DB_FILE)
