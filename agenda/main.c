#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <string.h>
 
int main(void)
{
	
	struct nomeS{
		char nome[50];
	};
	
    int *num, *numero; 
    int i, num_componentes = 0, option, j = 0, k =0;
    struct nomeS *nome;
	
    nome = (struct nomeS *)malloc(sizeof(struct nomeS)*num_componentes);
    numero = (int *) malloc(sizeof(int) * num_componentes);
    num = (int *) malloc(num_componentes * sizeof(int));
    
    while(1){
    	printf("\nAgenda Telefônica\n");
    	printf("1 - Adicionar\n");
    	printf("2 - Remover\n");
    	printf("3 - Listar\n");
    	printf("0 - Sair\n");
    	printf("Seleione a opcao: \n");
    	scanf("%d", &option);
    	setbuf(stdin, NULL);
	    switch(option){
	    	case 1:
	    		nome = realloc(nome, sizeof(struct nomeS) * (num_componentes + 1));
	    		printf("Digite o nome: \n");
	    		scanf("%[^\n]s", &nome[j].nome);
	    		setbuf(stdin, NULL);
	    		printf("\nDigite o numero: ");
	     		scanf("%d", &num[j]);
	     		num_componentes = num_componentes + 1;
	     		j = j + 1;
	     		break;
	     	case 2:
	     		printf("\nDigite o numero para remover: ");
	     		scanf("%d", &numero);
	     		for(i = 0; i < num_componentes; i++){
					if(num[i] == numero){
						num[i] = NULL;
						*nome[i].nome = NULL;
					}
				}
				numero = NULL;
				break;
			case 3:
				printf("*** Lista de contatos ***\n"); 
				for(i = 0; i < num_componentes; i++){
					if(num[i] != 0){
						printf("%d ----- %s \n", num[i], nome[i].nome);
					}

				}
				break;
			case 0: 
				free(nome);
				free(numero);
				free(num);
				exit(0);
				break;
			default: 
				printf("Opcao incorreta\n");
				break;
	    }
	}
    
   return 0;
} 
