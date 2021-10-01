/*
 Este é um esqueleto que deve ser utilzado como base para implementação da Lista de tarefas;
	- As funções não têm os parâmetros definidos; se necessário, estes devem ser incluídos;
 	- Devem ser respeitados os nomes atribuidos aos métodos e estruturas, porém, novas estruturas e funções podem ser criadas, caso julgue necessário;
	- Faça os includes necessários;
	- A organização das funções fica a critério do programador;
	- Códigos não indentados sofrerão duras penalidades;
	- Não serão toleradas variaveis globais;
	- Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/

#include <stdio.h> 


#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

//Struct que representa a data.
typedef struct {
	int day;
	int month;
} Date;
/ Estrutura que contém os campos dos registros das tarefas
struct REC {
       char nome[50];
       int prioridade;
       Date entrega; 
	  struct REC *next; // implemente como lista, como árvore BST, AVL...
	  struct REC *prev;
};

// Tipo criado para instanciar variaveis do tipo acima
typedef struct REC Task;
// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
    int op=0;
    while (op!=EXIT)
    {
        printf("%d Finaliza",EXIT);
        printf("\n: ");
        scanf("%d",&op);
       break;
    }
    return op;
}

// Permite o cadastro de uma tarefa
Task *insTask(Task *contact)
{
    Task *aux, *new;
    new = (Task *)malloc(sizeof(Task));

    printf("Por favor digite o nome da pessoa\n");
    scanf("%s", new->nome);
    printf("Por favor digite o email da pessoa\n");
    scanf("%s", new->prioridade);
    printf("Por favor digite o numero de telephone da pessoa\n");
    scanf("%s", new->entrega);

    //fim da leitura dos dados
    if (contact == NULL)
    {
        contact = new;
        printf("-------------------------------------------------\n");
        printf("O seu novo contato foi inserido com sucesso!\n");
        printf("-------------------------------------------------\n");
        return contact;
         //pois ele vai ser o primeiro elemento da lista.
    }
     else
    {
        //lógica para adionar mais elementos.
        aux = contact;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        //chegou aqui, o aux tem o último elemento;
        aux->next = new;
        aux->next->next = NULL;
    }


    printf("-------------------------------------------------\n");
    printf("O seu novo contato foi inserido com sucesso!\n");
    printf("-------------------------------------------------\n");


    return contact;
}