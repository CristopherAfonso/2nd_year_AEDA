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
 * @file AB.cc
 * @brief Donde se desarrollan las funciones de la clase AB contenida
 * en el archivo de cabecera AB.h
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

#include "../include/AB.h"

/**
 * @brief Constructor de la clase AB, constructor que usaran sus clases hijas
 * 
 * @tparam Key tipo de dato del dato que guardan los nodos del arbol
 * @param nodo nuevo nodo raiz del arbol
 */
template<typename Key>
AB<Key>::AB(const NodoB<Key>& nodo) : root_(nodo) {}

/**
 * @brief metodo de extraccion que muestra el arbol binario por el algoritmo de
 * niveles
 * 
 * @tparam T tipo de dato de los datos del arbol binario
 * @param out flujo de salida estandar
 * @param ab puntero que contiene a una clase hija de la clase AB el cual
 * queremos imprimir su arbol
 * @return std::ostream& el metodo retorna una serie de caracteres a imprimir
 */
template<typename T>
std::ostream& operator<<(std::ostream& out, const AB<T>* ab) {
  std::queue<T> queue_aux;
  NodoB<T>* nodo_aux();
  int level{0};
  int current_level{0};
  queue_aux.push(ab->root_, 0);
  while (!queue_aux.empty()) {
    queue_aux.pop(nodo_aux, level);
    if (level > current_level) {
      current_level = level;
      std::cout << "\n";
    }
    if (nodo_aux != nullptr) {
      std::cout << "[" << *nodo_aux << "]";
      queue_aux.push(nodo_aux->GetPtrIzdo(), level + 1);
      queue_aux.push(nodo_aux->GetPtrDcho(), level + 1);
    } else std::cout << "[.]";
  }
  return out;
}

/**
 * @brief Cambiamos el valor del atributo root_ por el dado al metodo
 * 
 * @tparam Key tipo de dato del arbol
 * @param root nuevo valor del atributo root_
 */
template<typename Key>
void AB<Key>::SetRoot(const NodoB<Key>* root) { root_ = root; }

/**
 * @brief Retornamos el puntero del atributo root_
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return NodoB<Key>* puntero que apunta a la raiz del arbol
 */
template<typename Key>
NodoB<Key>* AB<Key>::GetRoot(void) { return root_; }
