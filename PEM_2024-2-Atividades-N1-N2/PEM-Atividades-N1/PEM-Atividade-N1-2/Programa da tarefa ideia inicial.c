// Criador do Código: Diego Lopes Sakata
// Professor, eu fiz esse código para seguir o exemplo da tarefa, acredito que se tentar colocar menos ou mais  do que 5 categorias dará erro.
// Estou enviando esse código junto na tarefa, apenas para o senhor ver como foi a ideia inicial para a realização do outro código, que é o completo.

#include <stdio.h>

int main()
{
    int n, i, cont1 = 1, cont2 = 1, c1, c2, c3, c4, c5;
    
    printf("Digite quantas categorias existem: ");
    scanf("%i",&n);
    
    char cat[n][100];
    
    for(i = 0; i < n; i++){
        printf("Digite o nome da %i categoria: ",cont1);
        scanf(" %99[^\n]",cat[i]);
        cont1++;
    }
    
    printf("Quantos testes tem na categoria %s: ",cat[0]);
    scanf("%i",&c1);
    while(c1 <= 2){
        printf("A quantidade de testes não pode ser menor ou igual a 2.\n");
        printf("Digite novamente: ");
        scanf("%i",&c1);
    }
    
    printf("Quantos testes tem na categoria %s: ",cat[1]);
    scanf("%i",&c2);
    while(c2 <= 2){
        printf("A quantidade de testes não pode ser menor ou igual a 2.\n");
        printf("Digite novamente: ");
        scanf("%i",&c2);
    }
    
    printf("Quantos testes tem na categoria %s: ",cat[2]);
    scanf("%i",&c3);
    while(c3 <= 2){
        printf("A quantidade de testes não pode ser menor ou igual a 2.\n");
        printf("Digite novamente: ");
        scanf("%i",&c3);
    }
    
    printf("Quantos testes tem na categoria %s: ",cat[3]);
    scanf("%i",&c4);
    while(c4 <= 2){
        printf("A quantidade de testes não pode ser menor ou igual a 2.\n");
        printf("Digite novamente: ");
        scanf("%i",&c4);
    }
    
    printf("Quantos testes tem na categoria %s: ",cat[4]);
    scanf("%i",&c5);
    while(c5 <= 2){
        printf("A quantidade de testes não pode ser menor ou igual a 2.\n");
        printf("Digite novamente: ");
        scanf("%i",&c5);
    }
    
    float nota1[c1], nota2[c2], nota3[c3], nota4[c4], nota5[c5];
    
    printf("Digite as notas da categoria %s:\n",cat[0]);
    
    for(i = 0; i < c1; i++){    
        printf("Nota do %i teste: ",cont2);
        scanf("%f",&nota1[i]);
        if(nota1[i] < 0 || nota1[i] > 10){
            printf("as notas devem ser entre 0 e 10.\n");
            printf("Digite a nota novamente: ");
            scanf("%f",&nota1[i]);
        }
        cont2++;
    }
    
    printf("Digite as notas da categoria %s:\n",cat[1]);
    
    cont2 = 1;
    
    for(i = 0; i < c2; i++){    
        printf("Nota do %i teste: ",cont2);
        scanf("%f",&nota2[i]);
        if(nota2[i] < 0 || nota2[i] > 10){
            printf("as notas devem ser entre 0 e 10.\n");
            printf("Digite a nota novamente: ");
            scanf("%f",&nota2[i]);
        }
        cont2++;
    }
    
    printf("Digite as notas da categoria %s:\n",cat[2]);
    
    cont2 = 1;
    
    for(i = 0; i < c3; i++){    
        printf("Nota do %i teste: ",cont2);
        scanf("%f",&nota3[i]);
        if(nota3[i] < 0 || nota3[i] > 10){
            printf("as notas devem ser entre 0 e 10.\n");
            printf("Digite a nota novamente: ");
            scanf("%f",&nota3[i]);
        }
        cont2++;
    }
    
    printf("Digite as notas da categoria %s:\n",cat[3]);
    
    cont2 = 1;
    
    for(i = 0; i < c4; i++){    
        printf("Nota do %i teste: ",cont2);
        scanf("%f",&nota4[i]);
        if(nota4[i] < 0 || nota4[i] > 10){
            printf("as notas devem ser entre 0 e 10.\n");
            printf("Digite a nota novamente: ");
            scanf("%f",&nota4[i]);
        }
        cont2++;
    }
    
    printf("Digite as notas da categoria %s:\n",cat[4]);
    
    cont2 = 1;
    
    for(i = 0; i < c5; i++){    
        printf("Nota do %i teste: ",cont2);
        scanf("%f",&nota5[i]);
        if(nota5[i] < 0 || nota5[i] > 10){
            printf("as notas devem ser entre 0 e 10.\n");
            printf("Digite a nota novamente: ");
            scanf("%f",&nota5[i]);
        }
        cont2++;
    }
    
    float maior[n], menor[n];
    
    maior[0] = 0; menor[0] = 11;
    maior[1] = 0; menor[1] = 11;
    maior[2] = 0; menor[2] = 11;
    maior[3] = 0; menor[3] = 11;
    maior[4] = 0; menor[4] = 11;
    
     for(i = 0; i < c1; i++){ 
        if(maior[0] < nota1[i]){
            maior[0] = nota1[i];
        }
        if(menor[0] > nota1[i]){
            menor[0] = nota1[i];
        }
     }
     
     for(i = 0; i < c2; i++){ 
        if(maior[1] < nota2[i]){
            maior[1] = nota2[i];
        }
        if(menor[1] > nota2[i]){
            menor[1] = nota2[i];
        }
     }
     
     for(i = 0; i < c3; i++){ 
        if(maior[2] < nota3[i]){
            maior[2] = nota3[i];
        }
        if(menor[2] > nota3[i]){
            menor[2] = nota3[i];
        }
     }
     
     for(i = 0; i < c4; i++){ 
        if(maior[3] < nota4[i]){
            maior[3] = nota4[i];
        }
        if(menor[3] > nota4[i]){
            menor[3] = nota4[i];
        }
     }
     
     for(i = 0; i < c5; i++){ 
        if(maior[4] < nota5[i]){
            maior[4] = nota5[i];
        }
        if(menor[4] > nota5[i]){
            menor[4] = nota5[i];
        }
     }
    
    float soma[n], somaf;
    soma[0] = 0; soma[1] = 0; soma[2] = 0; soma[3] = 0; soma[4] = 0;
    
    for(i = 0; i < c1; i++){
        soma[0] = soma[0] + nota1[i];
    }
    
    soma[0] = soma[0] - menor[0] - maior[0];
    
    for(i = 0; i < c2; i++){
        soma[1] = soma[1] + nota2[i];
    }
    
    soma[1] = soma[1] - menor[1] - maior[1];
    
    for(i = 0; i < c3; i++){
        soma[2] = soma[2] + nota3[i];
    }
    
    soma[2] = soma[2] - menor[2] - maior[2];
    
    for(i = 0; i < c4; i++){
        soma[3] = soma[3] + nota4[i];
    }
    
    soma[3] = soma[3] - menor[3] - maior[3];
    
    for(i = 0; i < c5; i++){
        soma[4] = soma[4] + nota5[i];
    }
    
    soma[4] = soma[4] - menor[4] - maior[4];
    
    for(i = 0; i < n; i++){
        somaf = somaf + soma[i];
    }
    
    printf("As notas finais do candidato foram:\n");
    
    for(i = 0; i < n; i++){
        printf("Na categoria %s: %.2f\n",cat[i], soma[i]); 
    }
    
    printf("A nota final do teste foi: %.2f",somaf);
    
    
    return 0;
}
