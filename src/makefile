CXX := g++
CPPFLAGS := -g3 -std=c++11
CPPFILES := $(wildcard *.cpp)
HFILES := $(wildcard *.h)
OBJFILES := $(CPPFILES:.cpp=.o)

prog: $(OBJFILES)
	$(CXX) $(OBJFILES) $(CPPFLAGS) -o prog

%.o: %.cpp
	$(CXX) $< $(CPPFLAGS) -c -o $@

clean:
	rm *.o
	rm prog
