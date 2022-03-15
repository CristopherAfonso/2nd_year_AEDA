/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 2: El Ciclo de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 13/03/2021
 * 
 * @file StateAdult.h 
 * @brief Donde se aloja la declaración de la clase StateAdult y la declaracion
 * de sus metodos. La clase StateAdult es una clase de 5 clases de las cuales
 * cada una representa un estado de una celula.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 13/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 15/03/22 - Funciones de la clase terminadas.
 */

#ifndef _STATEADULT_
#define _STATEADULT_

#include <iostream>
#include "State.h"
#include "Grid.h"
#include "Cell.h"

class StateAdult : public State {
 public:
  int Neighbors(const Grid& grid, const int& i, const int& j) override;
  State* NextState(void) override;
  char GetState(void) const override;

 private:
  int neighbors_adult_{0};
};

#endif