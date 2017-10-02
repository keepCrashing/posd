INC_DIR = include

all: hw2

hw2: main.o Number.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 main.o Number.o -lgtest
else
	g++ -o hw2 main.o Number.o -lgtest -lpthread
endif

main.o: main.cpp utTerm.h
	g++ -std=gnu++0x -c main.cpp
Number.o: $(INC_DIR)/Number.h Number.cpp
	g++ -std=gnu++0x -c Number.cpp
#Shapes.o: $(INC_DIR)/Shapes.h Shapes.cpp
#	g++ -std=gnu++0x -c Shapes.cpp
#Media.o: $(INC_DIR)/Media.h Media.cpp
#	g++ -std=gnu++0x -c Media.cpp
#Sort.o: $(INC_DIR)/Sort.h Sort.cpp
#	g++ -std=gnu++0x -c Sort.cpp
clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif
