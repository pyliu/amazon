################################################################################
# Makefile for testing
################################################################################

RM := rm -rf
CP := cp -r
AR := ar -rv

all: distance stream
	@g++ -o"test" test.cpp

distance:
	@g++ -o"dist" distance.cpp

stream:
	@g++ -o"stream" stream.cpp

# clean all built files
clean:
	@$(RM) *.o test dist stream

.PHONY: all clean
