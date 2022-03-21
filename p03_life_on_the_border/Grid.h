/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 3: La Vida en la Frontera
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/03/2021
 * 
 * @file Grid.h 
 * @brief Donde se aloja la declaración de la clase Grid y la declaración de
 * sus metodos. La clase Grid es una clase abstracta la cual deriva en 4 clases
 * Grid diferentes.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 22/03/22 - Funciones de la clase terminadas.
 */

#ifndef _GRID_
#define _GRID_

#include <iostream>
#include "Cell.h"

class Grid {
 public:
  virtual Cell& GetCell(const int& posx, const int& posy) = 0;
  virtual const Cell& GetCell(const int& posx, const int& posy) const = 0;
  virtual void NextGeneration(void) = 0;
  virtual ~Grid(void) {};
};

#endif