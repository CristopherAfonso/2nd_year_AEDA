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
 * @file ShellSort.cc
 * @brief Donde se desarrollan las funciones de la clase ShellSort contenida
 * en el archivo de cabecera ShellSort.h
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

#include "../include/ShellSort.h"

/**
 * @brief Implementación del algoritmo ShellSort para ordenar datos
 * 
 * @tparam Key tipo de datos que tienen los datos a ser ordenados
 * @param vec atributo que contiene los datos a ser ordenados
 * @param n es el tamaño del parametro vec
 */
template<typename Key>
void ShellSort<Key>::Sort(std::vector<Key>& vec, unsigned int& n) {
  unsigned int delta{n};
  while (delta > 1) {
    delta = delta / 2;
    *this->DeltaSort(delta, vec, n);
  }
}

/**
 * @brief Metodo que se encarga de ordenar cada subconjunto denominado
 * ordenacion en el algoritmo ShellSort
 * 
 * @tparam Key tipo de dato de los datos a ser ordenados
 * @param delta numero de subsecuencias o ordenaciones dentro de nuestros datos
 * @param vec contenedor de los datos a ser ordenados
 * @param n tamaño del parametro vec
 */
template<typename Key>
void ShellSort<Key>::DeltaSort(const unsigned int& delta, std::vector<Key>& vec, const unsigned int& n) {
  for (int i{delta}; i < n; ++i) {
    Key x{vec[i]};
    int j{i};
    while ((j >= delta) && (x < vec[j - delta])) {
      vec[j] = vec[j - delta];
      j = j - delta;
    }
    vec[j] = x;
    for (auto j: vec) std::cout << j << " " << std::endl;
    std::cout << std::endl;
  }
}
