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
 * @file TestOrdenation.cc
 * @brief Donde se desarrollan las funciones de la clase TestOrdenation contenida
 * en el archivo de cabecera TestOrdenation.h
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

#include "../include/TestOrdenation.h"

/**
 * @brief Setter del atributo n_, dependiendo del metodo de ordenacion, este
 * atributo tendra una u otra funcion dentro del algoritmo
 * 
 * @tparam Key Tipo de dato que tienen los datos a ser ordenados
 * @param n parametro que ayuda al algoritmo a poder ser aplicado, para saber
 * su funcionalidad exacta, deberia consultar el algoritmo particular a usar
 * para saberlo, cada algoritmo puede usar este parametro para distintos fines
 */
template <typename Key>
void TestOrdenation<Key>::SetN(const unsigned int& n) { n_ = n; }

/**
 * @brief Setter del atributo interno 'vec_', este atributo contiene los datos
 * que van a ser ordenados
 * 
 * @tparam Key tipo de dato que tienen los datos a ser ordenados (que estan
 * contenidos en el atributo interno 'vec_')
 * @param vec es el contenedor de los datos que vamos a ordenar
 */
template <typename Key>
void TestOrdenation<Key>::SetVec(const std::vector<Key>& vec) { vec_ = vec; }

/**
 * @brief Setter del atributo interno 'strategy_', este atributo decide cual
 * sera el algoritmo de ordenacion que se seguira para ordenar los datos
 * 
 * @tparam Key tipo de dato que tienen los datos a ser ordenados
 * @param strategy atributo que decide cual sera el algoritmo de ordenacion
 * que se seguira para ordenar los datos
 */
template <typename Key>
void TestOrdenation<Key>::SetStrategy(Strategy<Key>* strategy) {
  strategy_ = strategy;
}

/**
 * @brief Metodo que se encarga de coger todos los atributos internos del
 * objeto para aplicar el algoritmo de ordenacion que se haya indicado
 * 
 * @tparam Key tipo de dato que tienen los datos a ser ordenados
 */
template<typename Key>
void TestOrdenation<Key>::Execute(void) {

}
