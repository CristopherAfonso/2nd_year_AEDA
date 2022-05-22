/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 8: Árbol binario AVL
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/05/2022
 * 
 * @file NodoAVL.h 
 * @brief Donde se aloja la declaración de la clase NodoAVL y la declaracion
 * de sus metodos. La clase NodoAVL es una clase que implementa un nodo binario
 * de un arbol binario AVL, contiene dos punteros y un dato.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/05/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 21/05/22 - Archivo terminado.
 */

#ifndef _NODOAVL_
#define _NODOAVL_

#include <iostream>

#include "NodoB.h"

/**
 * @brief clase nodo explícitamente creada para la clase NodoAVL
 * 
 * @tparam tipo de dato del dato que contiene el nodo
 */
template<class Key>
class NodoAVL : public NodoB<Key> {
 public:
  NodoAVL(void);
  NodoAVL(const Key& data, NodoAVL<Key>* izdo = NULL, NodoAVL<Key>* dcho = NULL);
  ~NodoAVL() = default;
  void SetBal(const int& bal);
  int GetBal(void);

 private:
  int bal_; ///< contiene el factor de balanceo del nodo
};

/**
 * @brief Constructor por defecto de la clase
 * 
 * @tparam Key tipo de dato del dato del nodo
 */
template<typename Key>
NodoAVL<Key>::NodoAVL(void) : NodoB<Key>::NodoB(), bal_(0) {
  reinterpret_cast<NodoAVL<Key>*>(this->izdo_);
  reinterpret_cast<NodoAVL<Key>*>(this->dcho_);
}

/**
 * @brief Construct a new Nodo A V L< Key>:: Nodo A V L object
 * 
 * @tparam Key 
 * @param data 
 * @param izdo 
 * @param dcho 
 */
template<typename Key>
NodoAVL<Key>::NodoAVL(const Key& data, NodoAVL<Key>* izdo, NodoAVL<Key>* dcho)
    : NodoB<Key>::NodoB(data, izdo, dcho), bal_(0) {
  reinterpret_cast<NodoAVL<Key>*>(this->izdo_);
  reinterpret_cast<NodoAVL<Key>*>(this->dcho_);
}

/**
 * @brief Setter del atributo bal_, que nos dice la diferencia de alturas entre
 * las dos ramas del nodo
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @param bal nuevo valor del atributo bal_
 */
template<typename Key>
void NodoAVL<Key>::SetBal(const int& bal) { bal_ = bal; }

/**
 * @brief Getter del atributo bal_
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @return int es el valor de bal_
 */
template<typename Key>
int NodoAVL<Key>::GetBal(void) { return bal_; }

#endif