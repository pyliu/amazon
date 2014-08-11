################################################################################
# Makefile for testing
################################################################################

RM := rm -rf
CP := cp -r
AR := ar -rv

all: distance
	@g++ -o"test" test.cpp

distance:
	@g++ -o"dist" distance.cpp

# clean all built files
clean:
	@$(RM) *.o test dist

.PHONY: all clean
