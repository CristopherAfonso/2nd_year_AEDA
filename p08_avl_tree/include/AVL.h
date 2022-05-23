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
 * @file AVL.h 
 * @brief Donde se aloja la declaración de la clase AVL y la declaracion
 * de sus metodos. La clase AVL es una clase hija de la clase ABB, la clase AVL
 * es una implementacion de un arbol binario de busqueda la cual diferencia de
 * altura de los dos subarboles no supera la unidad.
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

#ifndef _AVL_
#define _AVL_

#include <iostream>

#include "ABB.h"
#include "NodoAVL.h"

/**
 * @brief clase que implanta un arbol binario AVL
 * 
 * @tparam Key tipo de dato de los datos del arbol
 */
template<class Key>
class AVL : public ABB<Key> {
 public:
  AVL(bool traza = false, NodoAVL<Key>* nodo = nullptr);
  bool Insert(const Key& data) override;
  bool Delete(const Key& data) override;

 protected:
  void SetRoot(NodoAVL<Key>* root);
  NodoAVL<Key>*& GetRoot(void);
  NodoAVL<Key>* GetRoot(void) const;
  
 private:
  bool traza_{false};
  void Rotacion_II(NodoAVL<Key>* &nodo);
  void Rotacion_DD(NodoAVL<Key>* &nodo);
  void Rotacion_ID(NodoAVL<Key>* &nodo);
  void Rotacion_DI(NodoAVL<Key>* &nodo);
  void InsertaBal(NodoAVL<Key>* &root, NodoAVL<Key>* &nuevo, bool& crece);
  void InsertReBalanceaIzda(NodoAVL<Key>* &nodo, bool& crece);
  void InsertReBalanceaDcha(NodoAVL<Key>* &nodo, bool& crece);
  void DeleteBranch(NodoAVL<Key>* &nodo, const Key& data, bool& decrece);
  void Replace(NodoAVL<Key>* &eliminado, NodoAVL<Key>* &sust, bool& decrece);
  void DeleteReBalanceaIzda(NodoAVL<Key>* &nodo, bool& decrece);
  void DeleteReBalanceaDcha(NodoAVL<Key>* &nodo, bool& decrece);
};

/**
 * @brief Constructor de la clase AVL
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param traza le decimos a la clase si queremos tener un seguimiento de los
 * cambios que se produciran en el arbol
 * @param nodo sera el nodo root del arbol
 */
template<typename Key>
AVL<Key>::AVL(bool traza, NodoAVL<Key>* nodo) : traza_(traza) {
  this->AB<Key>::SetRoot(nodo);
}

/**
 * @brief Metodo que se encarga de insertar un dato en el arbol
 * 
 * @tparam Key tipo de dato de los nodos del arbol
 * @param data es el dato que ira en el nodo a insertar
 * @return true el nodo se inserto correctamente en el arbol
 * @return false el nodo no se inserto correctamente en el arbol
 */
template<typename Key>
bool AVL<Key>::Insert(const Key& data) {
  NodoAVL<Key>* nuevo = new NodoAVL<Key>(data);
  bool crece{false};
  this->InsertaBal(this->GetRoot(), nuevo, crece);
  return crece;
}

/**
 * @brief Metodo que se encarga de eliminar un nodo del arbol correctamente
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data es el dato que ira en el nodo a insertar
 * @return true el nodo se pudo eliminar correctamente
 * @return false el nodo no se pudo eliminar o no se encuentra en el arbol
 */
template<typename Key>
bool AVL<Key>::Delete(const Key& data) {
  bool decrece{false};
  DeleteBranch(this->GetRoot(), data, decrece);
  return decrece;
}

/**
 * @brief Metodo que cambia el valor de la root del arbol
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param root nuevo nodo root del arbol
 */
template<typename Key>
void AVL<Key>::SetRoot(NodoAVL<Key>* root) {
  this->AB<Key>::SetRoot(root);
}

/**
 * @brief metodo que devuelve una referencia a la root del arbol AVl
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return NodoAVL<Key>*& es el nodo root del arbol
 */
template<typename Key>
NodoAVL<Key>*& AVL<Key>::GetRoot(void) {
  return reinterpret_cast<NodoAVL<Key>*&>(this->AB<Key>::GetRoot());
}

/**
 * @brief metodo que devuelve una copia de la root del arbol AVL
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return NodoAVL<Key>* es el nodo root del arbol
 */
template<typename Key>
NodoAVL<Key>* AVL<Key>::GetRoot(void) const {
  return reinterpret_cast<NodoAVL<Key>*>(this->AB<Key>::GetRoot());
}

/**
 * @brief metodo encargado de realizar la rotacion izquierda izquierda al nodo
 * que se le pase
 * 
 * @tparam Key es el tipo de dato de los datos del arbol
 * @param nodo es el nodo a realizarle la rotacion izquierda izquierda
 */
template<typename Key>
void AVL<Key>::Rotacion_II(NodoAVL<Key>* &nodo) {
  NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrIzdoRef());
  nodo->SetPtrIzdo(reinterpret_cast<NodoAVL<Key>*&>(nodo1->GetPtrDchoRef()));
  nodo1->SetPtrDcho(nodo);
  if (nodo1->GetBal() == 1) {
    nodo->SetBal(0);
    nodo1->SetBal(0);
  } else { ///< nodo1->GetBal() == 0
    nodo->SetBal(1);
    nodo1->SetBal(-1);
  }
  nodo = nodo1;
}

/**
 * @brief metodo encargado de realizar la Rotacion derecha derecha al nodo
 * que se le pase
 * 
 * @tparam Key es el tipo de dato de los datos del arbol
 * @param nodo es el nodo a realizarle la Rotacion derecha derecha
 */
template<typename Key>
void AVL<Key>::Rotacion_DD(NodoAVL<Key>* &nodo) {
  NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrDchoRef());
  nodo->SetPtrDcho(reinterpret_cast<NodoAVL<Key>*&>(nodo1->GetPtrIzdoRef()));
  nodo1->SetPtrIzdo(nodo);
  if (nodo1->GetBal() == -1) {
    nodo->SetBal(0);
    nodo1->SetBal(0);
  } else { ///< nodo1->GetBal() == 0
    nodo->SetBal(-1);
    nodo1->SetBal(1);
  }
  nodo = nodo1;
}

/**
 * @brief metodo encargado de realizar la Rotacion izquierda derecha al nodo
 * que se le pase
 * 
 * @tparam Key es el tipo de dato de los datos del arbol
 * @param nodo es el nodo a realizarle la Rotacion izquierda derecha
 */
template<typename Key>
void AVL<Key>::Rotacion_ID(NodoAVL<Key>* &nodo) {
  NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrIzdoRef());
  NodoAVL<Key>* nodo2 = reinterpret_cast<NodoAVL<Key>*&>(nodo1->GetPtrDchoRef());
  nodo->SetPtrIzdo(reinterpret_cast<NodoAVL<Key>*&>(nodo2->GetPtrDchoRef()));
  nodo2->SetPtrDcho(nodo);
  nodo1->SetPtrDcho(reinterpret_cast<NodoAVL<Key>*&>(nodo2->GetPtrIzdoRef()));
  reinterpret_cast<NodoAVL<Key>*&>(nodo2->GetPtrIzdoRef()) = nodo1;
  if (nodo2->GetBal() == -1) nodo1->SetBal(1);
  else nodo1->SetBal(0);
  if (nodo2->GetBal() == 1) nodo->SetBal(-1);
  else nodo->SetBal(0);
  nodo2->SetBal(0);
  nodo = nodo2;
}

/**
 * @brief metodo encargado de realizar la Rotacion derecha izquierda al nodo
 * que se le pase
 * 
 * @tparam Key es el tipo de dato de los datos del arbol
 * @param nodo es el nodo a realizarle la Rotacion derecha izquierda
 */
template<typename Key>
void AVL<Key>::Rotacion_DI(NodoAVL<Key>* &nodo) {
  NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrDchoRef());
  NodoAVL<Key>* nodo2 = reinterpret_cast<NodoAVL<Key>*&>(nodo1->GetPtrIzdoRef());
  nodo->SetPtrDcho(reinterpret_cast<NodoAVL<Key>*&>(nodo2->GetPtrIzdoRef()));
  nodo2->SetPtrIzdo(nodo);
  nodo1->SetPtrIzdo(reinterpret_cast<NodoAVL<Key>*&>(nodo2->GetPtrDchoRef()));
  nodo2->SetPtrDcho(nodo1);
  if (nodo2->GetBal() == 1) nodo1->SetBal(-1);
  else nodo1->SetBal(-1);
  if (nodo2->GetBal() == -1) nodo->SetBal(1);
  else nodo->SetBal(0);
  nodo2->SetBal(0);
  nodo = nodo2;
}

/**
 * @brief Metodo que inserta un nodo y si el arbol se desequilibra, lo rebalancea
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param root es el nodo root del arbol
 * @param nuevo es el nodo a insertar
 * @param crece nos dice si el nodo se ha insertado correctamente
 */
template<typename Key>
void AVL<Key>::InsertaBal(NodoAVL<Key>* &root, NodoAVL<Key>* &nuevo,
                          bool& crece) {
  if (root == nullptr) {
    root = nuevo;
    crece = true;
  } else if (nuevo->GetData() < root->GetData()) {
    this->InsertaBal(reinterpret_cast<NodoAVL<Key>*&>(root->GetPtrIzdoRef()), nuevo, crece);
    if (crece) this->InsertReBalanceaIzda(root, crece);
  } else {
    this->InsertaBal(reinterpret_cast<NodoAVL<Key>*&>(root->GetPtrDchoRef()), nuevo, crece);
    if (crece) this->InsertReBalanceaDcha(root, crece);
  }
}

/**
 * @brief metodo que rebalancea un nodo AVL y sus ramas a la izquierda
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo a rebalancear
 */
template<typename Key>
void AVL<Key>::InsertReBalanceaIzda(NodoAVL<Key>* &nodo, bool& crece) {
  switch (nodo->GetBal()) {
    case -1: 
      nodo->SetBal(0);
      crece = false;
      break;
    case 0:
      nodo->SetBal(1);
      break;
    case 1:
      NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrIzdoRef());
      if (nodo1->GetBal() == 1) this->Rotacion_II(nodo);
      else this->Rotacion_ID(nodo);
      crece = false;
  }
}

/**
 * @brief metodo que rebalancea un nodo AVL y sus ramas a la derecha
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo a rebalancear
 */
template<typename Key>
void AVL<Key>::InsertReBalanceaDcha(NodoAVL<Key>* &nodo, bool& crece) {
  switch (nodo->GetBal()) {
    case 1:
      nodo->SetBal(0);
      crece = false;
      break;
    case 0:
      nodo->SetBal(-1);
      break;
    case -1:
      NodoAVL<Key>* nodo1 = reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrDchoRef());
      if (nodo1->GetBal() == -1) this->Rotacion_DD(nodo);
      else this->Rotacion_DI(nodo);
      crece = false;
  }
}

/**
 * @brief Metodo qu se encarga de buscar un valor concreto dentro de todos los
 * nodos del arbol AVL que cuelga del nodo "nodo" y si lo encuentra, lo borra
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es la root del arbol a comprobar el dato a borrar
 * @param data es el dato que queremos encontrar en un nodo y ese nodo lo borraremos
 * @param decrece nos dice si se ha eliminado el nodo correctamente
 */
template<typename Key>
void AVL<Key>::DeleteBranch(NodoAVL<Key>* &nodo, const Key& data, bool& decrece) {
  if (nodo == nullptr) return;
  if (data < nodo->GetData()) {
    this->DeleteBranch(reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrIzdoRef()), data, decrece);
    if (decrece) this->DeleteReBalanceaIzda(nodo, decrece);
    else if (data > nodo->GetData()) {
      this->DeleteBranch(reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrDchoRef()), data, decrece);
      if (decrece) this->DeleteReBalanceaDcha(nodo, decrece);
    } else { ///< data == nodo->data_
      NodoAVL<Key>* eliminado{nodo};
      if (nodo->GetPtrIzdo() == nullptr) {
        nodo = reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrDchoRef());
        decrece = true;
      } else if (nodo->GetPtrDcho() == nullptr) {
        nodo = reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrIzdoRef());
        decrece = true;
      } else {
        this->Replace(eliminado, reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrIzdoRef()), decrece);
        if (decrece) this->DeleteReBalanceaIzda(nodo, decrece);
      }
      eliminado->~NodoAVL();
      eliminado = nullptr;
    }

  }
}

/**
 * @brief metodo encargado de reemplazar un nodo eliminado en un arbol AVL
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param eliminado el nodo a eliminar
 * @param sust el nodo que lo sustituira
 * @param decrece true si se ha eliminado el nodo
 */
template<typename Key>
void AVL<Key>::Replace(NodoAVL<Key>* &eliminado, NodoAVL<Key>* &sust, bool& decrece) {
  if (sust->GetPtrDcho() != nullptr) {
    this->Replace(eliminado, reinterpret_cast<NodoAVL<Key>*&>(sust->GetPtrDchoRef()), decrece);
    if (decrece) this->DeleteReBalanceaDcha(sust, decrece);
  } else {
    eliminado->SetData(sust->GetData());
    eliminado = sust;
    sust = reinterpret_cast<NodoAVL<Key>*&>(sust->GetPtrIzdoRef());
    decrece = true;
  }
}

/**
 * @brief metodo que rebalancea hacia la izquierda al borrar un nodo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo desde donde parte el rebalanceo
 * @param decrece nos dice si el arbol ha decrecido a causa del borrado del nodo
 */
template<typename Key>
void AVL<Key>::DeleteReBalanceaIzda(NodoAVL<Key>* &nodo, bool& decrece) {
  NodoAVL<Key>* nodo1{reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrDchoRef())};
  switch (nodo->GetBal()) {
    case -1:
      if (nodo1->GetBal() > 0) this->Rotacion_DI(nodo);
      else {
        if (nodo1->GetBal() == 0) decrece = false;
        this->Rotacion_DD(nodo);
      }
      break;
    case 0:
      nodo->SetBal(-1);
      decrece = false;
      break;
    case 1:
      nodo->SetBal(0);
      break;
  }
}

/**
 * @brief metodo que rebalancea hacia la derecha al borrar un nodo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo desde donde parte el rebalanceo
 * @param decrece nos dice si el arbol ha decrecido a causa del borrado del nodo
 */
template<typename Key>
void AVL<Key>::DeleteReBalanceaDcha(NodoAVL<Key>* &nodo, bool& decrece) {
  NodoAVL<Key>* nodo1{reinterpret_cast<NodoAVL<Key>*&>(nodo->GetPtrIzdoRef())};
  switch (nodo->GetBal()) {
    case 1:
      if (nodo1->GetBal() < 0) this->Rotacion_ID(nodo);
      else {
        if (nodo1->GetBal() == 0) decrece = false;
        this->Rotacion_II(nodo);
      }
      break;
    case 0:
      nodo->SetBal(1);
      decrece = false;
      break;
    case -1:
      nodo->SetBal(0);
      break;
  }
}

#endif