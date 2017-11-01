all:

test: all
	make -C test

clean:
	make -C src clean
	make -C test clean

%:
	make -C src $@