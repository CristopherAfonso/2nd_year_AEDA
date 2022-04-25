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
 * @file RadixSort.cc
 * @brief Donde se desarrollan las funciones de la clase RadixSort contenida
 * en el archivo de cabecera RadixSort.h
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

#include "../include/RadixSort.h"

/**
 * @brief Implementación del algoritmo RadixSort para ordenar datos
 * 
 * @tparam Key tipo de datos que tienen los datos a ser ordenados
 * @param vec atributo que contiene los datos a ser ordenados
 * @param n es el digito en el que queremos que se base la ordenacion, si vale
 * 0, el numero entero mas a la derecha sera el que se usara para la ordenacion
 * si vale 1, el segundo mas a la derecha entero, etc...
 */
template<typename Key>
void RadixSort<Key>::Sort(std::vector<Key>& vec, unsigned int& n) {
  std::vector<std::vector<Key>> aux(10);
  int div{10 * n}; ///< divisor del numero que nos dira su posicion
  if (div == 0) div = 1; ///< asi nunca dividiremos por cero
  for (auto i: vec) aux[((i % (10 * (n + 1)))) / div].emplace_back(i);
  
}

    // /// mostramos el vector por pantalla tras hacer la iteracion del algoritmo
    // for (auto j: vec) std::cout << j << " " << std::endl;
    // std::cout << std::endl;