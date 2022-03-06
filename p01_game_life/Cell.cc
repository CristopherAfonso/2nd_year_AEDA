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

/**
 * @brief Constructor por defecto definido. 
 */
Cell::Cell(void) : state_(0), position_({-1, -1}), neighbors_alive_(0) {}

/**
 * @brief Constructor basico, que define el estado, pero no la posicion.
 * 
 * @param state estado de la celula.
 */
Cell::Cell(const State& state) 
    : state_(state), position_({-1, -1}), neighbors_alive_(0) {}

/**
 * @brief Constructor basico que define el estado y la posicion de la celula
 * en la Rejilla, este lo hace usando directamente un dato de tipo
 * std::pair<int, int>.
 * 
 * @param state Estado de la celula.
 * @param position Posicion en 2D de la celula en la Rejilla.
 */
Cell::Cell(const State& state, const std::pair<int, int>& position) 
    : state_(state), position_(position), neighbors_alive_(0) {}

/**
 * @brief Constructor basico que define el estado y la posicion de la celula
 * en la Rejilla, este lo hace cogiendo dos numeros que serán sus posiciones
 * en los ejes 'X' e 'Y'.
 * 
 * @param state Estado de la celula.
 * @param posx Posición en el eje 'X'
 * @param posy Posición en el eje 'Y'
 */
Cell::Cell(const State& state, const int& posx, const int& posy)
    : state_(state), position_({posx, posy}), neighbors_alive_(0) {}

/**
 * @brief Constructor de copia de la celula, el constructor llama al operador =
 * de la clase para crear el nuevo objeto Cell.
 * 
 * @param cell Objeto tipo Cell el cual, el neuvo objeto que va a ser creado
 * copiará.
 */
Cell::Cell(const Cell& cell) {
  *this = cell;
}

/**
 * @brief Funcion que cambia el atributo interno de la celula llamado 'state_'
 * por el dado al método (State es un int).
 * 
 * @param state Dato de tipo int que sustituirá al state_ de la celula.
 */
void Cell::SetState(const State& state) {state_ = state;}

/**
 * @brief Función que solo modifica la posición en el eje 'X' de la celula.
 * 
 * @param posx Posición nueva en el eje 'X' solo donde nuestra celula estara.
 */
void Cell::SetPosX(const int& posx) {position_.first = posx;}

/**
 * @brief Función que solo modifica la posición en el eje 'Y' de la celula.
 * 
 * @param posy Posición nueva en el eje 'Y' solo donde nuestra celula estara.
 */
void Cell::SetPosY(const int& posy) {position_.second = posy;}

/**
 * @brief Función que modifica la posición en el eje 'X' y 'Y' de nuestra
 * celula. La posición está contenida en un dato de tipo std::pair<int, int>,
 * donde el primer elemento es la posición en el eje 'X' y el segundo en el eje
 * 'Y' de nuestra celula.
 * 
 * @param position Nueva posición de nuestra celula.
 */
void Cell::SetPos(const std::pair<int, int> position) {position_ = position;}

/**
 * @brief Función que modifica la posición en el eje 'X' y 'Y' de nuestra
 * celula. La posición está contenida en un dato de tipo std::pair<int, int>,
 * donde el primer elemento es la posición en el eje 'X' y el segundo en el eje
 * 'Y' de nuestra celula.
 * 
 * @param posx Nueva posicion en el eje 'X' de nuestra celula.
 * @param posy Nueva posicion en el eje 'Y' de nuestra celula.
 */
void Cell::SetPos(const int& posx, const int& posy) {
  position_.first = posx;
  position_.second = posy;
}