#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro{
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

void cadastroLivro(int livrosCadastrados, Livro livros[]){
        printf("Nome do livro: ");
        scanf(" %[^\n]",livros[livrosCadastrados].nome);
        printf("Quantidade: ");
        scanf("%d",&livros[livrosCadastrados].quantidade);
}

void consultarLivros(int livrosCadastrados, Livro livros[]){
        printf("\n");
    for (int i = 0; i <= livrosCadastrados; i++) {
        printf("Nome: %s \n",livros[i].nome);
        printf("Quantidade: %d\n",livros[i].quantidade);

        printf("\n");
    }
}

int main (){
    int opc;
    int livrosCadastrados = -1;
    Livro livros[10];
    
    
    do{
        printf("1-Cadastrar livro \n");
        printf("2-Consultar livro \n");

        printf("5- Sair\n");
        scanf("%d",&opc);

        switch (opc){
        case 1:
            printf("\e[H\e[2J");
            livrosCadastrados += 1;
            cadastroLivro(livrosCadastrados, livros);
            printf("\e[H\e[2J");
            
            break;
        
        case 2:
            printf("\e[H\e[2J");
            consultarLivros(livrosCadastrados, livros);
            break;
        }

    }while(opc != 5);
    return 0;
}