# Algoritmos y Estructuras de Datos Avanzadas

## Práctica 2: Calculadora de expresiones en notación postfija

### Enunciado
Implementar en lenguaje C++ una calculadora que reciba como entrada una expresión aritmética en notación postfija, la evalúe y retorne su resultado.

Además de los tipos básicos del lenguaje (int, float), la calculadora debe funcionar con expresiones de operandos en los tipos de números implementados por el usuario:
* **Racional:**
 * La implementación del tipo de dato Racional debe asegurar que se representa con la fracción más simple posible, esto es, que no exista un divisor común para el numerador y denominador.
* **Complejo:**
 * Todo número complejo puede representarse como la suma de un número real y un número imaginario.

### Objetivo
El objetivo de esta práctica es trabajar la definición de clases, la implementación de operaciones mediante métodos, uso de funciones amigas y la sobrecarga de operadores. También se introduce las plantillas para definir clases genéricas.

### Forma de uso
#### Compilación
```bash
$ g++ main/main.cpp -o main.out
```
```bash
$ ./main.out
```
#### Ejecución
* Para el ejemplo usando **int**: (3 + 2) * (5 - 7)
```
 3 2 + 5 7 - *
```
* Para el ejemplo usando **float**: (3.2 + 2.4) * (5 - 7.1)
```
 3.2 2.4 + 5 7.1 - *
```
* Para el ejemplo usando **complejo**: (3+2i + 2+4i) - (5+2i - 7+1i)
```
 (3,2) (2,4) + (5,2) (7,1) - -
```
* Para el ejemplo usando **racional**: (3/2 + 2/4) * (7/1 - 5/1)
```
 {3/2} {2/4} + {7/1} {5/1} - *
```
### Autor

* [Adexe Sabina Pérez](http://alu0100769609.github.io)
