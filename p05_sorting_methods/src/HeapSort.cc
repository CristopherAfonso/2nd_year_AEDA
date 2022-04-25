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
 * @file HeapSort.cc
 * @brief Donde se desarrollan las funciones de la clase HeapSort contenida
 * en el archivo de cabecera HeapSort.h
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

#include "../include/HeapSort.h"

/**
 * @brief Implementación del algoritmo HeapSort para ordenar datos
 * 
 * @tparam Key tipo de datos que tienen los datos a ser ordenados
 * @param vec atributo que contiene los datos a ser ordenados
 * @param n es el tamaño del atributo vec
 */
template<typename Key>
void HeapSort<Key>::Sort(std::vector<Key>& vec, unsigned int& n) {
  /// Fase 1, inserciones
  for (int i{n / 2}; i > 0; --i) {
    *this->PushDown(i, vec, n);
    for (auto j: vec) std::cout << j << " " << std::endl;
  }
  std::cout << std::endl;
  
  /// Fase 2, extracciones
  for (int i{n}; i > 1; --i) {
    *this->Swap(vec[1], vec[i]);
    *this->PushDown(1, vec, i - 1);
    for (auto j: vec) std::cout << j << " " << std::endl;
  }
  std::cout << std::endl;
}

/**
 * @brief Metodo que se encarga de bajar (desplazar a la derecha del vector)
 * los valores mas pequeños de un vector
 * 
 * @tparam Key tipo de datos de los datos que van a ser ordenados
 * @param i posicion en el vector del elemento que queremos bajar
 * @param vec contenedor de los datos a ordenar
 * @param n tamaño del vector
 */
template<typename Key>
void HeapSort<Key>::PushDown(int i, std::vector<Key>& vec, int n) {
  int son{0};
  int son_first{0};
  int son_second{0};
  while ((2 * i) <= n) {
    son_first = 2 * i;
    son_second = son_first + 1;
    if (son_first == n) son = son_first;
    else if (vec[son_first] > vec[son_second]) son = son_first;
    else son = son_second;

    if (vec[son] <= vec[i]) break;
    else {
      *this->Swap(vec[i], vec[son]);
      i = son;
    }
  }
}

/**
 * @brief Metodo que intercambia dos datos de tipo Key
 * 
 * @tparam Key tipo de dato que tienen los datos a ser ordenados
 * @param i dato 1 a intercambiarse con el dato 2
 * @param j dato 2 a intercambiarse con el dato 1
 */
template<typename Key>
void HeapSort<Key>::Swap(Key& i, Key& j) {
  Key aux{i};
  i = j;
  j = aux;
}
