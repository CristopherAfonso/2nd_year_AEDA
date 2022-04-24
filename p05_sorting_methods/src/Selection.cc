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
 * @file Selection.cc
 * @brief Donde se desarrollan las funciones de la clase Selection contenida
 * en el archivo de cabecera Selection.h
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

#include "../include/Selection.h"



// /**
//  * @brief Algoritmo de seleccion que ordena un vector siguiendo una secuencia
//  * por la cual intercambia elementos del vector entre si hasta ordenarlo
//  * 
//  * @tparam Key Tipo de dato que almacena este vector
//  * @param vec vector a ordenar
//  * @param size_vec numero de elementos al principio del vector que ya ordenados
//  */
// template<class Key>
// void Selection(std::vector<Key>& vec, const int& size_vec) {
//   Key aux; ///< Valor a poner en la parte ordenada en cada iteracion
//   for (int i{0}; i < (n - 1); ++i) {
//     int min_pos{i};
//     for (int j{i + 1}; j < n; ++j) {
//       if (vec[j] < vec[min_pos]) {
//         min_pos = j;
//         aux = vec[min_pos];
//       }
//     }

//     vec[min_pos] = vec[i];
//     vec[i] = aux;
//   }
// }
