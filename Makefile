CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
LIBS =

RawTerm: RawTerm.o
	$(CXX) $(LIBS) -o $@ $^

*.o: *.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	$(RM) *.o RawTerm
