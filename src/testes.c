#include <stdio.h>
#ifdef _WIN32
    #include <windows.h> // Para Sleep() no Windows
#else
    #include <unistd.h>  // Para sleep() no Linux/MacOS
#endif

int main() {
    int tempo = 0;
    int intervalo = 2; // Intervalo de tempo em segundos

    while (tempo < 10) {  // Simula 10 unidades de tempo
        printf("Tempo: %d segundos\n", tempo);

        // Função de espera para controlar a velocidade
        #ifdef _WIN32
            Sleep(intervalo * 1000); // Windows usa milissegundos
        #else
            sleep(intervalo); // Linux/MacOS usa segundos
        #endif

        tempo += intervalo;
    }

    printf("Simulação concluída!\n");
    return 0;
}