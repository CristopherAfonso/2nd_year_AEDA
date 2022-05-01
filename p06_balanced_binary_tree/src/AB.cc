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
 * @brief Metodo que recorre el arbol binario siguiendo el algoritmo de inorden
 * 
 * @tparam Key es el tipo de dato que guardan los nodos del arbol
 */
template<typename Key>
void AB<Key>::Inorder(const NodoB<Key>& nodo) const {
  if (nodo == NULL) return;
  this->Inorder(nodo->GetPtrIzdo());
  std::cout << nodo->GetData() << " ";
  this->Inorder(nodo->GetPtrDcho());
}

/**
 * @brief Metodo que permite recorrer un nodo y sus subarboles segun el
 * algoritmo de recorrido por niveles
 * 
 * @tparam Key tipo de dato que guardan los nodos del arbol
 * @param nodo es donde empezamos el recorrido descendente
 */
template<typename Key>
void AB<Key>::LevelTour(const NodoB<Key>& nodo) const {
  
}

/**
 * @brief Sobrecarga del operador << que permite ver el arbol binario siguiendo
 * el algoritmo de recorrido por niveles
 * 
 * @tparam T tipo de dato que guardan los nodos del arbol
 * @param out salida estandar a la que vamos a mostrar los datos
 * @param ab arbol binario que queremos mostrar
 * @return std::ostream& es lo que se va a mostrar por pantalla
 */
template<typename T>
std::ostream& operator<<(std::ostream& out, const AB<T>& ab) {
  
  return out;
}
