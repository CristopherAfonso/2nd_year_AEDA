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
 * @file NodoB.h 
 * @brief Donde se aloja la declaración de la clase NodoB y la declaracion
 * de sus metodos. La clase NodoB es una clase que implementa un nodo binario
 * de un arbol binario, contiene dos punteros y un dato.
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

#ifndef _NODOB_
#define _NODOB_

#include <iostream>


/**
 * @brief Clase que implementa un nodo binario de un arbol binario
 * 
 * @tparam Key Es el tipo de dato del dato que se guardará en el nodo
 */
template<class Key>
class NodoB {
 public:
  NodoB(void);
  NodoB(const Key& data, NodoB<Key>* izdo = NULL, NodoB<Key>* dcho = NULL);

  Key GetData(void) const;
  NodoB<Key>* GetPtrIzdo(void) const;
  NodoB<Key>* GetPtrDcho(void) const;
  void SetData(const Key& data);
  void SetPtrIzdo(NodoB<Key>* izdo = NULL);
  void SetPtrDcho(NodoB<Key>* dcho = NULL);

  NodoB<Key>& operator=(const NodoB<Key>& nodo);
  template<typename T>
  friend std::ostream& operator<<(std::ostream& out, const NodoB<T>& nodo);

 private:
  Key data_;
  NodoB<Key>* izdo_;
  NodoB<Key>* dcho_;
};

#endif