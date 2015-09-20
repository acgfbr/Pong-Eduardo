#Compilador
CC=gcc

#Opções de compilação
CFLAGS=-ggdb -c -Werror -Wall -Wformat=0 

#Linkagem de libs
LDFLAGS  = `sdl2-config --libs` \
			-lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx -lSDL2_mixer

#Arquivos sources para compilação
SOURCES=main.c pong.c 

#Nome dos arquivos objetos que serão gerados
OBJECTS=$(SOURCES:.c=.o)

#Executável final
EXECUTABLE=Pong

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

Clean:
	rm *.o
