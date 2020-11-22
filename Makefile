CC		:= g++
CFLAGS	:= -std=c++20 -Wall -Wextra -g

CINCLUDES	:= -Iinclude

SOURCES		:= $(wildcard $(patsubst %,%/*.cpp, src))
OBJECTS		:= $(patsubst src%, bin%, $(SOURCES:.cpp=.o))

EXE			:= bin/lineWriter

all: clean $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@
	-$(RM) $(OBJECTS)

$(OBJECTS): bin
	$(eval OFILE := $@)
	$(eval SFILE := $(patsubst bin/%.o, src/%.cpp, $(OFILE)))
	$(CC) -c -o $(OFILE) $(SFILE)

bin:
	mkdir bin

.PHONY: clean
clean: 
	-$(RM) $(EXE)
