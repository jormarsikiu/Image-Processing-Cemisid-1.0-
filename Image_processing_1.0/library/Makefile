# Image Processing Cemisid 1.0 Library
# Copyright (C) 2017  Jormar S. Turizo A.
#
# This file is part of the Image Processing Cemisid 1.0 Library.
# It is provided without any warranty of fitness
# for any purpose. You can redistribute this file
# and/or modify it under the terms of the GNU
# Lesser General Public License (LGPL) as published
# by the Free Software Foundation, either version 3
# of the License or (at your option) any later version.
# (see http://www.opensource.org/licenses for more info)


# MACROS MODIFICABLES
#-------------------------------------------

# Directorio de los archivos codigo fuente (.cpp)
SRC_DIR = ./src

# Directorio de los archivos de cabecera (.h)
INC_DIR = ./include

# Nombre del ejecutable
ifeq ($(MAKECMDGOALS),)
	BIN = main

else
	BIN = $(MAKECMDGOALS)

endif

#-------------------------------------------------

# Extensiones de los codigo fuentes
SRC_EXT = .cpp .CPP

# Extensiones de los archivos de cabecera
INC_EXT = .h .H

# Compilador para C++
CPP = g++

# Parametros para el compilador
CCFLAGS = -c -Wall $(shell pkg-config --cflags opencv) -w -O2 -I /usr/include -I /usr/lib -I /home/jormar/armadillo-7.800.1/include -DARMA_DONT_USE_WRAPPER -lblas -llapack -I /usr/lib/liblapack.a -I /usr/lib/libblas.a -latlas

LDFLAGS = $(shell pkg-config --libs --static opencv)

# Comando para borrar
RM = rm -f


# Busqueda de Archivos
#--------------------------------------------------

SOURCES = $(foreach d,$(SRC_DIR),$(wildcard $(addprefix $(d)/*,$(SRC_EXT))))
OBJS = $(addsuffix .o, $(basename $(SOURCES)))


# Destinos a Crear
#--------------------------------------------------

.PHONY: all objs clean

all: $(BIN)


# Creacion de los codigo objetos (.o)
#--------------------------------------------------

objs: $(OBJS)

%.o: %.cpp
	@$(CPP) -I$(INC_DIR) -c $< -o $@ $(CCFLAGS)
	@echo Se creo $@ a partir de $^;

%.o: %.CPP
	@$(CPP) -I$(INC_DIR) -c  $< -o $@ $(CCFLAGS)
	@echo Se creo $@ a partir de $^;


# Creacion del Ejecutable
#--------------------------------------------------

$(BIN): $(OBJS)
	@$(CPP) $(OBJS) -o $@ $(LDFLAGS) $(CCFLAGS)
	@echo Se creo $@ a partir de $^


# Limpieza
#--------------------------------------------------

clean:
	@$(RM) $(SRC_DIR)/*.o
