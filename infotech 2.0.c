#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define SIZE 3

// Declaração de Struct que será utilizada por todas as funções

typedef struct {
	
	int id;
	char descricao[30];
	char modelo[20];
	char fornecedor[20];
	char tipo[20];
	int quantidade;
	float valor;
		
}produto;

produto produtos[SIZE];

// Declaração das funções

void menu();
void cadastro ();
void pesquisa ();
void lista ();

//Função Principal

int main (){
			
	menu();
	
	return 0;		
	
}
 
// fim da função principal

// Função do Menu inicial

void menu(){
	
	setlocale (LC_ALL, "portuguese"); // Acentuação de acordo com idioma Português  
		
	int i, contador, operador, opcao; // Declarando variáveis que será utilizado dentra da função main 
	
	do{
	
	
		printf("       --- Programa Infotech 2.0 Deluxe ----"); // Nome do programa
		printf("\n       |                                   |");
		printf("\n       |                                   |");
		printf("\n       |      1 - Cadastrar Produto        |");
		printf("\n       |      2 - Pesquisar do Produto     |");
		printf("\n       |      3 - Gerar relatório          |");
		printf("\n       |      4 - Finalizar programa       |");
		printf("\n       |                                   |");
		printf("\n       |                                   |");
		printf("\n       -------------------------------------");
	
		printf("\n\nOpção escolhida: ");
		scanf("%d", &opcao); // escolha do usuário
										
		switch (opcao){
			case 1:
				
				system ("cls"); // função para limpar a tela
		
				cadastro(); // Chamando a função cadastro se caso usuário digitar 1
				
				break;
			
			case 2:
				
				system ("cls");
				
				pesquisa(); // Chamando a função de pesquisa se caso usúario digitar 2
								
				break;
				
			case 3:
				
				system ("cls");				
									
				lista(); // Chamando a função para gerar relatórios
				
				break;			
								
			case 4:
				
				exit;				
	}
			
		system ("cls");
		
		printf("Fim do Sistema !"); // Finalizar programa				
												
	} while ( opcao != 4 );	
}

// Fim da Função de menu inicial

// Inicio da função de cadastro
	
void cadastro (){ 

	int operador, decisao;  // Variaveis que serão utilizado pela função cadastro
	
	int qdt = 1;
		
	do{			
		
		if( qdt < SIZE){
			
			unsigned int cp    = 1252; // Configurar sistema para receber acentuação na string
		
			SetConsoleCP(cp);       //Estabelecendo o codepage de entrada 1252(latin2)
    		SetConsoleOutputCP(cp);  //Estabelecendo o codepage de saída 1252(latin2)		
			
			fflush(stdin); // Apagar sujeira de memória
			
			printf(" --------------------------");
			printf("\n |  Cadastro de Produtos  |"); // Título da Janela
			printf("\n --------------------------");
		
			printf("\n\n"); // Espaçamento para não ficar tudo unido
		
			printf("ID: %d", qdt); // Cadastro de ID do Produto
			printf("\n");
			
			produtos[qdt].id = qdt;
		
			printf("Descrição: "); // Cadastro de descrição do Produto
			fflush(stdin);
			fgets(produtos[qdt].descricao, 30, stdin);
					
			printf("Modelo: "); // Cadastro de modelo do Produto
			fflush(stdin);
			fgets(produtos[qdt].modelo, 20, stdin);
					
			printf("Fornecedor: "); // Cadastro de fornecedor do Produto
			fflush(stdin);
			fgets(produtos[qdt].fornecedor, 20, stdin);
					
			printf("Tipo: "); // Cadastro de tipo do Produto
			fflush(stdin);
			fgets(produtos[qdt].tipo, 20, stdin);
					
			printf("Quantidade: "); // Cadastro de quantidade do Produto
			scanf("%d", &produtos[qdt].quantidade);
					
			printf("Valor: "); // Cadastro de valor do Produto
			scanf("%f", &produtos[qdt].valor);
			printf("\n");		 						
						
			printf("Digite 1-Salvar ou 2-Cancelar: "); // Perguntar pro usuário se deseja salvar os dados no banco
			scanf("%d", &decisao);						
		
			if( decisao == 1 ){
				FILE *arq = fopen("C:/Users/gog_e/OneDrive/Ambiente de Trabalho/infotech Linguagem C/Banco de dados.txt", "w");
						
				if(arq){
					
					fprintf(arq, "ID: %i\n", produtos[qdt].id);
					fprintf(arq, "Descrição: %s", produtos[qdt].descricao);
					fprintf(arq, "Modelo: %s", produtos[qdt].modelo);
					fprintf(arq, "Fornecedor: %s", produtos[qdt].fornecedor);
					fprintf(arq, "Tipo: %s", produtos[qdt].tipo);
					fprintf(arq, "Quantidade: %i\n", produtos[qdt].quantidade);
					fprintf(arq, "Valor: R$ %.2f\n\n", produtos[qdt].valor);
			
					fclose(arq);	
					
					printf("Produto Salvo com Sucesso!");					
		
				}
	
				else{
					
					printf("ERRO: não foi possivel abrir o arquivo.\n\n");
					
				}
				
			}
						
		}		
		
		else{
			
			printf("Error, não tem mais espaço para cadastrar produtos, Limite de %i produtos estourado.", SIZE);
			printf("\n");
						
		}
		
		qdt++;		
		
		printf("\n\n");
						
		printf("\n1-Cadastrar novamente 2-voltar ao menu: "); // Decisão para cadastrar novamente repete o do while se digitar 2 volta no menu inicial
		scanf("%d", &operador);
						
		printf("\n\n");
		
		system("cls"); // Limpar a tela 
						
	} while( operador == 1 );	
	
	system ("cls");
	
	main ();		// Retornar para main
	
} 

// Fim da Função de cadastro

// Início da função de pesquisa

void pesquisa (){

	int i, operador, tam;
		
	do{
		
		printf(" --------------------------");
		printf("\n |  Pesquisa de Produtos  |"); // Título da Janela
		printf("\n --------------------------");
			
		printf("\nDigite a ID: ");
		scanf("%d", &i);
							
			if ( produtos[i].id == i ){
				
				
				printf("ID: %i\n", produtos[i].id);
				printf("Descrição: %s", produtos[i].descricao);
				printf("Modelo: %s", produtos[i].modelo);
				printf("Fornecedor: %s", produtos[i].fornecedor);
				printf("Tipo: %s", produtos[i].tipo);
				printf("Quantidade: %i\n", produtos[i].quantidade);
				printf("Valor: R$ %.2f", produtos[i].valor);
			
				printf("\n\n");			
			}
					
			else{
				printf("Não tem produto cadastrado com esse ID.");
			}
		
		
		printf("\n1-Pesquisar Novamente ou 2-Voltar menu: ");
		scanf("%d", &operador);
		
		system("cls");
	
	} while( operador == 1 );
	
	system ("cls");
	
	main();
}

//Fim da função de pesquisa

//Inicio da função de lista

void lista (){
	
	int i, operador;
	
		printf(" ---------------------------------------");
		printf("\n |  Produtos de Produtos Cadastrados.  |"); // Título da Janela
		printf("\n ---------------------------------------");
	
	printf("\n\n");
	
	do{		
	
		for ( i = 1; i < SIZE; i++){				
				
			printf("ID: %i\n", produtos[i].id);
			printf("Descrição: %s", produtos[i].descricao);
			printf("Modelo: %s", produtos[i].modelo);
			printf("Fornecedor: %s", produtos[i].fornecedor);
			printf("Tipo: %s", produtos[i].tipo);
			printf("Quantidade: %i\n", produtos[i].quantidade);
			printf("Valor: R$ %.2f", produtos[i].valor);
			
			printf("\n\n");			
					
		}
		
		printf("\n\n");
		
		system ("pause");
		
		printf("\n\n1-Atualizar página ou 2-Voltar ao menu: ");
		scanf("%i", &operador);
		
		system("cls");
		
	}while( operador != 2);

}

// Fim da Função de Pesquisa


