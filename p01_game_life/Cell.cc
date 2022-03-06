/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 1: El Juego de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/03/2022
 * 
 * @file Cell.cc
 * @brief Donde se desarrollan las funciones de la clase Cell contenida
 * en el archivo de cabecera Cell.h
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

#include "Cell.h"

Cell::Cell(void) : state_(0), position_({-1, -1}), neighbors_alive_(0) {}

Cell::Cell(const State& state) 
    : state_(state), position_({-1, -1}), neighbors_alive_(0) {}

Cell::Cell(const State& state, const std::pair<int, int>& position) 
    : state_(state), position_(position), neighbors_alive_(0) {}

