/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 6: Árbol binario equilibrado
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 01/05/2022
 * 
 * @file ABE.cc
 * @brief Donde se desarrollan las funciones de la clase ABE contenida
 * en el archivo de cabecera ABE.h
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 01/05/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 08/05/22 - Archivo terminado.
 */

#include "../include/ABE.h"

/**
 * @brief Constructor de la clase ABE
 * 
 * @tparam Key tipo de dato del dato que guardan los nodos del arbol
 * @param nodo nuevo nodo raiz del arbol
 */
template<typename Key>
ABE<Key>::ABE(const NodoB<Key>* nodo) : AB<Key>::AB(nodo) {}

/**
 * @brief Metodo que se encarga de insertar un nodo en el arbol en donde el
 * metodo considere que debe ir el nuevo nodo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data nodo nuevo a introducir en el arbol
 * @return true el nodo se inserto correctamente en el arbol
 * @return false el nodo no se pudo insertar en el arbol
 */
template<typename Key>
bool ABE<Key>::Insert(const Key& data) {
  bool result{false};

  return result;
}

/**
 * @brief metodo que se encarga de buscar un dato en el arbol para comprobar si
 * se encuentra en el arbol o si este no esta en el arbol
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data es el dato a buscar en el arbol
 * @return true el dato si se encuentra dentro del arbol
 * @return false el dato no se encuentra dentro del arbol
 */
template<typename Key>
bool ABE<Key>::Search(const Key& data) const {
  bool result{false};

  return result;
}

/**
 * @brief Metodo que se encarga de buscar en el arbol un nodo que se le pasa
 * como argumento, y si lo encuentra en el arbol, lo borra, sino lo encuentra
 * no hace nada
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data es el nodo a buscar en el arbol para borrar
 * @return true el nodo se encontro en el arbol y se borro correctamente
 * @return false el nodo no se encontro en el arbol
 */
template<typename Key>
bool ABE<Key>::Delete(const Key& data) {
  throw "error, operacion no permitida en este objeto";
  return false;
}
