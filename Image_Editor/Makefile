# design names
DESIGN = PhotoLab PhotoLabTest

#libs
LIBS   = libFilter.a libFileIO.a

CC     = gcc
DEBUG  = -g -DDEBUG
CFLAGS = -ansi -Wall -c
LFLAGS = -Wall
AR     = ar rc
RANLIB = ranlib

IMAGES = border.ppm \
         colorfilter.ppm \
         edge.ppm \
         hflip.ppm \
         negative.ppm \
         vmirror.ppm \
         whatever.ppm \
         zoom.ppm \
         shuffle.ppm \
         posterize.ppm \
         noise.ppm

all: PhotoLab PhotoLabTest


########### generate object files ###########
#target to generate PhotoLab.o
PhotoLab.o: PhotoLab.c
	$(CC) $(CFLAGS) PhotoLab.c -o PhotoLab.o

#target to generate FileIO.o
FileIO.o: FileIO.h FileIO.c
	$(CC) $(CFLAGS) FileIO.c -o FileIO.o

#target to generate DIPs.o
DIPs.o: DIPs.h DIPs.c
	$(CC) $(CFLAGS)  DIPs.c -o DIPs.o

#target to generate Advanced.o
Advanced.o: Advanced.h Advanced.c
	$(CC) $(CFLAGS) -c Advanced.c -o Advanced.o

#target to generate FileIO_DEBUG.o
FileIO_DEBUG.o: FileIO.h FileIO.c
	$(CC) $(CFLAGS) $(DEBUG) -c FileIO.c -o FileIO_DEBUG.o

#target to generate Advanced_DEBUG.o
Advanced_DEBUG.o: Advanced.h Advanced.c
	$(CC) $(CFLAGS) $(DEBUG) -c Advanced.c -o Advanced_DEBUG.o

#target to generate FileIO_DEBUG.o
PhotoLab_DEBUG.o: PhotoLab.c
	$(CC) $(CFLAGS) $(DEBUG) -c PhotoLab.c -o PhotoLab_DEBUG.o


########### generate library files ###########
#target to generate libFileIO.a
libFileIO.a: FileIO.o
	$(AR) libFileIO.a FileIO.o
	$(RANLIB) libFileIO.a

#target to generate libFilter.a
libFilter.a: DIPs.o Advanced.o
	$(AR) libFilter.a Advanced.o DIPs.o
	$(RANLIB) libFilter.a


########### generate executables ###########
#target to generate PhotoLab
PhotoLab: PhotoLab.o libFileIO.a libFilter.a
	$(CC) $(LFLAGS) PhotoLab.o -lFileIO -lFilter -L. -o PhotoLab

#target to generate test
PhotoLabTest: PhotoLab_DEBUG.o FileIO_DEBUG.o DIPs.o Advanced_DEBUG.o
	$(CC) $(lflags) $(DEBUG) PhotoLab_DEBUG.o FileIO_DEBUG.o DIPs.o Advanced_DEBUG.o -o PhotoLabTest


#target to clean the directory
clean:
	rm -f *.o *.jpg $(DESIGN) $(IMAGES) $(LIBS)

