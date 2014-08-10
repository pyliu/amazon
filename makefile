################################################################################
# Makefile for testing
################################################################################

RM := rm -rf
CP := cp -r
AR := ar -rv

all:
	@g++ -o"test" test.cpp

# clean all built files
clean:
	@$(RM) *.o test

.PHONY: all clean
