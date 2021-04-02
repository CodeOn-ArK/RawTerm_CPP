CXXFLAGS=-Wall -Wextra -pedantic -std=c++14
LIBS=-lcurses -lmenu

SRC=RawTerm.cpp
OBJ=RawTerm.o

.PHONY: clean

RawTerm: $(OBJ)
	$(CXX) $(LIBS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) RawTerm
