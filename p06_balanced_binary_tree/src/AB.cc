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
 * @brief Metodo que recorre todo un subarbol siguiendo el algoritmo Inorden
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo del cual empezamos a recorrre, la raiz de la busqueda
 */
template<typename Key>
void AB<Key>::Inorden(const NodoB<Key>* nodo) const {
  if (nodo == nullptr) return;
  this->Inorden(nodo->GetPtrIzdo());
  std::cout << nodo->GetData() << " ";
  this->Inorden(nodo->GetPtrDcho());
}

/**
 * @brief metodo que recorre todo el arbol siguiendo el algritmo Inorden
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo del cual empezamos a recorrre, la raiz de la busqueda
 */
template<typename Key>
void AB<Key>::InordenRoot(void) const {
  this->Inorden(this->root_);
}

/**
 * @brief Metodo que poda una rama, desde el nodo que se le pasa a la rama
 * hasta las hojas, todos los nodos se eliminan
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo nodo que se va a podar
 */
template<typename Key>
void AB<Key>::Prune(NodoB<Key>* nodo) {
  if (nodo == nullptr) return;
  this->Prune(nodo->GetPtrIzdo()); ///< Podar Subarbol Izquierdo
  this->Prune(nodo->GetPtrDcho()); ///< Podar Subarbol Derecho
  delete nodo; ///< Eliminar Nodo
  nodo = nullptr;
}

/**
 * @brief metodo que cuenta todos los nodos del arbol
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return const int numero de nodos en todo el arbol binario
 */
template<typename Key>
int AB<Key>::Size(void) const { return this->SizeBranch(root_); }

/**
 * @brief metodo que cuenta la profundidad de los nodos y devuelve la
 * profundidad del nodo mas profundo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return const int es la profundidad del nodo mas profundo
 */
template<typename Key>
int AB<Key>::Height(void) const { return this->Height(root_); }

/**
 * @brief Metodo que nos dice si el puntero contiene un nodo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo que queremos comprobar
 * @return true el nodo pasado al metodo apunta a nullptr
 * @return false el nodo pasado al metodo apunta a un objeto de la clase NodoB
 */
template<typename Key>
bool AB<Key>::IsEmpty(const NodoB<Key>* nodo) const { return nodo == nullptr; }

/**
 * @brief metodo que comprueba si el nodo pasado es un nodo hoja
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el objeto a comprobar si es un nodo hoja
 * @return true el nodo pasado por parametro si es un nodo hoja
 * @return false el nod pasado por parametro no es un nodo hoja
 */
template<typename Key>
bool AB<Key>::IsLeaf(const NodoB<Key>* nodo) const {
  return !nodo->GetPtrDcho() && !nodo->GetPtrIzdo();
}

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

/**
 * @brief metodo el cual se encarga de contar todos los nodos que hay desde un
 * nodo en particular, contandolo a el, hasta llegar a las hojas del mismo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo donde empezaremos a contar los nodos
 * @return int numero de nodos que hay a partir del puntero a nodo que se da
 */
template<typename Key>
int AB<Key>::SizeBranch(NodoB<Key>* nodo) const {
  if (nodo == nullptr) return 0;
  return (1 + this->SizeBranch(nodo->GetPtrIzdo()) + 
              this->SizeBranch(nodo->GetPtrDcho()));
}

/**
 * @brief metodo que se encarga de devolver la longitud de la rama mas profunda
 * partiendo del nodo que se le pasa como argumento
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo del que empezaremos la busqueda
 * @return int es la profundidad de la rama mas profunda partiendo del nodo
 * dado como argumento
 */
template<typename Key>
int AB<Key>::HeightN(NodoB<Key>* nodo) const {
  if (nodo == nullptr) return 0;
  int height_left{this->HeightN(nodo->GetPtrIzdo())};
  int height_right{this->HeightN(nodo->GetPtrDcho())};
  if (height_right > height_left) return height_right;
  else return height_left;
}
