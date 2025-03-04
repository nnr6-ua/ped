
CC=g++
OPTIONS= -g
DEBUG= #-D DEBUG

LIBDIR=lib
INCLUDEDIR=include

_OBJ= tporo.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ)) #Añade la ruta (se quedaría lib/tporo.o)

tad:    src/tad.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad.cpp $(OBJ) -o tad

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

clean:
	rm -f $(OBJ) 
