// Parte A: Definición de la estructura
struct Proceso {
    int pid;
    char nombre[20];
    int prioridad; // 1 (alta) a 5 (baja)
};
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
