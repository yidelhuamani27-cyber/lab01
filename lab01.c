// Parte A: Definición de la estructura
#include <stdio.h>
#define MAX_PROCESOS 10
struct Proceso {
    int pid;
    char nombre[20];
    int prioridad; // 1 (alta) a 5 (baja)
};
//Parte C: Prototipo de la función de búsqueda
int buscarMayorPrioridad(struct Proceso *procesos, int n);

int main() {
    struct Proceso procesos[MAX_PROCESOS];
    int n = 0;
// Parte B: Registro de procesos
    printf("¿Cuántos procesos desea ingresar (máximo %d)? ", MAX_PROCESOS);
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Cantidad no válida.\n");
        return 1;
    }
    if (n > MAX_PROCESOS) {
        n = MAX_PROCESOS;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Registro del Proceso %d ---\n", i + 1);
        printf("PID: ");
        scanf("%d", &procesos[i].pid);
        
        printf("Nombre: ");
        scanf("%19s", procesos[i].nombre);
        
        printf("Prioridad (1-5): ");
        scanf("%d", &procesos[i].prioridad);
    }
// Parte C: Llamada a la función de búsqueda
    int indice_ganador = buscarMayorPrioridad(procesos, n);
// Parte D: Presentación de resultados
    if (indice_ganador != -1) {
        printf("\nProceso de mayor prioridad:\n");
        printf("PID: %d\n", procesos[indice_ganador].pid);
        printf("Nombre: %s\n", procesos[indice_ganador].nombre);
        printf("Prioridad: %d\n", procesos[indice_ganador].prioridad);
    }

    return 0;
}
// Parte C: Implementación de la función mediante punteros
int buscarMayorPrioridad(struct Proceso *procesos, int n) {
    if (n <= 0) return -1;

    int indice_menor = 0;
    // Se accede mediante el puntero utilizando la notación de arreglos o aritmética de punteros
    for (int i = 1; i < n; i++) {
        if ((procesos + i)->prioridad < (procesos + indice_menor)->prioridad) {
            indice_menor = i;
        }
    }
    return indice_menor;
}
