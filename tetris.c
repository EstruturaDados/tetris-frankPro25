#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8  // tamanho máximo da fila
typedef struct {
    char tipo;
    int id;
} Peca;

typedef struct {
    Peca dados[MAX];
    int inicio;
    int fim;
    int quantidade;
} Fila;
void LimparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
// Inicializa fila
void inicializarFila(Fila* f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

// Adiciona elemento (enqueue)
void enfileirar(Fila* f, Peca valor) {
    if (f->quantidade == MAX) {
        printf("Fila cheia!\n");
        return;
    }

    // move o 'fim' de forma circular
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = valor;
    f->quantidade++;
    printf("Inserido: %c id: %d (fim=%d)\n", valor.tipo, valor.id, f->fim);
}

// Remove elemento (dequeue)
void desenfileirar(Fila* f) {
    if (f->quantidade == 0) {
        printf("Fila vazia!\n");
        return ;
    }
    Peca valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->quantidade--;
    printf("peca \"%c\" saiu do começo da fila.\n", valor.tipo);
}

// Mostra elementos da fila
void exibirFila(Fila* f) {
    printf("Fila: \n");
    for (int i = 0; i < f->quantidade; i++) {
        int pos = (f->inicio + i) % MAX;
        printf("[%c]  ", f->dados[pos].tipo);
    }
    printf("\n");
}

void inserirPecaPadrao(Fila *f) {
    char c[] = "IOTL";
    Peca p;

    int index = 0;
    while (c[index] != '\0')
    {
        p.tipo = c[index];
        p.id = index;
        enfileirar(f,p);
        index++;
    }
}

int main() {
    Fila fila;
    Peca p;

    inicializarFila(&fila);
    inserirPecaPadrao(&fila);
    int id=4;
    
    int opcao;
    do
    {
        printf("---MANIPULACAO DE FILA CIRCULAR---\n");
        printf("1- exibir Fila.\n");
        printf("2- enfileirar peca.\n");
        printf("3- jogar peca.\n");
        printf("0- sair\n");
        scanf("%1d", &opcao);
        LimparBufferEntrada();
        
        switch (opcao)
        {
        case 1:
            exibirFila(&fila);
            break;
        case 2:
            printf("tipo de Peca:\n");
            scanf("%1c", &p.tipo);
            LimparBufferEntrada();

            p.id = id++;

            enfileirar(&fila, p);
            break;
        case 3:
            desenfileirar(&fila);
            break;
        case 0:
            printf("Saindo...\n");
            break;

        default:
            break;
        }
    } while (opcao != 0);
    
}
