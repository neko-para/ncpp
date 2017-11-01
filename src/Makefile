SRCS=$(wildcard *.cpp)
DEPS=$(patsubst %.cpp, .build/%/Makefile, $(SRCS))
OBJS=$(patsubst %.cpp, .build/%/.o, $(SRCS))

default: all

all:
	$(MAKE) -B $(DEPS)
	$(MAKE) libncpp.a

.PHONY: default all clean

libncpp.a: $(OBJS)
	$(AR) r $@ $(OBJS)

.build/%/Makefile: %.cpp
	mkdir -p .build/`echo $< | sed 's/\.cpp$$//'`
	echo .build/`echo $< | sed 's/\.cpp$$//'`/.o:`$(CXX) -MM $< | sed 's/^.*://'` > $@
	echo '	$$(CXX) -c -o $$@ $$< $$(CXXFLAGS)' >> $@

clean:
	-$(RM) -rf .build
	-$(RM) -rf libncpp.a

-include .build/*/Makefile