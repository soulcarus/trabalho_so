# Kernel Cooperativo - Semáforo Inteligente
Kernel cooperativo para Arduino Mega2560, implementado como trabalho da disciplina Sistemas Operacionais (UFC Russas, 2024.2).

## Descrição
Simula um semáforo inteligente que adapta o tempo do sinal verde com base em pedidos de pedestres (botão no pino 2).

## Estrutura
- `include/kernel.h`: Definições do kernel.
- `src/kernel.c`: Escalonador cooperativo.
- `src/tasks.c`: Tarefas do semáforo.
- `main.ino`: Inicialização.

## Hardware
- Arduino Mega2560
- LEDs: Vermelho (11), Amarelo (12), Verde (13)
- Botão: Pino 2 (pull-up)

## Como Testar
1. Carregue no Arduino IDE ou Wokwi.
2. Conecte LEDs e botão conforme os pinos.
3. Abra o monitor serial (9600 baud).
