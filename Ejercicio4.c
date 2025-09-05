#include <stdio.h>
#include <stdlib.h>

static inline int comparar_tuerca_con_tornillo(int tuerca, int tornillo) {
    if (tuerca < tornillo) return -1;
    if (tuerca > tornillo) return  1;
    return 0;
}

static inline void intercambiar(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partir_tuercas(int tuercas[], int bajo, int alto, int tornilloPivote) {
    int pos = bajo;

    for (int i = bajo; i <= alto; ++i) {
        int cmp = comparar_tuerca_con_tornillo(tuercas[i], tornilloPivote);
        if (cmp == 0) { intercambiar(&tuercas[i], &tuercas[alto]); break; }
    }

    for (int i = bajo; i < alto; ++i) {
        int cmp = comparar_tuerca_con_tornillo(tuercas[i], tornilloPivote);
        if (cmp < 0) {
            intercambiar(&tuercas[store], &tuercas[i]);
            pos++;
        }
    }
    
    intercambiar(&tuercas[store], &tuercas[alto]);
    return pos;
}

int partir_tornillos(int tornillos[], int bajo, int alto, int tuercaPivote) {
    int pos = bajo;

    for (int i = bajo; i <= alto; ++i) {
        int cmp = comparar_tuerca_con_tornillo(tuercaPivote, tornillos[i]);
        if (cmp == 0) { intercambiar(&tornillos[i], &tornillos[alto]); break; }
    }

    for (int i = bajo; i < alto; ++i) {
        int cmp = comparar_tuerca_con_tornillo(tuercaPivote, tornillos[i]);
        if (cmp > 0) {  /* equivalente a tornillo < pivote */
            intercambiar(&tornillos[store], &tornillos[i]);
            pos++;
        }
    }
    intercambiar(&tornillos[store], &tornillos[alto]);
    return pos;
}

static void emparejar_recursivo(int tuercas[], int tornillos[], int bajo, int alto) {
    if (bajo >= alto) return;

    int idxPivot = partir_tuercas(tuercas, bajo, alto, tornillos[alto]);

    partir_tornillos(tornillos, bajo, alto, tuercas[idxPivot]);

    emparejar_recursivo(tuercas, tornillos, bajo, idxPivot - 1);
    emparejar_recursivo(tuercas, tornillos, idxPivot + 1, alto);
}

void emparejar_tuercas_y_tornillos(int tuercas[], int tornillos[], int n) {
    if (n <= 1) return;
    emparejar_recursivo(tuercas, tornillos, 0, n - 1);
}

void imprimir_arreglo(const char *etiqueta, int arr[], int n) {
    printf("%s: ", etiqueta);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int m;  
    if (scanf("%d", &m) != 1 || m <= 0) {
        fprintf(stderr, "Error: m inválido.\n");
        return 1;
    }

    int *tuercas   = (int *)malloc(m * sizeof(int));
    int *tornillos = (int *)malloc(m * sizeof(int));
    if (!tuercas || !tornillos) {
        fprintf(stderr, "Error: memoria insuficiente.\n");
        free(tuercas); free(tornillos);
        return 1;
    }

    int n_tuercas = 0, n_tornillos = 0;

    for (int i = 0; i < m; i++) {
        int tipo, valor;
        if (scanf("%d %d", &tipo, &valor) != 2) {
            fprintf(stderr, "Error: entrada inválida en la línea %d.\n", i + 2);
            free(tuercas); free(tornillos);
            return 1;
        }
        if (tipo == 0) {           // tuerca
            tuercas[n_tuercas++] = valor;
        } else if (tipo == 1) {    // tornillo
            tornillos[n_tornillos++] = valor;
        } else {
            fprintf(stderr, "Error: tipo debe ser 0 (tuerca) o 1 (tornillo).\n");
            free(tuercas); free(tornillos);
            return 1;
        }
    }

    if (n_tuercas != n_tornillos) {
        fprintf(stderr, "Error: cantidad desigual de tuercas (%d) y tornillos (%d).\n",
                n_tuercas, n_tornillos);
        free(tuercas); free(tornillos);
        return 1;
    }

    int n = n_tuercas; 

    emparejar_tuercas_y_tornillos(tuercas, tornillos, n);

    imprimir_arreglo("Tuercas", tuercas, n);
    imprimir_arreglo("Tornillos", tornillos, n);

    free(tuercas);
    free(tornillos);
    return 0;
}
