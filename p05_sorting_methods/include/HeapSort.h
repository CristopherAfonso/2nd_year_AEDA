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
 * @file HeapSort.h 
 * @brief Donde se aloja la declaración de la clase HeapSort y la declaracion
 * de sus metodos. La clase HeapSort es una clase hija de la clase Strategy y
 * representa una instanciacion del algoritmo de ordenacion de HeapSort
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

#ifndef _HEAPSORT_
#define _HEAPSORT_

#include "Strategy.h"

/**
 * @brief Esta clase representa la implementación del algoritmo de ordenacion
 * HeapSort
 * 
 * @tparam Key Es el tipo de dato de los datos que queremos ordenar
 */
template<class Key>
class HeapSort: public Strategy<Key> {
 public:
  void Sort(std::vector<Key>& vec, unsigned int& n) override;
  
 private:
  void PushDown(int i, std::vector<Key>& vec, int n);
  void Swap(Key& i, Key& j);
};

#endif