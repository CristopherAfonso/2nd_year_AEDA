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
 * @file ABE.h 
 * @brief Donde se aloja la declaración de la clase ABE y la declaracion
 * de sus metodos. La clase ABE es una clase hija de la clase AB, la clase ABE
 * es una implementacion de un arbol binario perfectamente equilibrado
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

#ifndef _ABE_
#define _ABE_

#include <iostream>

#include "AB.h"

/**
 * @brief implementacion de una clase que es un arbol binario equilibrado
 * 
 * @tparam Key tipo de dato de los datos del arbol binario equilibrado
 */
template<class Key>
class ABE : public AB<Key> {
 public:
  ABE(const NodoB<Key>* nodo = nullptr);
  bool Insert(const Key& data) override;
  bool Search(const Key& data) const override;
  bool Delete(const Key& data) override;
  bool Balanced(void) const;
  
 private:
  int SubtreeSize(const NodoB<Key>* nodo) const;
  bool BalancedBranch(NodoB<Key>* nodo) const;
};

#endif