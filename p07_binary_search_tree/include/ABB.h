/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 7: Árbol binario de busqueda
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 15/05/2022
 * 
 * @file ABB.h 
 * @brief Donde se aloja la declaración de la clase ABB y la declaracion
 * de sus metodos. La clase ABB es una clase hija de la clase AB, la clase ABB
 * es una implementacion de un arbol binario de busqueda
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 15/05/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 17/05/22 - Archivo terminado.
 */

#ifndef _ABB_
#define _ABB_

#include <iostream>

#include "AB.h"

/**
 * @brief implementacion de una clase que es un arbol binario de busqueda
 * 
 * @tparam Key tipo de dato de los datos del arbol binario equilibrado 
 */
template<class Key>
class ABB : public AB<Key> {
 public:
  ABB(void);
  bool Insert(const Key& data) override;
  bool Search(const Key& data) const override;
  bool Delete(const Key& data) override;
  
 private:
  
};

#endif