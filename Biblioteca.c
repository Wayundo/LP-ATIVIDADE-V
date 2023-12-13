#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 2

struct cadastro{
   char nome[500];
   int idade;
};

struct livro{
	char livro[500];
	char autor [500];
};

void AdicionarLivro(struct livro livros[], int total_livros){
 for (int i = 0; i < total_livros; ++i) {
        printf("\n Adicionar o %d: livro\n", i + 1);

        printf("Digite o titulo do livro: ");
        scanf("%s", livros[i].livro);
        
        printf("Digite o nome do autor: ");
        scanf("%s", livros[i].autor);

    }
}
    
void VerLivros(struct livro livros[], int total_livros){
 printf("\nMostrando livros adicionados:\n");
    for (int i = 0; i < total_livros; ++i) {
        printf("\n %dº Livro:\n", i + 1);
        
        printf("Titulo: %s\n", livros[i].livro);
        
        printf("Autor: %s\n", livros[i].autor);
    }

}
 
    
void CadastrarUsuario(struct cadastro usuarios[], int total_usuarios){
 for (int i = 0; i < total_usuarios; ++i) {
        printf("\nCadastro do Usuario %d:\n", i + 1);

        printf("Digite o nome do usuario: ");
        scanf("%s", usuarios[i].nome);

        printf("Digite a idade do usuario: ");
        scanf("%d", &usuarios[i].idade);
    }
}
    
void VerUsuario(struct cadastro usuarios[], int total_usuarios){
 printf("\nMostrando Informacoes dos Usuarios:\n");
    for (int i = 0; i < total_usuarios; ++i) {
        printf("\nUsuario %d:\n", i + 1);
        
        printf("Nome: %s\n", usuarios[i].nome);
        
        printf("Idade: %d\n", usuarios[i].idade);
    }

}

int PesquisarUsuario(struct cadastro usuarios[], int total_usuarios, char nome[]) {
    for (int i = 0; i < total_usuarios; ++i) {
        if (strcmp(usuarios[i].nome, nome) == 0) {
            return i; 
        }
    }
    return -1;
}

int main (){

setlocale(LC_ALL, "portuguese");

int escolha;
struct cadastro usuarios[TAM];
int total_usuarios = 0;
struct livro livros[TAM];
int total_livros = 0;
char nome[500];
int indice;


do{

 printf("\nMenu da Biblioteca:\n");
        printf("1 - Adicionar um Livro. \n");
        printf("2 - Ver livros. \n");
        printf("3 - Cadastrar Usuário.\n");
        printf("4 - Ver Usuários. \n");
        printf("5 - Pesquisar Usuários. \n");
        printf("6 - Data de devolução. \n");
        printf("7 - Sair do programa\n");
        printf("Escolha a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
            AdicionarLivro(livros, TAM);
            total_livros = TAM;
                break;
            }
            case 2: {
            VerLivros(livros, total_livros);

                break;
            }
            case 3: {
            CadastrarUsuario(usuarios, TAM);
            total_usuarios = TAM;
        
                break;
            }
            case 4:{
            VerUsuario(usuarios, total_usuarios);
                break;
            }
            case 5: {
            printf("\nDigite o nome do usuário a ser pesquisado: ");
            scanf("%s", nome);
            indice = PesquisarUsuario(usuarios, total_usuarios, nome);
             if (indice != -1) {
                    printf("Usuário encontrado!\n");
                    printf("Nome: %s\n", usuarios[indice].nome);
                    printf("Idade: %d\n", usuarios[indice].idade);
                } else {
                    printf("Usuário não encontrado.\n");
                }
			    break;
            }
            
            case 6: {
            printf("\n Data de Devolução: \n");
            printf("01/01/2024");
			    break;
            }
            
            case 7: {
            printf("Saindo do programa. Até logo!\n");
			    break;
            }
          
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    }while (escolha != 7);

    return 0;
}