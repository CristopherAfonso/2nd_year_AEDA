/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 1: El Juego de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/03/2022
 * 
 * @file Grid.cc
 * @brief Donde se desarrollan las funciones de la clase Grid contenida
 * en el archivo de cabecera Grid.h
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 05/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 06/03/22 - Funciones de la clase terminadas.
 */

#include "Grid.h"

/**
 * @brief Constructor por defecto, crear un objeto Grid de tamaño 10x10 visible
 * al usuario.
 */
Grid::Grid(void) : grid_(NULL), rows_(2), cols_(2) {
  grid_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_[i][j] = aux;
    }
  }
}

/**
 * @brief Constructor predeterminado, crea un objeto Grid donde kRows es el
 * numero de filas y kCols es el numero de columnas, tanto kRows como kCols
 * deben ser 1, o mayores a 1, sino el objeto estará vacio
 * 
 * @param kRows Numero de filas de la rejilla
 * @param kCols Numero de columnas de la rejilla
 */
Grid::Grid(const int& kRows, const int& kCols) 
    : grid_(NULL), rows_(2), cols_(2) {
  if (kRows > 0) rows_ = kRows + 2;
  if (kCols > 0) cols_ = kCols + 2;
  grid_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_[i][j] = aux;
    }
  }
}

/**
 * @brief Constructor de copia, crea un nuevo objeto copiando el que se le pasa
 * 
 * @param grid Objeto tipo Grid que nuestro nuevo objeto Grid copiara.
 */
Grid::Grid(const Grid& grid) : grid_(NULL), rows_(2), cols_(2) {
  *this = grid;
}

/**
 * @brief Destructor de la clase Grid, cada objeto Grid debe eliminar su
 * memoria dinamica antes de terminar el programa, eso hace este metodo
 */
Grid::~Grid(void) {
  for (int i{0}; i < rows_; ++i) delete[] grid_[i];
  delete[] grid_;
  grid_ = NULL;
}

/**
 * @brief Añade un nuevo objeto Cell a la posición en la rejilla indicada por
 * posx, y; posy, si la posicion cae fuera de las dimensiones de la rejilla,
 * directamente no la añade y no avisa de si ha sido o no ha sido añadida
 * correctamente.
 * 
 * @param posx Posición en el eje 'X' donde será añadida la celula
 * @param posy Posición en el eje 'Y' donde será añadida la celula
 * @param cell Celula que se añadirá a la rejilla
 */
void Grid::SetCell(const int& posx, const int& posy, Cell& cell) {
  if ((posx > 0) && (posy > 0) && (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    grid_[posx][posy] = cell;
    cell.SetPos(posx, posy);
  }
}

/**
 * @brief Añade un nuevo objeto Cell a la posición en la rejilla indicada por
 * position, position.first es la posicion de la celula en el eje 'X', y
 * position.second en el eje 'Y', si la posicion cae fuera de las dimensiones
 * de la rejilla, directamente no la añade y no avisa de si ha sido o no ha 
 * sido añadida correctamente.
 * 
 * @param position objeto std::pair<int, int> el cual en su primer elemento,
 * contiene la position en el eje 'X' de la celula y en el segundo la
 * posicion en el eje 'Y'. 
 * @param cell Es el objeto que va a ser añadido
 */
void Grid::SetCell(const std::pair<int, int> position, Cell& cell) {
  if ((position.first > 0) && (position.second > 0) && 
      (position.first < (rows_ - 1)) && (position.second < (cols_ - 1))) {
    grid_[position.first][position.second] = cell;
    cell.SetPos(position.first, position.second);
  }
}

/**
 * @brief Añade un nuevo objeto Cell a la posicion indicada en el atributo
 * privado position_ del objeto cell que va a ser añadido al objeto Grid, si la
 * posicion cae fuera de las dimensiones de la rejilla, directamente no la añade
 * y no avisa de si ha sido o no ha sido añadida correctamente.
 * 
 * @param cell objeto tipo Cell que sera añadido al objeto Grid en la posicion
 * que indique la propia celula ya.
 */
void Grid::SetCell(const Cell& cell) {
  if ((cell.GetPosition().first > 0) && (cell.GetPosition().second > 0) &&
      (cell.GetPosition().first < (rows_ - 1)) && 
      (cell.GetPosition().second < (cols_ - 1))) {
    grid_[cell.GetPosition().first][cell.GetPosition().second] = cell;
  }
}

/**
 * @brief Metodo que readimensiona solo las filas del objeto Grid, si el nuevo
 * objeto Grid es más pequeño que el original, habrá filas de objetos Cell que
 * se omitiran en la sobreescritura (las ultimas del original), si el nuevo
 * objeto Grid es más grande que el original, se crearán filas nuevas (a
 * continuacion de las ultimas del original).
 * 
 * @param kRows Numero de filas que tendrá nuestro objeto Grid readimensionado.
 * 
 */
void Grid::SetRows(const int& kRows) {
  Cell** aux_ptr{NULL};
  Cell aux_var;
  int aux_counter_1{2};
  if (kRows < 0) {
    aux_ptr = new Cell*[2];
  } else {
    aux_ptr = new Cell*[kRows + 2];
    aux_counter_1 += kRows;
  }

  for (int i{0}; i < aux_counter_1; ++i) {
    aux_ptr[i] = new Cell[cols_];
  }

  for (int i{1}; i < (aux_counter_1 - 1); ++i) {
    for (int j{1}; j < (cols_ - 1); ++j) {
      aux_var = this->GetCell(i, j);
      aux_var.SetPos(i, j); ///< el metodo GetCell puede devolver {-1, -1}
      aux_ptr[i][j] = aux_var;
    }
  }
}

/**
 * @brief Metodo que readimensiona solo las columnas del objeto Grid, si el
 * nuevo objeto Grid es más pequeño que el original, habrá filas de objetos
 * Cell que se omitiran en la sobreescritura (las ultimas del original), si
 * el nuevo objeto Grid es más grande que el original, se crearán filas
 * nuevas (a continuacion de las ultimas del original).
 * 
 * @param kCols Numero de columnas que tendrá nuestro objeto Grid
 * readimensionado.
 */
void Grid::SetCols(const int& kCols) {
  Cell** aux_ptr{NULL};
  Cell aux_var;
  int aux_counter_1{2};
  aux_ptr = new Cell*[rows_];

  if (kCols < 0) {
    aux_counter_1 = 2;
  } else {
    aux_counter_1 += kCols + 2;
  }

  for (int i{0}; i < rows_; ++i) {
    aux_ptr[i] = new Cell[aux_counter_1];
  }

  for (int i{1}; i < (rows_ - 1); ++i) {
    for (int j{1}; j < (aux_counter_1 - 1); ++j) {
      aux_var = this->GetCell(i, j);
      aux_var.SetPos(i, j); ///< el metodo GetCell puede devolver {-1, -1}
      aux_ptr[i][j] = aux_var;
    }
  }
}

/**
 * @brief Metodo que recibe una coordenada en el eje 'X' y otra en el eje 'Y'
 * y si estas coordenadas señalan una posicion valida dentro de la rejilla (una
 * posicion positiva y menor al limite en cada eje de coordenadas), devuelve la
 * celula que en esa posicion se halla, sino, devuelve una celula en estado
 * muerta y con posición en el eje 'X' = -1, y en el eje 'Y' = -1.
 * 
 * @param posx Posición en eje 'X' donde está la celula que queremos retornar.
 * @param posy Posición en eje 'Y' donde está la celula que queremos retornar.
 * @return Cell objeto celula que tiene como coordenadas 'posx' en el eje 'X' y
 * 'posy' en el eje 'Y'.
 */
Cell Grid::GetCell(const int& posx, const int& posy) const {
  if ((posx > 0) && (posy > 0) && (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    return grid_[posx][posy];
  } else {
    Cell aux;
    return aux;
  }
}

/**
 * @brief Metodo que recibe una coordenada en el eje 'X' y otra en el eje 'Y'
 * codificadas en un argumento std::pair<int, int> (coordenada 'X' es la
 * primera y la segunda es la 'Y'). Si estas coordenadas señalan una posicion
 * valida dentro de la rejilla (una posicion positiva y menor al limite en cada
 * eje de coordenadas), devuelve la celula que en esa posicion se halla, sino,
 * devuelve una celula en estado muerta y con posición en el eje 'X' = -1, y en
 * el eje 'Y' = -1.
 * 
 * @param position Variable que contiene la coordenada 'X' en el atributo
 * .first y la 'Y' en el atributo .second
 * @return Cell Objeto celula que tiene como coordenadas los valores de
 * position.
 */
Cell Grid::GetCell(const std::pair<int, int> position) const {
  if ((position.first > 0) && (position.second > 0) &&
      (position.first < (rows_ - 1)) && 
      (position.second < (cols_ - 1))) {
    return grid_[position.first][position.second];
  } else {
    Cell aux;
    return aux;
  }
}

/**
 * @brief 
 * 
 * @return int 
 */
int Grid::GetRows(void) const {return rows_;}

/**
 * @brief 
 * 
 * @return int 
 */
int Grid::GetCols(void) const {return cols_;}

