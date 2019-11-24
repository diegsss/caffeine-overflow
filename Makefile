CFLAGS = -I ./include
CPP = escape_from_grass.cpp log.cpp timers.cpp Image.cpp diegoC.cpp joseC.cpp fahadA.cpp rayanA.cpp
LFLAGS = -lrt -lX11 -lGLU -lGL -pthread -lm #-lXrandr
FONT = libggfonts.a
all: escape_from_grass

escape_from_grass: $(CPP)
	g++ $(CFLAGS) $(CPP) $(FONT) -Wall -Wextra $(LFLAGS) -oescape_from_grass

clean:
	rm -f asteroids
	rm -f *.o

