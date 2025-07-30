#include <stdio.h>   // Para printf, scanf, fgets, getchar
#include <string.h>  // Para strcspn (remover \n do fgets)

// --- Definição da estrutura para uma Carta de Super Trunfo ---
// Esta struct agrupa todas as informações de uma única carta.
struct CartaSuperTrunfo {
    char estado;              // Ex: 'A', 'B', 'C', etc.
    char codigo_carta[5];     // Ex: "A01", "B00" (4 caracteres + terminador nulo '\0')
    char nome_pais[50];       // Ex: "Brasil" (até 49 caracteres + '\0')
    long long populacao;      // Número de habitantes (long long para números grandes)
    float area_km2;           // Área em quilômetros quadrados
    float pib_bilhoes;        // Produto Interno Bruto em bilhões de reais
    int pontos_turisticos;    // Quantidade de pontos turísticos
    float densidade_demografica; // População / Área
};

// --- Função para limpar o buffer de entrada ---
// Essencial após scanf de números e antes de fgets.
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal do Programa ---
int main() {
    // --- Declaração e Inicialização de Duas Cartas ---
    // Usamos dados pré-definidos para simplificar o desafio.
    struct CartaSuperTrunfo carta1 = {
        'A', "A01", "Brasil", 215000000, 8515767.0, 1800.0, 1500
    };

    struct CartaSuperTrunfo carta2 = {
        'B', "B02", "Argentina", 46000000, 2780400.0, 630.0, 500
    };

    // --- Cálculo da Densidade Demográfica para ambas as cartas ---
    // A densidade é População / Área
    if (carta1.area_km2 > 0) { // Evita divisão por zero
        carta1.densidade_demografica = (float)carta1.populacao / carta1.area_km2;
    } else {
        carta1.densidade_demografica = 0.0;
    }

    if (carta2.area_km2 > 0) { // Evita divisão por zero
        carta2.densidade_demografica = (float)carta2.populacao / carta2.area_km2;
    } else {
        carta2.densidade_demografica = 0.0;
    }

    // --- Exibição das Cartas Cadastradas para Conferência ---
    printf("--- Cartas Cadastradas ---\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo_carta);
    printf("Nome do País: %s\n", carta1.nome_pais);
    printf("População: %lld\n", carta1.populacao); // %lld para long long
    printf("Área: %.2f km²\n", carta1.area_km2);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib_bilhoes);
    printf("Pontos Turísticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta1.densidade_demografica);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo_carta);
    printf("Nome do País: %s\n", carta2.nome_pais);
    printf("População: %lld\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area_km2);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib_bilhoes);
    printf("Pontos Turísticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta2.densidade_demografica);

    // --- Menu Interativo para Escolha do Atributo ---
    int escolha;
    printf("\n--- Escolha o Atributo para Comparação ---\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Digite o número do atributo desejado: ");
    scanf("%d", &escolha);
    limparBuffer(); // Limpa o buffer após scanf

    printf("\n--- Resultado da Comparação ---\n");
    printf("País 1: %s\n", carta1.nome_pais);
    printf("País 2: %s\n", carta2.nome_pais);

    // --- Lógica de Comparação com switch e if-else aninhados ---
    switch (escolha) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %lld habitantes\n", carta1.nome_pais, carta1.populacao);
            printf("%s: %lld habitantes\n", carta2.nome_pais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s (População: %lld)\n", carta1.nome_pais, carta1.populacao);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedor: %s (População: %lld)\n", carta2.nome_pais, carta2.populacao);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome_pais, carta1.area_km2);
            printf("%s: %.2f km²\n", carta2.nome_pais, carta2.area_km2);
            if (carta1.area_km2 > carta2.area_km2) {
                printf("Vencedor: %s (Área: %.2f km²)\n", carta1.nome_pais, carta1.area_km2);
            } else if (carta2.area_km2 > carta1.area_km2) {
                printf("Vencedor: %s (Área: %.2f km²)\n", carta2.nome_pais, carta2.area_km2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões de reais\n", carta1.nome_pais, carta1.pib_bilhoes);
            printf("%s: %.2f bilhões de reais\n", carta2.nome_pais, carta2.pib_bilhoes);
            if (carta1.pib_bilhoes > carta2.pib_bilhoes) {
                printf("Vencedor: %s (PIB: %.2f bilhões de reais)\n", carta1.nome_pais, carta1.pib_bilhoes);
            } else if (carta2.pib_bilhoes > carta1.pib_bilhoes) {
                printf("Vencedor: %s (PIB: %.2f bilhões de reais)\n", carta2.nome_pais, carta2.pib_bilhoes);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos\n", carta1.nome_pais, carta1.pontos_turisticos);
            printf("%s: %d pontos\n", carta2.nome_pais, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Vencedor: %s (Pontos Turísticos: %d)\n", carta1.nome_pais, carta1.pontos_turisticos);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("Vencedor: %s (Pontos Turísticos: %d)\n", carta2.nome_pais, carta2.pontos_turisticos);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (Regra Invertida!)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nome_pais, carta1.densidade_demografica);
            printf("%s: %.2f hab/km²\n", carta2.nome_pais, carta2.densidade_demografica);
            // Regra Invertida: Menor valor vence!
            if (carta1.densidade_demografica < carta2.densidade_demografica) { // Menor densidade vence
                printf("Vencedor: %s (Densidade Demográfica: %.2f)\n", carta1.nome_pais, carta1.densidade_demografica);
            } else if (carta2.densidade_demografica < carta1.densidade_demografica) { // Menor densidade vence
                printf("Vencedor: %s (Densidade Demográfica: %.2f)\n", carta2.nome_pais, carta2.densidade_demografica);
            } else {
                printf("Empate!\n");
            }
            break;

        default: // Tratamento para opção inválida
            printf("Opção inválida! Por favor, escolha um número entre 1 e 5.\n");
            break;
    }

    printf("\nFim da comparação do Super Trunfo!\n");

    return 0; // Indica que o programa terminou com sucesso
}