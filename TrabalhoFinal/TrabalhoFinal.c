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
// Estrutura que contém os campos dos registros das tarefas
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

// Permite excluir uma tarefa
Task *delTask(Task *task, char *name)
{
    Task *aux, *anterior = NULL;
    int cont;

    if (task == NULL)
    {
        printf("Infelizmente não temos contatos!\n");
    }

    for (aux = task; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->nome, name) == 0)
        {
            
            if (task == aux)
            {
                task = aux->next;
            }
            else
            {
                anterior->next = aux->next;
            }
            free(aux);
            cont = 1;
        }
        anterior = aux;
    }
    if (!cont)
    {
        printf("Infelizmente não temos contatos!\n");
    }
    printf("-------------------------------------------------\n");
    printf("O seu novo contato foi excluido com sucesso!\n");
    printf("-------------------------------------------------\n");
    return task;
}

// Lista o conteudo da agenda (todos os campos)
void listTasks(Task *task)
{   
  Task *aux;
  if(task == NULL){
    printf("Infelizmente não temos contatos!\n"); 
  }
    printf("-------------------------------------------------\n");
    printf("O contatos cadastrados!!!\n");
    printf("-------------------------------------------------\n");
  aux = task;
  while(aux !=NULL){
    printf("-> %s, %s, %s\n", aux->nome, aux->prioridade, aux->entrega);
    aux = aux->next;
  }
    
}

// Permite consultar uma tarefa da lista pelo nome
void *queryTask(Task *contact, char name[100])
{  
    Task *aux;
    int cont;

    if (contact == NULL)
    {
        printf("Infelizmente não temos contatos!\n");
    }
    printf("-------------------------------------------------\n");
    printf("Os dados do %s sâo!!!\n", name);
    printf("-------------------------------------------------\n");

    for (aux = contact; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->nome, name) == 0)
        {
                printf("%s, %s, %s\n", aux->nome, aux->prioridade, aux->entrega);
            cont = 1;
        }
    }
    if (!cont)
    {
        printf("Infelizmente não temos contatos!\n");
    }
    
}

// Permite a atualização dos dados de uma tarefa
void upTask ()
{
     return;
}

// Programa principal
int main()
{
    int op=0;
    Task t;

    while (op!=EXIT)
    {
          op=menu();
          switch(op)
          {
              case 1 : //insTask();
                   first = insTask(first);
                   printf("\n");
                   break;
              case 2 : //delTask();
                  printf("Por favor digite o nome da pessoa que você quer excluir\n");
                  scanf("%s", nome);
                  first = delTask(first, nome);
                  printf("\n");
                  break;
              //case 3 : //upTask();
                   
              case 4 : //queryTask();
                   printf("Por favor digite o nome da pessoa que você quer consultar\n");
                   scanf("%s", nome);
                   queryContact(first, nome);
                   printf("\n");
                   break;
              //case 5 : listTasks();
          }
    }
    return 0;
}
