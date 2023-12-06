#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()	//Fun��o responsavel pela cria��o de usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	char arquivo [14];	//nome do arquivo que ser� gerado, mesmo do cpf
	char cpf[14];	//tamanho maximo de cpf - 14 digitos
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int novo_registro=1;	//variavel para verificar op��o de novo registro
	
	do
	{
		printf("|||		Registro de Novo Usu�rio da EBAC		|||\n\n");
		printf("Digite o CPF para registro: ");
		scanf("%s",cpf);
			
		strcpy(arquivo,cpf);
			
		FILE *file;
		file=fopen(arquivo, "w");	//cria arquivo de dados, com o mesmo valor de cpf. "w" para criar, Write
		fprintf(file,cpf);
		fprintf(file," , ");
		fclose(file);
			
		printf("\nDigite o Nome para registro: ");
		scanf("%s",nome);
			
		file=fopen(arquivo, "a");	//atualiza��o do arquivo com a variavel nome. "a" para atualizar
		fprintf(file,nome);
		fprintf(file," , ");
		fclose(file);
			
		printf("\nDigite o Sobrenome para registro: ");
		scanf("%s",sobrenome);
			
		file=fopen(arquivo, "a");	//atualiza��o do arquivo com a variavel sobrenome
		fprintf(file,sobrenome);
		fprintf(file," , ");
		fclose(file);
		
		printf("\nDigite o Cargo para registro: ");
		scanf("%s",cargo);
			
		file=fopen(arquivo, "a");	//atualiza��o do arquivo com a variavel cargo
		fprintf(file,cargo);
		fclose(file);
			
		printf("\n\nRealizar novo registro?		(1) para sim\n");
		scanf("%i",&novo_registro);	
		system("cls");
	}
	while(novo_registro == 1);	//Enquanto o usu�rio escolher o digito "1" ser� realizado novo registro
}

int consulta()	//Fun��o responsavel pela consulta de usu�rio no banco de dados
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[14];
	char conteudo[144];		//tamonho maximo que arquivo contando os tamanhos das variaveis do registro e os espa�amentos e mais um espa�o de seguran�a
	int nova_consulta = 1;
	
	do
	{
		printf("|||		Consultar Usu�rio da EBAC		|||\n\n");
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
			
		FILE *file;
		file = fopen(cpf,"r");	//consulta banco de dados para abrir arquivo cpf informado. "r" read, leitura
		
		if(file == NULL)	//caso cpf informado seja invalido informa usu�rio
		{
			printf("Opera��o invalida, arquivo n�o encontrado.\n");
		}
		while(fgets(conteudo, 144, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		fclose(file);
			
		printf("\n\nRealizar nova consulta?		(1) para sim\n");
		scanf("%d",&nova_consulta);	
		system("cls");
	}
	while(nova_consulta==1);
}

int deletar()	//Fun��o responsavel por deletar o usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[14];
	int novo_del = 1;
		
	do
	{
		printf("|||		Deletar Usu�rio da Listagem da EBAC		|||\n\n");
		printf("Qual o CPF do usu�rio que ser� deletado: \n");
		scanf("%s",cpf);
			
		FILE *file;
		file = fopen(cpf,"r");
			
		if(file == NULL)	//consulta no banco de dados o cpf informado
		{
			printf("O usu�rio n�o foi encontrado, insira outro CPF.\n");
			fclose(file);
		}
		if(file != NULL)	//caso encontre o cpf no banco realiza o processo de deletar
		{
			fclose(file);	//fecha a consulta para liberar o acesso da fun��o de deletar
			remove(cpf);
		
			file = fopen(cpf,"r");	//abre novamente a consulta para verificar se arquivo foi deletado
				
			if(file == NULL)
			{	
				printf("O usu�rio foi deletado com sucesso.\n");
			}
			fclose(file);	//encerra a consulta
		}
			
		printf("\n\nDeseja deletar mais algum usu�rio?		(1) para sim\n");
		scanf("%d",&novo_del);	
		system("cls");
	}
	while(novo_del==1);
}

int main()
{
	int menu=0, laco=0, comp_senha;
	char senha[10]="a";
	setlocale(LC_ALL, "Portuguese");
		
	printf("|||		Listagem de Usu�rios da EBAC		|||\n\n");
	printf("\n\nDigite a senha para acessar o programa: ");
	scanf("%s", senha);
	
	comp_senha = strcmp(senha,"admin");		//fun��o que compara os valores da senha fornecida com a registrada no sistema e salva o valor na variavel, ser� 0 no caso de ser igual
	
	if(comp_senha == 0)
	{
		for(laco=1;laco=1;)	//la�o de repeti��o do menu
		{
		
			system("cls");
			printf("|||		Listagem de Usu�rios da EBAC		|||\n\n");
			printf("Escolha a op��o desejada no menu:\n\n");
			printf("\t*1 - Registrar novo nome de usu�rio\n");
			printf("\t*2 - Consultar nomes registrados\n");
			printf("\t*3 - Deletar usu�rio\n");
			printf("\n\t*4 - Finalizar o Programa\n");
			printf("Op��o: ");
			scanf("%d", &menu);
			system("cls");
			//printf("\n\n***Esse Software � de livre uso dos alunos da EBAC***\n***Desenvolvido por Erik Luiz Manosso***");
		
			switch(menu)	//escolha da op��o do menu
			{
				case 1:
					registro();
				break;
				
				case 2:
					consulta();
				break;
				
				case 3:
					deletar();
				break;
					
				case 4:
					return 0;
				break;
					
				default:
					printf("Op��o invalida, tente novamente\n");
					system("pause");
				break;
			}
			
		}
	}
	else{
		printf("Senha invalida!\n");
		system("pause");
	}
	
}
