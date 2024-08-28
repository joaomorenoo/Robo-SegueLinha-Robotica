int main() {
    int segundos = -1;
    int minutos = 0;
    int inicio = 1;

    while (inicio == 1) {
        segundos++;
        // Pausa por 1 segundo
        for (int i = 0; i < 100000000; i++);  // Aproximação de um delay, não é exato

        if (segundos == 60) {
            minutos++;
            segundos = 0;
        }

        if (segundos <= 9) {
            // Imprime com um zero à esquerda
            printf("%d:0%d\n", minutos, segundos);
        } else {
            // Imprime normalmente
            printf("%d:%d\n", minutos, segundos);
        }
    }

    return 0;
}