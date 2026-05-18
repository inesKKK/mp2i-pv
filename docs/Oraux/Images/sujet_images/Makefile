# requires libsdl2-dev libsdl2-image-dev

CFLAGS=$$(pkg-config --cflags --libs sdl2) -Wall  -lSDL2_image -lm

debug:
	gcc image.c $(CFLAGS) -g -o image 

all:
	gcc image.c $(CFLAGS) -O2 -o image 

clean:
	rm image
