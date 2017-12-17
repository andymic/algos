# the compiler: gcc for C program, define as g++ for C++
CC = g++ -g

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -std=c++11 -pthread 
RFLAGS  = -Wall 
PROJECT_PATH = $(PWD)
# define any directories containing header files other than /usr/include
INCLUDES = -I$(PROJECT_PATH)/data_structures

# define the C++ source files
DIR_PATH= $(PROJECT_PATH)/data_structures
SRCS = main.cc $(DIR_PATH)/linkedlist.cc $(DIR_PATH)/stack.cc $(DIR_PATH)/queue.cc $(DIR_PATH)/binary_search_tree.cc

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.cc=.o)

DIRS = $(MAIN) $(DIR_PATH)
# define the executable file 
MAIN = main 
#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: clean

all:$(MAIN)
	@echo  Simple compiler named interview prep has been compiled 

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)  

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.cc.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	@echo cleaning up; \
	find . -iname "*.o" -type f -delete	
	
	
