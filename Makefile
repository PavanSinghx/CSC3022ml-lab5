CC=g++
CCflags = -std=c++11
INCLflag= -Iinclude/ 

BUILD = build
SRC = src
BIN = bin
TARGET = main
bin: objects
	@mv main $(BIN)/

objects: files.o
	@mv *.o $(BUILD)/

files.o: files.cpp
	$(CC) driver.o perceptron.o -o main $(CCflags)

files.cpp: $(SRC)/driver.cpp $(SRC)/perceptron.cpp 
	$(CC) -c $(SRC)/driver.cpp $(SRC)/perceptron.cpp $(INCLflag) $(CCflags)

run: 
	cd $(BIN); ./$(TARGET)

clean: files.o
	@rm $(BUILD)/*.o
	@rm $(BIN)/*