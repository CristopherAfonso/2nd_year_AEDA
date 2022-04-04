#​Compilador 
CC = g++

#​Flags 
CFLAGS = -I -g -std=c++20 -Wall -Weffc++ -Wextra -Wpedantic -Werror
 
#​Variables 
EJECUTABLE = hash_table 
DEPSSRC = include        #​En DEPSSRC va la dirección de los .h
OBJSRC = src             #​En OBJSRC va la dirección de los .cc
OBJDIR = build           #​Dirección donde se ponen los .o
BINDIR = bin             #​Dirección donde se ponen los ejecutables/archivos binarios
 
#​############################################################################### 
#​#########################    NO TOCAR NADA DE ABAJO    ######################## 
#​############################################################################### 
  
#​############################ ARCHIVOS H ####################################### 
#​En DEPS van los archivos .h 
DEPS = $(DEPSSRC)/*.h   
DEPSCPY = $(DEPS)

#​############################ ARCHIVOS CC ###################################### 
#​Obtenemos los archivos .cc y le ponemos .o 
AUX=$(OBJSRC)/*.cc 
OBJ=$(shell echo $(AUX) | sed -r 's/.cc/.o/g' | sed -r 's/$(OBJSRC)/$(OBJDIR)/g') 


#​############################ PROGRAMA #########################################

$(OBJDIR)/%.o: src/%.cc $(DEPS) 
	$(CC) $(CFLAGS) -c -o $@ $< 

$(BINDIR)/$(EJECUTABLE): $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) 
  
	@echo "" 
  @echo ARCHIVOS .o: $(OBJ) 
  @echo ARCHIVOS .h: $(DEPSCPY) 
  @echo "" 

clean: 
	rm -rf $(OBJDIR)/*.o 

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
