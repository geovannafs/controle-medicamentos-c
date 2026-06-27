#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICAMENTOS 100 // Limite maximo de medicamentos no sistema

// Definicao da estrutura do medicamento
typedef struct medicamento {
    char nome[50];
    int quantEstoque;            
} med;

// Funcao para limpar o buffer universal
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- DEFINICAO DAS FUNCOES ---

// Funcao para cadastrar um medicamento num espaco especifico do vetor
void cadastrarMedicamento(med *m) {
    printf("\n--- CADASTRO DE NOVO MEDICAMENTO ---\n");
    
    // Limpa o buffer do teclado
    limparBuffer();
 
    
    printf("Nome do medicamento: ");
    fgets(m->nome, 50, stdin);
    m->nome[strcspn(m->nome, "\n")] = '\0'; // Remove o \n do final da string

    printf("Quantidade inicial em estoque: ");
    scanf("%d", &m->quantEstoque);
    
    printf("Medicamento '%s' cadastrado com sucesso!\n\n", m->nome);
}

// Funcao para listar todos os medicamentos cadastrados
void listarMedicamentos(med lista[], int total) {
    if (total == 0) {
        printf("\nNenhum medicamento cadastrado no sistema.\n\n");
        return;
    }

    printf("\n--- LISTA DE MEDICAMENTOS CADASTRADOS ---\n");
    printf("%-3s | %-30s | %s\n", "ID", "Nome do Medicamento", "Estoque");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        // Exibe o ID (indice + 1), o nome e a quantidade em estoque
        printf("%03d | %-30s | %d unidades\n", i + 1, lista[i].nome, lista[i].quantEstoque);
    }
    printf("-----------------------------------------------------------------\n\n");
}

// Funcao para procurar um medicamento pelo nome (retorna o indice ou -1 se nao encontrar)
int buscarMedicamento(med lista[], int total, char nomeBusca[]) {
    for (int i = 0; i < total; i++) {
        // O ideal e que a comparacao diferencie maiusculas de minusculas.
        if (strcmp(lista[i].nome, nomeBusca) == 0) {
            return i; // Retorna a posicao do medicamento no vetor
        }
    }
    return -1; // Retorna -1 se nao encontrar
}

// Funcao para atualizar o estoque de um medicamento ja existente
void atualizarEstoque(med *m) {
    int novaQuantidade;
    printf("\n--- ATUALIZAR ESTOQUE ---\n");
    printf("Medicamento: %s\n", m->nome);
    printf("Estoque atual: %d unidades\n", m->quantEstoque);
    
    printf("Digite a nova quantidade: ");
    scanf("%d", &novaQuantidade);
    
    m->quantEstoque = novaQuantidade;
    printf("Estoque de '%s' atualizado para %d unidades!\n\n", m->nome, m->quantEstoque);
}

// --- FUNCAO PRINCIPAL ---
int main() {
    //vetor (array) para guardar ate 100 medicamentos
    med vetorMedicamentos[MAX_MEDICAMENTOS]; 
    int totalMedicamentos = 0; // Controla quantos foram cadastrados ate o momento
    int opcao;

    do {
        printf("-----------------------------------------------------------------\n");
        printf("---------------------Controle de medicamentos----------------------\n\n");
        printf("Para cadastrar um novo medicamento digite 1\n");
        printf("Para atualizar o estoque de um medicamento digite 2\n");
        printf("Para exibir todos os medicamentos cadastrados digite 3\n");
        printf("Para sair digite 0\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalMedicamentos < MAX_MEDICAMENTOS) {
                    // Passamos o endereco do espaco vazio atual do vetor
                    cadastrarMedicamento(&vetorMedicamentos[totalMedicamentos]);
                    totalMedicamentos++; // Incrementa o contador de cadastrados
                } else {
                    printf("\nErro: Limite maximo de %d medicamentos atingido!\n\n", MAX_MEDICAMENTOS);
                }
                break;
                
            case 2:
                if (totalMedicamentos == 0) {
                    printf("\nNenhum medicamento cadastrado no sistema para ser atualizado.\n\n");
                } else {
                    char nomeProcurado[50];
                    limparBuffer();
                    printf("\nDigite o nome do medicamento para atualizar: ");
                    fgets(nomeProcurado, 50, stdin);
                    nomeProcurado[strcspn(nomeProcurado, "\n")] = '\0';

                    // Procura o medicamento no vetor
                    int indiceEncontrado = buscarMedicamento(vetorMedicamentos, totalMedicamentos, nomeProcurado);

                    if (indiceEncontrado != -1) {
                        // Passa apenas o endereço do medicamento encontrado para atualizacao
                        atualizarEstoque(&vetorMedicamentos[indiceEncontrado]);
                    } else {
                        printf("\nMedicamento '%s' nao encontrado.\n\n", nomeProcurado);
                    }
                }
                break;
                
            case 3:
                // Lista todos os medicamentos registados
                listarMedicamentos(vetorMedicamentos, totalMedicamentos);
                break;
                
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
