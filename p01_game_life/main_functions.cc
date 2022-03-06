/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 1: El Juego de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/03/2022
 * 
 * @file main_functions.cc
 * @brief Donde se aloja el desarrollo y la implementación de las funciones
 * de nuestro archivo cliente.
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
 *            cabecera y declarado su include
 * 06/03/22 - Funciones del main terminadas.
 */

#include "main_functions.h"

using std::cout;
using std::cerr;

/**
 * @brief Función que solo muestra un mensaje por pantalla sobre como usar el
 * programa.
 * 
 * @param argv Array de puntero a caracteres donde cada posición contiene el
 * primer caracter de cada argumento del programa.
 */
void MainMessage(const char* argv) {
  
}

/**
 * @brief Funcion que nos ayuda a procesar las entradas del programa por línea
 * de comandos para comprobar si se han pasado valores correctos al programa.
 * 
 * @param argc Número de argumentos pasados al programa (incluido el nombre).
 * @param argv Array de puntero a caracteres donde cada posición contiene el
 * primer caracter de cada argumento del programa.
 */
void Usage(const int& argc, const char* argv) {
  if (argc == 1) {
    MainMessage(argv);
    exit(EXIT_SUCCESS);
  }
  
  if (argc == 4) {

  } else {
    
  }
}