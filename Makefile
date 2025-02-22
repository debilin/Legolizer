CC=g++

OS := $(shell uname)
ifeq ($(OS),Darwin)
	OPENGLLIB= -framework OpenGL
	GLFWLIB = -lglfw3
else
	OPENGLLIB= -lGL
	GLFWLIB = -lglfw
endif

GLEWLIB= -lGLEW

LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB)
LDFLAGS=-L/usr/local/lib
CPPFLAGS=-I/usr/local/include -I./

BIN=application.out
SRCS=application.cpp gl_framework.cpp shader_util.cpp legolization/LegoBlock.cpp
INCLUDES=legolization/LegoBlock.h gl_framework.hpp shader_util.hpp application.hpp

all: $(BIN)

$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f *~ *.o $(BIN)

lego:
	cd legolization; make; ./legolization.out

prman:
	cd renderman; make;