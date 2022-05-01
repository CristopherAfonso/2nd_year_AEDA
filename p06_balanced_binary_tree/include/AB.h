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
 * @file AB.h 
 * @brief Donde se aloja la declaración de la clase AB y la declaracion
 * de sus metodos. La clase AB es una clase abstracta la cual es una
 * implementación del Tipo de Dato Abstracto de Arbol Binario, sus clases hijas
 * cada una es una implementación de un tipo deferente de un arbol binario,
 * esta clase define los métodos y atributos comunes a todas ellas
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

#ifndef _AB_
#define _AB_

#include <iostream>
#include <queue>

#include "NodoB.h"

/**
 * @brief Clase que implementa un arbol binario generico, clase abstracta
 * 
 * @tparam Key tipo de dato del dato que se guardará en cada nodo del arbol
 */
template<class Key>
class AB {
 public:
  AB(const NodoB<Key>& nodo = NULL);
  virtual ~AB() = default;

  virtual bool Insert(const Key& data) = 0;
  virtual bool Search(const Key& data) const = 0;
  void Inorder(const NodoB<Key>& nodo = NULL) const;
  void LevelTour(const NodoB<Key>& nodo = NULL) const;

  template<typename T>
  friend std::ostream& operator<<(std::ostream& out, const AB<T>& ab);

 protected:
  NodoB<Key>* root_;
};

#endif