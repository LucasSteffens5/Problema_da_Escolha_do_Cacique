#include <stdio.h>
#include <stdlib.h>

typedef struct lista
    {
	struct node *ini;
	} lista;
typedef struct node
	{
	int ficha;
	struct node *prox;
	} no;

void incluir(lista *inicio,int v);
void mostrar(lista *inicio);
void excluir(lista *inicio, int setstep );

void main()
	{
	//determinar o passo em setstep (exclui de 2 em 2 quando atribu�do 2)
	int c, flag_cont=1, setstep, q = 21, ex = 1; //ex = 1 � s� pra controle
  printf("Digite o numero de candidatos a Cacique \n: ");
  scanf("%i", &q);
  printf("%i\n", q);
  printf("Digite o numero do salto:\n");
  scanf("%i", &setstep);
  printf("%i\n", setstep);
	//aloca mem�ria para os n�s
	lista *c_lista;
	c_lista = (lista *)malloc(sizeof(lista));
	c_lista->ini = NULL;

	//cria os candidados/n�s e atribui uma ficha a cada um deles
	for(c=1;c <= q;c++)//insere quantos condidatos conforme o numero determinado em q
		{
		incluir(c_lista,c); //c � o valor da ficha atribuida ao cacique e a fun��o cria o n�
		}

	printf("Lista Criada \n: ");
	mostrar(c_lista); //mostra lista gerada

	if(ex)
		{
		excluir(c_lista,setstep); // excluir
		}


//	printf("\n\nlista final: ");
//	mostrar(c_lista); //mostra lista ap�s exclus�o
	}

void incluir(lista *inicio,int v)
	{
    no *candidato, *aux_r;

	candidato = (no *)malloc(sizeof(no));  // Aloca o Nó
	candidato->ficha = v; // Coloca o valor da ficha do candidato
	candidato->prox = NULL; // Seta o prox para NULL e testa as condições da lista circular

	if(inicio->ini == NULL) // Se o inicio é nulo aloca no no do candidato e aponta o prox para ele mesmo
		{
	    inicio->ini = candidato; candidato->prox = inicio->ini;
		}
	else // Se nao for ja existe nos nas fila adiciona no final e aponta o ultimo pro primeiro
		{
		aux_r = inicio->ini;  // Ponteiro auxiliar recebe o inicio da lista
		while(aux_r->prox != inicio->ini)// e enquanto o proximo nao for o inicio segue pegando o endereco do proximo
			{
			aux_r = aux_r->prox;
			}
		aux_r->prox = candidato; // Coloca o novo no no final e aponta o proximo dele para o incio da lista
		candidato->prox = inicio->ini;
		}
	}

void mostrar(lista *inicio) // Mostra a lista
	{
	no *candidato;
	candidato = inicio->ini;

	if(candidato == NULL)
		{
		printf("Lista vazia\n");
		}
	else if(candidato->prox == candidato)//quando apenas um candidato na lista
		{
		printf("\n - Unico candidato a Cacique ficha numero:- %d\n",candidato->ficha);
		}
	else
		{
		printf("\n - candidato a Cacique ficha numero: - %d\n",candidato->ficha); // Quando tem mais de um // N tem sentido esse print
		candidato = candidato->prox;

		while (candidato != inicio->ini )
			{
			printf("\n - candidato a Cacique ficha numero: - %d\n",candidato->ficha);
			candidato = candidato->prox;
	        }
  		}
	}

void excluir(lista *inicio, int setstep )
	{
    int aux = setstep;
    no *candidato, *auxantes, *auxdps;
    candidato = inicio->ini;

    if(candidato == NULL)
  		{
  		printf("Lista vazia, nenhum candidato a cacique\n");

  		}
    else if(candidato->prox == candidato)//quando apenas um candidato na lista
        {
        printf("\n - Unico candidato e novo Cacique ficha numero:- %d\n",candidato->ficha);
        }


    while (candidato->prox != candidato ) // Equanto nao tiver apenas um no na lista
    			{aux = aux-1;  // Subtrai o auxiliar do passo e vai pro proximo
            auxantes = candidato;
            candidato = candidato->prox;
            auxdps = candidato->prox;
            if(aux==1){ // quando auxiliar se torna zero remove o no que esta e volta o valor do passo
              aux = setstep;
              free(candidato);
              auxantes->prox = auxdps;
              candidato = auxantes->prox;
            }


              }

            printf("\n -Vencedor e novo Cacique ficha numero:- %d\n",candidato->ficha);
            free(candidato);


}
