
###### VARIABLES

EXE=erdos
CFLAGS=-Wall -ansi -pedantic -ggdb -g
LFLAGS=

#################### DO NOT CHANGE ################

CXXFLAGS=$(CFLAGS)
CC=g++


###### LISTS

SRCS:=$(wildcard *.cpp)
OBJS:=$(patsubst %.cpp,%.o,$(SRCS))
DEPS:=$(patsubst %.cpp,%.d,$(SRCS))

###### RULES

$(EXE): $(DEPS) $(OBJS) 
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LFLAGS)

# $< is whatever %.cpp was.   $@ is whatever %.d was
# sed stands for stream editor, >> means append
%.d: %.cpp
	$(CC) $(CFLAGS) -M $< > $@
	$(CC) $(CFLAGS) -M $< | sed s/\\.o/.d/ >> $@

# automatic rule that looks like the following...
# %.o: %.cpp
#	$(CC) $(CFLAGS) -c -o $@ $<



clean:
	rm -rf $(EXE) $(DEPS) $(OBJS) *~ core


-include $(DEPS)
