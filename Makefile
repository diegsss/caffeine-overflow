CFLAGS = -I ./include
CPP = asteroids.cpp log.cpp timers.cpp Image.cpp diegoC.cpp joseC.cpp fahadA.cpp rayanA.cpp
LFLAGS = -lrt -lX11 -lGLU -lGL -pthread -lm #-lXrandr
FONT = libggfonts.a
all: asteroids

asteroids: $(CPP)
	g++ $(CFLAGS) $(CPP) $(FONT) -Wall -Wextra $(LFLAGS) -oasteroids

clean:
	rm -f asteroids
	rm -f *.o

