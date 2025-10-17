#include <stdio.h>

int main(){
    char codigo_carta[8], codigo_carta2[5], cidade[50], cidade2[50], estado[8], estado2[8];
    int pTuristico, pTuristico2, opcao;
    unsigned long int populacao, populacao2;
    float area, pib, area2, pib2, densidade_populacional, densidade_populacional2, pibPCapita, pibPCapita2, superPoder, superPoder2;

    //Dados da carta 1:
    printf("Carta 1:\n");
    printf("Digite a sigla do estado que você escolheu: ");
    scanf("%s", &estado);
    
    printf("Escolha o código da carta usando a sigla do estado escolhido + 01/04.(ex: SP04, PR01): ");
    scanf("%s", &codigo_carta);

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
    scanf("%s", &estado2);
    
    printf("Escolha o código da carta usando a sigla do estado escolhido + 01/04.(ex: SP04, PR01): ");
    scanf("%s", &codigo_carta2);

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
        printf("Compare o atributo desejável: \n");
        printf("[1] População\n");
        printf("[2] Área\n");
        printf("[3] PIB\n");
        printf("[4] Número de Pontos Turísticos\n");
        printf("[5] Densidade Demográfica\n");
        printf("[0] Sair");
        printf("Opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                if (populacao > populacao2) {
                    printf("%s Venceu\n", cidade);
                    printf("Atributo comparado: População.\n");
                    printf("Valor: %lu\n", populacao);
                    printf("Carta 1 venceu!\n");
                } else if (populacao == populacao2){
                    printf("Empate.\n");
                } else {
                    printf("%s Venceu\n", cidade2);
                    printf("Atributo comparado: População.\n");
                    printf("Valor: %lu\n", populacao2);
                    printf("Carta 2 venceu!\n");
                }
                break;
            case 2:
                if (area > area2) {
                    printf("%s Venceu\n", cidade);
                    printf("Atributo comparado: Área.\n");
                    printf("Valor: %.2fkm²\n", area);
                    printf("Carta 1 venceu!\n");
                } else if (area == area2){
                    printf("Empate.\n");
                } else {
                    printf("%s Venceu\n", cidade2);
                    printf("Atributo comparado: Área.\n");
                    printf("Valor: %.2fkm²\n", area2);
                    printf("Carta 2 venceu!\n");
                }
                break;
            case 3:
                if (pib > pib2) {
                    printf("%s Venceu\n", cidade);
                    printf("Atributo comparado: PIB.\n");
                    printf("Valor: %.2f\n", pib);
                    printf("Carta 1 venceu!\n");
                } else if (pib == pib2){
                    printf("Empate.\n");
                } else {
                    printf("%s Venceu\n", cidade2);
                    printf("Atributo comparado: PIB.\n");
                    printf("Valor: %.2f\n", pib2);
                    printf("Carta 2 venceu!\n");
                }
                break;
            case 4:
                    if (pTuristico > pTuristico2) {
                    printf("%s Venceu\n", cidade);
                    printf("Atributo comparado: Número de Pontos Turísticos.\n");
                    printf("Valor: %d\n", pTuristico);
                    printf("Carta 1 venceu!\n");
                } else if (pTuristico == pTuristico2){
                    printf("Empate.\n");
                } else {
                    printf("%s Venceu\n", cidade2);
                    printf("Atributo comparado: Número de Pontos Turísticos.\n");
                    printf("Valor: %d\n", pTuristico2);
                    printf("Carta 2 venceu!\n");
                }
                break;
            case 5:
                    if (densidade_populacional < densidade_populacional2) {
                    printf("%s Venceu\n", cidade);
                    printf("Atributo comparado: Densidade Demográfica.\n");
                    printf("Valor: %.2f hab/km²\n", densidade_populacional);
                    printf("Carta 1 venceu!\n");
                } else if (densidade_populacional == densidade_populacional2){
                    printf("Empate.\n");
                } else {
                    printf("%s Venceu\n", cidade2);
                    printf("Atributo comparado: Densidade Demográfica.\n");
                    printf("Valor: %.2f hab/km²\n", densidade_populacional2);
                    printf("Carta 2 venceu!\n");
                }
                break;
            case 0:
                    printf("Encerrando o programa...\n");
                    break;
            default:
                    printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}