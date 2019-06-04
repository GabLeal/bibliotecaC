#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro{
    int id;
    char nome[40];
    int quantidade;
}Livro;

/*   Livro vetor_livro[2];
    printf("CADASTRANDO LIVROS\n \n");
    for (int i = 0; i < 2; i++){
        printf("Nome do livro: ");
        scanf(" %[^\n]",vetor_livro[i].nome);
        printf("Quantidade: ");
        scanf("%d",&vetor_livro[i].quantidade);
    }
    printf("\n");
    printf("CONUSLTANDO TODOS OS LIVROS \n \n");
    for (int i = 0; i < 2; i++) {
        printf("Nome: %s \n",vetor_livro[i].nome);
        printf("Quantidade: %d\n",vetor_livro[i].quantidade);

        printf("\n \n");
    }*/

void cadastroLivro(int livrosCadastrados, Livro livros[],int maxLivros[]){
        //livros = (Livro *) realloc(livros, livrosCadastrados*sizeof(Livro));
        
        livros[livrosCadastrados].id = livrosCadastrados;
        printf("Nome do livro: ");
        scanf(" %[^\n]",livros[livrosCadastrados].nome);
        printf("Quantidade: ");
        scanf("%d",&livros[livrosCadastrados].quantidade);
        maxLivros[livrosCadastrados] = livros[livrosCadastrados].quantidade;
}

void consultarLivros(int livrosCadastrados, Livro livros[]){
    printf("\n");
    for (int i = 0; i <= livrosCadastrados; i++) {
        printf("ID: %d \n",livros[i].id);
        printf("Nome: %s \n",livros[i].nome);
        printf("Quantidade: %d\n",livros[i].quantidade);

        printf("\n");
    }
}

void retirarLivros(Livro livro[], int livrosCadastrados, int opc, int maxLivros[]){
    int id;
    int cont = 0;

    if (opc==3){
        printf("Digite o ID do livro que sera retirado: ");
        scanf("%d",&id);

        for (int i = 0; i <= livrosCadastrados; i++){
            if (id == livro[i].id){
                livro[i].quantidade -= 1;
                printf("Retirada efetuada com sucesso! \n");
                cont++;
            }

        }

        if (cont==0){
            printf("O livro solicitado não existe em nossos registros. \n");
        }

    }else{
        printf("Digite o ID do livro que sera devolvido: ");
        scanf("%d",&id);
        
        for (int i = 0; i <= livrosCadastrados; i++){
            if (id == livro[i].id && livro[i].quantidade < maxLivros[i]){
                livro[i].quantidade += 1;
                printf("Devolução efetuada com sucesso! \n");
                cont++;
            }

        }

        if (cont==0){
            printf("O livro solicitado não existe em nossos registros ou você está excedendo o limite.\n");
        } 
    }

}


int main (){
    int opc;
    //int livrosCadastrados = 1;
    int livrosCadastrados = -1;
    Livro livros[10];
    int id;
    int maxLivros[10];
    
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
            livrosCadastrados += 1;
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