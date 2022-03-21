/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 3: La Vida en la Frontera
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/03/2022
 * 
 * @file main_cycle_life.cc (programa cliente)
 * @brief Programa que simula el famoso "Juego de la Vida" de John Horton
 * Conway, creado en 1970, es un ejemplo de "Autómata Celular". Este programa
 * es una extensión del juego de la vida, representar solo los estados de
 * "viva" y "muerta". A parte de la rejilla o Grid tiene diferentes
 * implementaciones, cosa que antes no tenía.
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./main_game_life --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 22/03/22 - Proyecto terminado.
 */

#include "main_functions.h"

  using std::cout;
  using std::cerr;
  using std::cin;

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string kKindOfGrid{argv[1]};
  std::string kRows{argv[2]};
  std::string kCols{argv[3]};
  std::string kGameTurns{argv[4]};

  

  GridWithOpenBorder grid_with_open_border(std::stoi(kRows), std::stoi(kCols));
  grid_with_open_border.LifeBorder(std::stoi(kGameTurns));

  return 0;
}
