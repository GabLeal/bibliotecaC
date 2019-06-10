#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Livro{
    int id;
    char nome[40];
    int quantidade;
}Livro;

void cadastroLivro(int livrosCadastrados, Livro livros[],int maxLivros[]){
        //livros = (Livro *) realloc(livros, livrosCadastrados*sizeof(Livro));
        
        livros[livrosCadastrados].id = livrosCadastrados;
        
        printf("Nome do livro: ");
        scanf(" %[^\n]",livros[livrosCadastrados].nome);
        printf("Quantidade: ");
        scanf("%d",&livros[livrosCadastrados].quantidade);
        maxLivros[livrosCadastrados] = livros[livrosCadastrados].quantidade;

        //Usando arquivos para salvar
        FILE* arqSaida = fopen("arquivo.txt","a");
        fprintf(arqSaida,"%d %d %s \n",livros[livrosCadastrados].id,livros[livrosCadastrados].quantidade,livros[livrosCadastrados].nome);
        fclose(arqSaida);
}

void consultarLivros(int livrosCadastrados, Livro livros[]){
    printf("\n");
    FILE* arqnome = fopen("arquivo.txt","r");
    int contador = 0;


    if (arqnome != NULL){
        while (fscanf(arqnome, "%d %d %[^\n]s",&livros[contador].id, &livros[contador].quantidade,livros[contador].nome) != EOF){
            
            printf("ID: %d \n",livros[contador].id);
            printf("Nome: %s \n",livros[contador].nome);
            printf("Quantidade: %d\n",livros[contador].quantidade);

            printf("\n");

            contador++;
        }  
    }

    fclose(arqnome);
    

   /*
    for (int i = 0; i <= livrosCadastrados; i++) {
        printf("ID: %d \n",livros[i].id);
        printf("Nome: %s \n",livros[i].nome);
        printf("Quantidade: %d\n",livros[i].quantidade);

        printf("\n");
    }
    */
}

void retirarLivros(Livro livro[], int livrosCadastrados, int opc, int maxLivros[]){
    int id;
    int cont = 0;
     printf("\e[H\e[2J");
    if (opc==3){
        printf("Digite o ID do livro que sera retirado: ");
        scanf("%d",&id);

        for (int i = 0; i <= livrosCadastrados; i++){
            if (id == livro[i].id){
                livro[i].quantidade -= 1;
                printf("Retirada efetuada com sucesso... \n");
                cont++;
                sleep(1.5);
                printf("\e[H\e[2J");
            }

        }

        if (cont==0){
            printf("O livro solicitado não existe em nossos registros... \n");
            sleep(1.5);
        }

    }else{
        printf("Digite o ID do livro que sera devolvido: ");
        scanf("%d",&id);
        
        for (int i = 0; i <= livrosCadastrados; i++){
            if (id == livro[i].id){
                
                if (livro[i].quantidade < maxLivros[i]){
                    livro[i].quantidade += 1;
                    printf("Devolução efetuada com sucesso... \n");
                }else{
                    printf("Ops! Todos as edições desse livro já foram devolvidas. Tente novamente... \n");
                }
                
                cont++;
            }

        }

        if (cont==0){
            printf("O livro solicitado não existe em nossos registros...\n");
            
        } 
    }
    sleep(1.5);
    printf("\e[H\e[2J");
}


int main (){
    int opc;
    //int livrosCadastrados = 1;
    //int livrosCadastrados = -1;
    int livrosCadastrados;
    Livro livros[10];
    int id;
    int maxLivros[10];

    //ARQUIVOS
    
    //livros = (Livro *) malloc(livrosCadastrados * sizeof(Livro)); 
    
    do{
        
        printf("1-Cadastrar livro \n");
        printf("2-Consultar livro \n");
        printf("3-Retirar livro \n");
        printf("4-Devolução \n");


        printf("5- Sair\n");
        scanf("%d",&opc);

        switch (opc){
        case 1:
            printf("\e[H\e[2J");
            //livrosCadastrados += 1;
            //arquivo
            FILE* arqQdtR = fopen("qtdlivros.txt","r");
            fscanf(arqQdtR,"%d",&livrosCadastrados);
            fclose(arqQdtR);
            livrosCadastrados++;
            FILE* arqQdtW = fopen("qtdlivros.txt","w");
            fprintf(arqQdtW,"%d",livrosCadastrados);
            fclose(arqQdtW);

            
            //arquivo
            cadastroLivro(livrosCadastrados, livros, maxLivros);
            printf("\e[H\e[2J");
            
            break;
        
        case 2:
            printf("\e[H\e[2J");
            consultarLivros(livrosCadastrados, livros);
            break;

        case 3:
            retirarLivros(livros,livrosCadastrados,opc,maxLivros);
            break;

        case 4:
            retirarLivros(livros,livrosCadastrados,opc,maxLivros);
            break;
        }

    }while(opc != 5);
    return 0;
}