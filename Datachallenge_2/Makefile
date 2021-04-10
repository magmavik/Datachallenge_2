SRC =  ./lib/dataset.cpp 
OBJECTS=$(SRC:.cpp=.o)
HEADERS=$(SRC:.cpp=.h)
TARGET = main.x
CC  = g++
LIB = 

all: $(TARGET)

main.x: main.o $(OBJECTS) $(HEADERS)
			$(CC) -g $< $(OBJECTS) $(LIB) -o $@

%.o: %.cpp $(SRC) $(HEADERS)
	$(CC) -c -o $@ $< $(LIB)

clear:
	rm *.o *.x
