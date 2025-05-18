# Laboratorio IE0117 - Análisis de Secuencia Binaria y Palíndromos

Este repositorio contiene la implementación en lenguaje C de dos ejercicios desarrollados como parte del curso **IE-0117: Programación Bajo Plataformas Abiertas** en la Universidad de Costa Rica (I-2025).

## 🧩 Ejercicio 1: Secuencia más larga de 1s en matriz binaria

- Lee una matriz binaria cuadrada generada aleatoriamente.
- Determina la secuencia más larga de 1s consecutivos, permitiendo que continúe entre filas.
- Uso exclusivo de aritmética de punteros (sin indexación por corchetes).
- Uso de memoria dinámica.
- Validado con `valgrind` para evitar memory leaks.

📂 Ubicación: [`/ejercicio1/ejercicio1.c`](./ejercicio1/ejercicio1.c)

---

## 🔁 Ejercicio 2: Palíndromo más largo en un archivo de texto

- Lee palabra por palabra desde un archivo (`input.txt`).
- Ignora signos de puntuación y convierte todo a minúscula.
- Detecta e imprime el palíndromo más largo.
- Manejo eficiente de memoria con `malloc`, `realloc`, y `free`.

📂 Ubicación: [`/ejercicio2/ejercicio2.c`](./ejercicio2/ejercicio2.c)  
📄 Archivo de entrada: [`input.txt`](./ejercicio2/input.txt)

---

## 🧪 Validación

Todos los programas fueron ejecutados y verificados usando:

```bash
valgrind --leak-check=full ./ejecutable
