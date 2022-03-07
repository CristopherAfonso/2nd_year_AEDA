/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 1: El Juego de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/03/2021
 * 
 * @file Grid.h 
 * @brief Donde se aloja la declaración de la clase Grid y la declaracion
 * de sus metodos. La clase Grid es una matriz dinámica de objetos Cell, la
 * cual será el escenario de nuestro programa "El Juego de la Vida".
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 05/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 06/03/22 - Funciones de la clase terminadas.
 */

#ifndef _GRID_
#define _GRID_

#include <iostream>
#include "Cell.h"

/**
 * @class Grid.
 * @brief El Juego de la Vida consiste en una Rejilla (Grid en ingles), la cual
 * debe ser rellenada con Células (objetos tipo Cell) vivas o muertas, esta
 * clase define el objeto Grid, sus atributos y funciones.
 */
class Grid {
 public:
  /// Constructores.
  Grid(void);
  Grid(const int& rows, const int& cols);
  Grid(const Grid&  grid);

  /// Destructores.
  ~Grid(void);

  /// Setters.
  /// Getters.
  const Cell& GetCell(const int& posx, const int& posy) const;
  const Cell& GetCell(const std::pair<int, int> postion) const;

  /// Funciones de la Clase (Métodos).
  void GameLife(const int& kGameTurns);
  void NextGeneration(void);

  /// Operadores Sobrecargados.
  Grid& operator=(const Grid& grid);

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const Grid& grid);

 private:
  Cell** grid_;
};
#endif