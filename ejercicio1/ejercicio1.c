#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Reserva dinámicamente una matriz cuadrada de tamaño size×size.
 * matrix: puntero por referencia donde se almacenará la dirección de la matriz.
 */
void allocateMatrix(int ***matrix, int size) {
    *matrix = malloc(size * sizeof(int*));
    if (!*matrix) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        *(*matrix + i) = malloc(size * sizeof(int));
        if (!*(*matrix + i)) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }
}

/*
 * Llena la matriz con 0s y 1s aleatorios, usando exclusively aritmética de punteros.
 */
void fillMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        int *fila = *(matrix + i);
        for (int j = 0; j < size; j++) {
            *(fila + j) = rand() % 2;
        }
    }
}

/*
 * Imprime la matriz, usando aritmética de punteros.
 */
void printMatrix(int **matrix, int size) {
    printf("Matriz (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        int *fila = *(matrix + i);
        for (int j = 0; j < size; j++) {
            printf("%d ", *(fila + j));
        }
        printf("\n");
    }
}

/*
 * Recorre fila a fila (sin reiniciar la cuenta al cambiar de fila)
 * y determina la longitud de la secuencia más larga de 1s.
 * Usa únicamente aritmética de punteros.
 */
void findLargestLine(int **matrix, int size, int *result) {
    int maxCount = 0;
    int currentCount = 0;

    for (int i = 0; i < size; i++) {
        int *fila = *(matrix + i);
        for (int j = 0; j < size; j++) {
            if (*(fila + j) == 1) {
                currentCount++;
            } else {
                if (currentCount > maxCount)
                    maxCount = currentCount;
                currentCount = 0;
            }
        }
        /* Al finalizar cada fila, no reseteamos currentCount:
           la secuencia puede continuar al inicio de la siguiente fila */
    }
    if (currentCount > maxCount)
        maxCount = currentCount;

    *result = maxCount;
}

/*
 * Libera toda la memoria asignada a la matriz.
 */
void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(*(matrix + i));
    }
    free(matrix);
}

int main() {
    int size, largestLine;
    int **matrix = NULL;

    printf("Ingrese el tamaño de la matriz cuadrada: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Tamaño inválido\n");
        return EXIT_FAILURE;
    }

    srand((unsigned)time(NULL));

    allocateMatrix(&matrix, size);
    fillMatrix(matrix, size);
    printMatrix(matrix, size);

    findLargestLine(matrix, size, &largestLine);
    printf("\nLa longitud de la secuencia de 1s más larga es: %d\n", largestLine);

    freeMatrix(matrix, size);
    return 0;
}
