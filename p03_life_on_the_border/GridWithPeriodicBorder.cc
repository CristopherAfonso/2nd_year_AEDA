/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 3: La Vida en la Frontera
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/03/2022
 * 
 * @file GridWithOpenBorder.cc
 * @brief Donde se desarrollan las funciones de la clase GridWithOpenBorder
 * contenida en el archivo de cabecera GridWithOpenBorder.h
 *
 * @bug En el metodo LifeBorder, cuando te piden las posiciones de las celulas
 * si introduces caracteres en vez de numeros, entra en bucle infinito, pasa lo
 * mismo si introduces numeros con decimales.
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 22/03/22 - Funciones de la clase terminadas.
 */

#include "Cell.h"
#include "GridWithPeriodicBorder.h"

/**
 * @brief Constructor por defecto, crear un objeto GridWithPeriodicBorder de
 * tamaño 10x10 visible al usuario.
 */
GridWithPeriodicBorder::GridWithPeriodicBorder(void)
    : grid_with_periodic_border_(NULL), rows_(2), cols_(2) {
  grid_with_periodic_border_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_with_periodic_border_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_with_periodic_border_[i][j] = aux;
    }
  }
}

/**
 * @brief Constructor predeterminado, crea un objeto GridWithPeriodicBorder
 * donde kRows es el numero de filas y kCols es el numero de columnas,
 * tanto kRows como kCols deben ser 1, o mayores a 1, sino el objeto estará
 * vacio.
 * 
 * @param kRows Numero de filas de la rejilla
 * @param kCols Numero de columnas de la rejilla
 */
GridWithPeriodicBorder::GridWithPeriodicBorder(const int& kRows, const int& kCols)
  : grid_with_periodic_border_(NULL), rows_(2), cols_(2) {
  if (kRows > 0) rows_ = kRows + 2;
  if (kCols > 0) cols_ = kCols + 2;
  grid_with_periodic_border_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_with_periodic_border_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_with_periodic_border_[i][j] = aux;
    }
  }
}

/**
 * @brief Constructor de copia, crea un nuevo objeto copiando el que se le pasa
 * 
 * @param grid Objeto tipo GridWithPeriodicBorder que nuestro nuevo objeto
 * GridWithPeriodicBorder copiara.
 */
GridWithPeriodicBorder::GridWithPeriodicBorder(const GridWithPeriodicBorder& grid_with_periodic_border)
  : grid_with_periodic_border_(NULL), rows_(2), cols_(2) {
  grid_with_periodic_border_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_with_periodic_border_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_with_periodic_border_[i][j] = aux;
    }
  }
  *this = grid_with_periodic_border;
}

/**
 * @brief Destructor de la clase GridWithPeriodicBorder, cada objeto
 * GridWithPeriodicBorder debe eliminar su memoria dinamica antes de
 * terminar el programa, eso hace este metodo.
 */
GridWithPeriodicBorder::~GridWithPeriodicBorder(void) {
  for (int i{0}; i < rows_; ++i) delete[] grid_with_periodic_border_[i];
  delete[] grid_with_periodic_border_;
  grid_with_periodic_border_ = NULL;
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
void GridWithPeriodicBorder::SetCell(const int& posx, const int& posy, const Cell& cell) {
  if ((posx > 0) && (posy > 0) && (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    grid_with_periodic_border_[posx][posy] = cell;
    grid_with_periodic_border_[posx][posy].SetPos(posx, posy);
  }
}

/**
 * @brief Añade un nuevo objeto Cell a la posicion indicada en el atributo
 * privado position_ del objeto cell que va a ser añadido al objeto rejilla, si la
 * posicion cae fuera de las dimensiones de la rejilla, directamente no la añade
 * y no avisa de si ha sido o no ha sido añadida correctamente.
 * 
 * @param cell objeto tipo Cell que sera añadido al objeto Grid en la posicion
 * que indique la propia celula ya.
 */
void GridWithPeriodicBorder::SetCell(const Cell& cell) {
  if ((cell.GetPosition().first > 0) && (cell.GetPosition().second > 0) &&
      (cell.GetPosition().first < (rows_ - 1)) && 
      (cell.GetPosition().second < (cols_ - 1))) {
    grid_with_periodic_border_[cell.GetPosition().first][cell.GetPosition().second] = cell;
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
Cell& GridWithPeriodicBorder::GetCell(const int& posx, const int& posy) {
  if ((posx > 0) && (posy > 0) && (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    return grid_with_periodic_border_[posx][posy];
  } else {
    Cell aux;
    return aux;
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
const Cell& GridWithPeriodicBorder::GetCell(const int& posx, const int& posy) const {
  if ((posx > 0) && (posy > 0) &&
      (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    return grid_with_periodic_border_[posx][posy];
  } else {
    Cell aux;
    return aux;
  }
}

/**
 * @brief Metodo que devuelve el numero de filas que tiene la rejilla.
 * 
 * @return int Numero de filas que tiene la rejilla (rejillas usables).
 */
int GridWithPeriodicBorder::GetRows(void) const {return rows_ - 2;}

/**
 * @brief Metodo que devuelve el numero de columnas que tiene la rejilla.
 * 
 * @return int Numero de columnas que tiene la rejilla (rejillas usables).
 */
int GridWithPeriodicBorder::GetCols(void) const {return cols_ - 2;}

/**
 * @brief Metodo que implementa El Juego de la Vida, aquí está desarrollado
 * todo lo que debe ocurrir en el juego.
 * 
 * @param kGameTurns Parametro que indica cuantas veces se va a actulizar toda
 * la rejilla (cuantos turnos van a pasar y como se va a desarrollar el juego)
 * segun los estados de las celulas.
 */
void GridWithPeriodicBorder::LifeBorder(const int& kGameTurns) {
  std::cout << "\nTurno 0\n";
  std::cout << *this;
  for (int i{1}; i < kGameTurns; ++i) {
    std::cout << "Turno " << i << "\n";
    this->NextGeneration();
    std::cout << *this;
  }

  std::cout << "Fin del Juego\n\n";
}

