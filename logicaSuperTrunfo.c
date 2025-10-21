#include <stdio.h>
#include <string.h>


int main(){
    char codigo_carta[8], codigo_carta2[8], cidade[50], cidade2[50], estado[8], estado2[8];
    char *venceu;
    char *comparacao;
    char *comparacao2;
    int pTuristico, pTuristico2, opcao, opcao2, combinacao;
    unsigned long int populacao, populacao2;
    float area, pib, area2, pib2, densidade_populacional, densidade_populacional2, pibPCapita, pibPCapita2, superPoder, superPoder2, soma, soma2;

    //Dados da carta 1:
    printf("Carta 1:\n");
    printf("Digite a sigla do estado que você escolheu: ");
    scanf("%s", estado);
    
    printf("Escolha o código da carta usando a sigla do estado escolhido + 01/04.(ex: SP04, PR01): ");
    scanf("%s", codigo_carta);

    getchar(); //consome espaço extra.

    printf("Escolha o nome da cidade: ");
    fgets(cidade, 50, stdin);
    cidade[strcspn(cidade, "\n")] = '\0';


    printf("População da cidade: ");
    scanf("%lu", &populacao);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pTuristico);

    printf("Digite a área da cidade em quilometros quadrados a cidade tem: ");
    scanf("%f", &area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib);

    // Calcula densidade populacional e PIB per Capita:
    densidade_populacional = populacao / area;
    pibPCapita = pib / populacao;

    // Calcula Super Poder:
    superPoder = (float)populacao + area + pib + (float)pTuristico + pibPCapita + (1.0f / densidade_populacional);


    //Dados da carta 2:
    printf("Carta 2:\n");
    printf("Digite a sigla do estado que você escolheu: ");
    scanf("%s", estado2);
    
    printf("Escolha o código da carta usando a sigla do estado escolhido + 01/04.(ex: SP04, PR01): ");
    scanf("%s", codigo_carta2);

    getchar(); //consome espaço extra.

    printf("Escolha o nome da cidade: ");
    fgets(cidade2, 50, stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';



    printf("População da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pTuristico2);

    printf("Digite a área da cidade em quilometros quadrados a cidade tem: ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);

    // Calcula densidade populacional e PIB per Capita:
    densidade_populacional2 = populacao2 / area2;
    pibPCapita2 = pib2 / populacao2;

    // Calcula Super Poder:
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pTuristico2 + pibPCapita2 + (1.0f / densidade_populacional2);

    //Imprime carta 1: 
    printf("\n\nCarta 1: \n");
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codigo_carta);
    printf("Nome da cidade: %s", cidade);
    printf("População: %lu\n", populacao);
    printf("Área: %.2fkm²\n", area);
    printf("PIB: %.2f\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pTuristico);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional);
    printf("PIB per Capita: %.2f reais\n\n", pibPCapita);

    //Imprime carta 2:
    printf("Carta 2: \n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo_carta2);
    printf("Nome da cidade: %s", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2fkm²\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pTuristico2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n\n\n", pibPCapita2);

    // Adiciona menu interativo:
    do {
        printf("========= Menu Interativo ==========\n");
        printf("Compare os atributos desejáveis: \n");
        printf("[1] População\n");
        printf("[2] Área\n");
        printf("[3] PIB\n");
        printf("[4] Número de Pontos Turísticos\n");
        printf("[5] Densidade Demográfica\n");
        printf("[0] Sair\n\n");


        printf("Escolha o atributo 1: ");
        scanf("%d", &opcao);
        
        if (opcao == 0){
            printf("Encerrando programa...\n");
            break;
        }
        
        while (opcao > 5) {
            printf("Opção inválida, tente novamente: ");
            scanf("%d", &opcao);
        }

        // Menu do atributo 2, sem repetição de escolhas:
        for (int i = 1; i <= 5; i++){
            if (i == opcao) continue;
            if (i == 1) printf("[1] População\n");
            if (i == 2) printf("[2] Área\n");
            if (i == 3) printf("[3] PIB\n");
            if (i == 4) printf("[4] Número de Pontos Turísticos\n");
            if (i == 5) printf("[5] Densidade Demográfica\n");
        }

        printf("Escolha o atributo 2: ");
        scanf("%d", &opcao2);

        // Impede que o jogador escolha o mesmo atributo duas vezes.
        while (opcao2 == opcao || opcao2 < 1 || opcao2 > 5){
            printf("Você já escolheu esse atributo, escolha outro: ");
            scanf("%d", &opcao2);
        }

        // Força as escolhas a serem da menor para a maior.
        if (opcao > opcao2) {
            int t = opcao;
            opcao = opcao2;
            opcao2 = t;
        }

        combinacao = opcao*10 + opcao2;

        // Compara Atributos:
        switch (combinacao) {
            case 12:
                // População e Área
                printf("Carta 1:\nCidade: %s\nAtributos: População: %lu e Área: %.2fkm²\n", cidade, populacao, area);
                soma = (float)populacao + area;
                printf("Carta 2:\nCidade: %s\nAtributos: População: %lu e Área: %.2fkm²\n", cidade2, populacao2, area2);
                soma2 = (float)populacao2 + area2;
                // Compara Atributos:
                comparacao = (populacao > populacao2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: População - Resultado: %s\n", comparacao);
                comparacao2 = (area > area2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Área - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!\n");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu a rodada!\n" : "Carta 2 Venceu a rodada!\n";
                    printf("%s\n", venceu);
                }
                break;
            case 13:
                // População e PIB
                printf("Carta 1:\nCidade: %s\nAtributos: População: %lu e PIB: %.2f\n", cidade, populacao, pib);
                soma = (float)populacao + pib;
                printf("Carta 2:\n Cidade: %s\nAtributos: População: %lu e PIB: %.2f\n", cidade2, populacao2, pib2);
                soma2 = (float)populacao2 + pib2;
                // Compara Atributos:
                comparacao = (populacao > populacao2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: População - Resultado: %s\n", comparacao);
                comparacao2 = (pib > pib2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: PIB - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                    printf("%s\n", venceu);
                }
                break;
            case 14:
                // População e Pontos Turísticos
                printf("Carta 1:\nCidade: %s\nAtributos: População: %lu e Pontos Turísticos: %d\n", cidade, populacao, pTuristico);
                soma = (float)populacao + (float)pTuristico;
                printf("Carta 2:\nCidade: %s\nAtributos: População: %lu e Pontos Turísticos: %d\n", cidade2, populacao2, pTuristico2);
                soma2 = (float)populacao2 + (float)pTuristico2;
                // Compara Atributos:
                comparacao = (populacao > populacao2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: População - Resultado: %s\n", comparacao);
                comparacao2 = (pTuristico > pTuristico2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Ponto Turístico - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!\n");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                    printf("%s\n", venceu);
                }
                break;
            case 15:
                // População e Densidade Populacional
                printf("Carta 1:\nCidade: %s\nAtributos: População: %lu e Densidade Populacional: %.2f hab/km²\n", cidade, populacao, densidade_populacional);
                soma = (float)populacao + densidade_populacional;
                printf("Carta 2:\nCidade: %s\nAtributos: População: %lu e Densidade Populacional: %.2f hab/km²\n", cidade2, populacao2, densidade_populacional2);
                soma2 = (float)populacao2 + densidade_populacional2;
                // Compara Atributos:
                comparacao = (populacao > populacao2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: População - Resultado: %s\n", comparacao);
                comparacao2 = (densidade_populacional < densidade_populacional2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Densidade Populacional - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!\n");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                    printf("%s\n", venceu);
                }
                break;
            case 23:
                // Área e PIB
                printf("Carta 1:\nCidade: %s\nAtributos: Área: %.2fkm² e PIB: %.2f\n", cidade, area, pib);
                soma = area + pib;
                printf("Carta 2:\nCidade: %s\nAtributos: Área: %.2fkm² e PIB: %.2f\n", cidade2, area2, pib2);
                soma2 = area2 + pib2;
                // Compara Atributos:
                comparacao = (area > area2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Área - Resultado: %s\n", comparacao);
                comparacao2 = (pib > pib2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: PIB - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!\n");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                    printf("%s\n", venceu);
                }
                break;
            case 24:
                // Área e Pontos Turísticos
                printf("Carta 1:\nCidade: %s\nAtributos: Área: %.2fkm² e Pontos Turísticos: %d\n", cidade, area, pTuristico);
                soma = area + (float)pTuristico;
                printf("Carta 2:\nCidade: %s\nAtributos: Área: %.2fkm² e Pontos Turísticos: %d\n", cidade2, area2, pTuristico2);
                soma2 = area2 + (float)pTuristico2;
                // Compara Atributos:
                comparacao = (area > area2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Área - Resultado: %s\n", comparacao);
                comparacao2 = (pTuristico > pTuristico2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Ponto Turístico - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!\n");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                    printf("%s\n", venceu);
                }
                break;
            case 25:
                // Área e Densidade Populacional
                printf("Carta 1:\nCidade: %s\nAtributos: Área: %.2fkm² e Densidade Populacional: %.2f hab/km²\n", cidade, area, densidade_populacional);
                soma = area + densidade_populacional;
                printf("Carta 2:\nCidade: %s\nAtributos: Área: %.2fkm² e Densidade Populacional: %.2f hab/km²\n", cidade2, area2, densidade_populacional2);
                soma2 = area2 + densidade_populacional2;
                // Compara Atributos:
                comparacao = (area > area2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Área - Resultado: %s\n", comparacao);
                comparacao2 = (densidade_populacional < densidade_populacional2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Densidade Populacional - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!\n");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                    printf("%s\n", venceu);
                }
                break;
            case 34:
                // PIB e Pontos Turísticos
                printf("Carta 1:\nCidade: %s\nAtributos: PIB: %.2f e Pontos Turísticos: %d\n", cidade, pib, pTuristico);
                soma = pib + (float)pTuristico;
                printf("Carta 2:\nCidade: %s\nAtributos: PIB: %.2f e Pontos Turísticos: %d\n", cidade2, pib2, pTuristico2);
                soma2 = pib2 + (float)pTuristico2;
                // Compara Atributos:
                comparacao = (pib > pib2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: PIB - Resultado: %s\n", comparacao);
                comparacao2 = (pTuristico > pTuristico2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Ponto Turístico - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!\n");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                    printf("%s\n", venceu);
                }
                break;
            case 35:
                // PIB e Densidade Populacional
                printf("Carta 1:\nCidade: %s\nAtributos: PIB: %.2f e Densidade Populacional: %.2f hab/km²\n", cidade, pib, densidade_populacional);
                soma = pib + densidade_populacional;
                printf("Carta 2:\nCidade: %s\nAtributos: PIB: %.2f e Densidade Populacional: %.2f hab/km²\n", cidade2, pib2, densidade_populacional2);
                soma2 = pib2 + densidade_populacional2;
                // Compara Atributos:
                comparacao = (pib > pib2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: PIB - Resultado: %s\n", comparacao);
                comparacao2 = (densidade_populacional < densidade_populacional2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Densidade Populacional - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!\n");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                    printf("%s\n", venceu);
                }
                break;
            case 45:
                // Pontos Turísticos e Densidade Populacional
                printf("Carta 1:\nCidade: %s\n Atributos: Pontos Turísticos: %d e Densidade Populacional: %.2f hab/km²\n", cidade, pTuristico, densidade_populacional);
                soma = (float)pTuristico + densidade_populacional;
                printf("Carta 2:\nCidade: %s\n Atributos: Pontos Turísticos: %d e Densidade Populacional: %.2f hab/km²\n", cidade2, pTuristico2, densidade_populacional2);
                soma2 = (float)pTuristico2 + densidade_populacional2;
                // Compara Atributos:
                comparacao = (pTuristico > pTuristico2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Ponto Turístico - Resultado: %s\n", comparacao);
                comparacao2 = (densidade_populacional < densidade_populacional2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                printf("Atributo da comparação: Densidade Populacional - Resultado: %s\n", comparacao2);

                // Define vencedor da rodada:
                if (soma == soma2) {
                    printf("Empate!\n");
                } else {
                    venceu = (soma > soma2) ? "Carta 1 Venceu!\n" : "Carta 2 Venceu!\n";
                    printf("%s\n", venceu);
                }
                break;
            default:
                printf("Opção Inválida, tente novamente: ");
                continue;
        }

    } while (opcao != 0);

    return 0;
}