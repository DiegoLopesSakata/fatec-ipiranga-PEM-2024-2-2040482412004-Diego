// Criador do Código: Diego Lopes Sakata 
// Esse é o código certo com todas as automações e contigências de erros.

#include <stdio.h>

int main()
{
    int n, i, a = 0, cont = 1;
    
    printf("Esse programa calculará a nota final do candidato.\n");
    printf("Quantas categorias diferentes existem?\n");
    printf("R: ");
    scanf("%i",&n);
    
    if(n > 0){
    char cat[n][100];
    
    for(i = 0; i < n; i++){
        printf("Digite o nome da %i categoria: ",cont);
        scanf(" %99[^\n]",cat[i]);
        cont++;
    }
    
    int test[n];
    
    for(i = 0; i < n; i++){
        printf("Quantos testes tem na categoria %s: ",cat[i]);
        scanf("%i",&test[i]);
        while(test[i] <= 2){
            printf("O número de testes deve ser maior do que 2.\n");
            printf("Digite novamente o número de testes presente na categoria: ");
            scanf("%i",&test[i]);
        }
    }
    
    for(i = 0; i < n; i++){
        if (a < test[i]){
            a = test[i];
        }
    }
    
    float notas[n][a], maior[n], menor[n], soma[n+1];
    
    
    for(i = 0; i < n; i++){
        printf("Digite as notas dos testes de %s\n",cat[i]);
        for(a = 0; a < test[i]; a++){
            printf("Nota do %i teste: ",a + 1);
            scanf("%f",&notas[i][a]);
            while(notas[i][a] < 0 || notas[i][a] > 10){
                printf("As notas devem ser entre 0 e 10.\n");
                printf("Entre com a nota novamente: ");
                scanf("%f",&notas[i][a]);
            }
        }
    }
    
    for(i = 0; i < n; i++){
        maior[i] = 0;
        menor[i] = 10;
        for(a = 0; a < test[i]; a++){
            if(maior[i] < notas[i][a]){
                maior[i] = notas[i][a];
            }
            if(menor[i] > notas[i][a]){
                menor[i] = notas[i][a];
            }
        }
    }
    
    for(i = 0; i < n; i++){
        soma[i] = 0;
        
        for(a = 0; a < test[i]; a++){
            soma[i] = soma[i] + notas[i][a];
        }
    }
    
    for(i = 0; i < n; i++){
        soma[i] = soma[i] - maior[i] - menor[i];
    }
    
    soma[n+1] = 0;
    
    for(i = 0; i < n; i++){
        soma[n+1] = soma[n+1] + soma[i];
    }
    
    // A partir daqui o "é" está escrito como "eh", pois algumas vezes o acento agudo pode dar problema na línguagem C e não aparecer.
    
    for(i = 0; i < n; i++){
        printf("A nota da categoria %s eh: %.2f\n",cat[i],soma[i]);
    }
    
    printf("A nota final do candidato eh: %.2f",soma[n+1]);
    
    }
    
    else{
        printf("Não existem categorias para calcular a nota.");
    }


    return 0;
}
