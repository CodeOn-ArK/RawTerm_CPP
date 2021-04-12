CXXFLAGS=-Wall -Wextra -pedantic -Wno-implicit-fallthrough -Wno-parentheses \
         -Wno-maybe-uninitialized -Wno-unused-variable -std=c++17
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
