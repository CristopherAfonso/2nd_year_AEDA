#Compilador
CC = g++

#Flags
CFLAGS = -I -g -std=c++17 -Wall -Weffc++ -Wextra -Wpedantic -Werror

#Variables
EJECUTABLE = hash_table


################################################################################
##########################    NO TOCAR NADA DE ABAJO    ########################
################################################################################

#En DEPSSRC va la dirección de los .h 
DEPSSRC = include

#En OBJSRC va la dirección de los .cc 
OBJSRC = src

############################# ARCHIVOS H #######################################
#En DEPS van los archivos .h
DEPS = $(DEPSSRC)/*.h
DEPSCPY = $(DEPS)

############################# ARCHIVOS CC ######################################
#Obtenemos los archivos .cc y le ponemos .o
AUX=$(OBJSRC)/*.cc
OBJ=$(shell echo $(AUX) | sed -r 's/.cc/.o/g')

############################# DIRECCIONES DE DESTINO ###########################
#Dirección donde se ponen los .o
OBJDIR = build

#Dirección donde se ponen los ejecutables/archivos binarios
BINDIR = bin

############################# PROGRAMA #########################################
%.o: %.cc $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR)/$(EJECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

	@echo ""
	@echo ARCHIVOS .o: $(OBJ)
	@echo ARCHIVOS .h: $(DEPSCPY)
	@echo ""

clean: 
	rm -rf $(OBJSRC)/*.o

cleaner:
	rm -rf $(BINDIR)/*

template:
	mkdir $(BINDIR)
	mkdir $(OBJDIR)
	mkdir $(DEPSSRC)
	mkdir $(OBJSRC)
	@echo "Plantilla creada correctamente"

show:
	@echo $(AUX)
	@echo $(OBJ)
	@echo $(DEPSCPY)
