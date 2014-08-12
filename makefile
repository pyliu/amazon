################################################################################
# Makefile for testing
################################################################################

RM := rm -rf
CP := cp -r
AR := ar -rv

all: clean sort

sort:
	@g++ -o"sort" sort.cpp

distance:
	@g++ -o"dist" distance.cpp

stream:
	@g++ -o"stream" stream.cpp

# clean all built files
clean:
	@$(RM) *.o test dist stream sort

.PHONY: all clean
