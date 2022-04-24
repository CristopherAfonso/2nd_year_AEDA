/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 5: Implementación de Métodos de Ordenación
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/04/2022
 * 
 * @file TestOrdenation.h 
 * @brief Donde se aloja la declaración de la clase TestOrdenation y la
 * declaracion de sus metodos. La clase TestOrdenation es una clase que
 * encapsula distintos metodos de ordenacion de datos (almacenados en un
 * vector) en un solo objeto, para que dependiendo del metodo elegido, este se
 * ejecute usando el mismo objeto y simplificando el programa.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/04/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 23/04/22 - Archivo terminado.
 */

#ifndef _TESTORDENATION_
#define _TESTORDENATION_

#include "../include/Strategy.h"

/**
 * @brief Clase que encapsula un metodo de ordenacion de datos y unos datos, y
 * ordena los datos usando el metodo que guarda
 * 
 * @tparam Key Es el tipo de dato que tienen los datos a ordenar.
 */
template <typename Key>
class TestOrdenation {
 public:
  TestOrdenation(void);
  void SetN(const unsigned int& n);
  void SetVec(const std::vector<Key>& vec);
  void SetStrategy(Strategy<Key>* strategy);
  void Execute(void);

 private:
  unsigned int n_;
  std::vector<Key> vec_;
  Strategy<Key>* strategy_;
};

#endif