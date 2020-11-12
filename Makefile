CC		:= g++
CFLAGS	:= -std=c++20 -Wall -Wextra -g

CINCLUDES	:= -Iinclude

SOURCES		:= $(wildcard $(patsubst %,%/*.cpp, src))
OBJECTS		:= $(patsubst src%, bin%, $(SOURCES:.cpp=.o))

SERVER		:= ~/Documents/Coding/Web/Server_Laptop/cpp

EXE			:= cppWriteLine
SERVEREXE 	:= $(SERVER)/$(EXE)

all: $(SERVEREXE)

$(SERVEREXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@
	-$(RM) $(OBJECTS)

$(OBJECTS): bin
	-$(RM) $(SERVEREXE)
	$(eval OFILE := $@)
	$(eval SFILE := $(patsubst bin/%.o, src/%.cpp, $(OFILE)))
	$(CC) -c -o $(OFILE) $(SFILE)

bin:
	mkdir bin

.PHONY: clean
clean:
	-$(RM) $(SERVEREXE)
	-$(RM) $(OBJECTS)
