INC_DIR = include
all: shell hw8


hw8: main.o Term.o Number.o Variable.o Atom.o List.o Struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw8 main.o Term.o Number.o Variable.o Atom.o List.o Struct.o -lgtest
else
	g++ -o hw8 main.o Term.o Number.o Variable.o Atom.o List.o Struct.o -lgtest -lpthread
endif
shell: shell.o Term.o Number.o Variable.o Atom.o List.o Struct.o
ifeq (${OS}, Windows_NT)
	g++ -o shell shell.o Term.o Number.o Variable.o Atom.o List.o Struct.o -lgtest
else
	g++ -o shell shell.o Term.o Number.o Variable.o Atom.o List.o Struct.o -lgtest -lpthread
endif
shell.o: shell.cpp utTerm.h utStruct.h utVariable.h utList.h utParser.h utIterator.h expression.h exception.h
	g++ -std=gnu++0x -c shell.cpp
main.o: main.cpp utTerm.h utStruct.h utVariable.h utList.h utParser.h utIterator.h expression.h exception.h
	g++ -std=gnu++0x -c main.cpp
Term.o: term.h Term.cpp
	g++ -std=gnu++0x -c Term.cpp
Number.o: number.h Number.cpp
	g++ -std=gnu++0x -c Number.cpp
Variable.o: variable.h Variable.cpp
	g++ -std=gnu++0x -c Variable.cpp
Atom.o: atom.h Atom.cpp
	g++ -std=gnu++0x -c Atom.cpp
List.o: list.h List.cpp
	g++ -std=gnu++0x -c List.cpp
Struct.o: struct.h Struct.cpp
	g++ -std=gnu++0x -c Struct.cpp

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
	rm -f *.o hw8 shell
endif
