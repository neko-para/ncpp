default: all

all: main

main: main.cpp
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS) ../src/libncpp.a -lncursesw -ltinfo

.PHONY: default all clean

clean:
	-$(RM) -f main