#include <stdio.h> //biblioteca de comunição com o usuario
#include <stdlib.h>//biblioteca de alocação de memória
#include <locale.h>//biblioteca de localização
#include <string.h>//biblioteca de manipulação de string

int registro () //Definindo a função registro
{
    char arquivo[20]; //Definindo a variável arquivo como uma string de 20 caracteres
    char cpf[20]; //Definindo a variável cpf como uma string de 20 caracteres
    char nome[20]; //Definindo a variável nome como uma string de 20 caracteres
    char sobrenome[20]; //Definindo a variável sobrenome como uma string de 20 caracteres
    char cargo[20]; //Definindo a variável cargo como uma string de 20 caracteres

    printf("Digite o CPF a ser cadastrado:"); //solicitando ao usuário que digite o CPF a ser cadastrado
    scanf("%s", cpf); //armazenando o CPF digitado pelo usuário na variável


    strcpy(arquivo, cpf); //copiando o valor da variável cpf para a variável arquivo

    FILE *file; //Definindo a variável file como um ponteiro para o arquivo
    file = fopen(arquivo, "w"); //abrindo o arquivo com o nome do CPF digitado pelo usuário, caso o arquivo não exista ele será criado
    fprintf(file, "CPF:"); //escrevendo a palavra "CPF:" no arquivo
    fprintf(file, "%s",  cpf); //escrevendo o CPF no arquivo
    fclose(file); //fechando o arquivo


    file = fopen(arquivo, "a"); //abrindo o arquivo com o nome do
    fprintf(file, "\nNome:"); //escrevendo a palavra "Nome:" no arquivo
    fclose(file); //fechando o arquivo

    printf("Digite o nome a ser cadastrado:"); //solicitando ao usuário que digite o nome a ser cadastrado
    scanf("%s" , nome); //armazenando o nome digitado pelo usuário na variável

    file = fopen(arquivo, "a"); //abrindo o arquivo com o nome do
    fprintf(file, "%s",nome); //escrevendo o nome no arquivo
    fclose(file); //fechando o arquivo

    file = fopen(arquivo, "a"); //abrindo o arquivo com o nome do
    fprintf(file, "\nSobrenome:"); //escrevendo a palavra "Sobrenome:" no arquivo
    fclose (file); //fechando o arquivo

    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s", sobrenome); //armazenando o sobrenome digitado pelo usuário
    
    file = fopen(arquivo, "a"); //abrindo o arquivo com o nome do
    fprintf(file, "%s", sobrenome); //escrevendo o sobrenome no arquivo
    fclose(file); //fechando o arquivo

    file = fopen(arquivo, "a"); //abrindo o arquivo com o nome do
    fprintf(file, "\nCargo:"); //escrevendo a palavra "Cargo:" no arquivo
    fclose (file); //fechando o arquivo

    printf("Digite o seu cargo:"); //solicitando ao usuário que digite o cargo a ser cadastrado
    scanf("%s", cargo); //armazenando o cargo digitado pelo usuário na variável

    file = fopen(arquivo, "a"); //abrindo o arquivo com o nome do
    fprintf(file, "%s", cargo); //escrevendo o cargo no arquivo
    fclose(file); //fechando o arquivo


    return 0; //retornando 0 para indicar que a função foi executada com sucesso

}

int consulta () //Definindo a função consulta
{
    char cpf[20]; //Definindo a variável cpf como uma string de 20 caracteres
    char conteudo[100]; //Definindo a variável conteudo como uma string de 100 caracteres
    
    printf("Digite o CPF a ser consultado:"); //solicitando ao usuário que digite o CPF a ser consultado
    scanf("%s", cpf); //armazenando o CPF digitado pelo usuário na variável

    FILE *file; //Definindo a variável file como um ponteiro para o arquivo
    file = fopen(cpf, "r"); //abrindo o arquivo com o nome do

    if (file == NULL) //verificando se o arquivo existe
    {
        printf("Arquivo não encontrado\n"); //informando ao usuário que o arquivo não foi encontrado
    }

    while (fgets(conteudo, 100, file) != NULL) //lendo o conteúdo do arquivo
    {
        printf("\n Essas são as informacoẽs do usuario\n"); //informando ao usuário que o conteúdo do arquivo será exibido
        printf("%s", conteudo); //imprimindo o conteúdo do arquivo
        printf("\n\n"); //pulando duas linhas para que o usuário possa ver a mensagem
        
    }
    system("pause"); //pausando o programa para que o usuário possa ver a mensagem  
    
    return 0; //retornando 0 para indicar que a função foi executada com sucesso

}


int deletar () //Definindo a função deletar
{
    char cpf[20]; //Definindo a variável cpf como uma string de 20 caracteres

    printf("Digite ocpf a ser deletado:"); //solicitando ao usuário que digite o CPF a ser deletado
    scanf("%s", cpf); //armazenando o CPF digitado pelo usuário na variável

    remove(cpf); //deletando o arquivo com o nome do CPF digitado pelo usuário

    FILE *file; //Definindo a variável file como um ponteiro para o arquivo
    file = fopen(cpf, "r"); //abrindo o arquivo com o nome do
    if (file == NULL) //verificando se o arquivo existe
    {
        printf("Arquivo deletado com sucesso\n"); //informando ao usuário que o arquivo foi deletado com sucesso
    }
    else
    {
        printf("Erro ao deletar o arquivo\n"); //informando ao usuário que houve um erro ao deletar o arquivo
    }
    system("pause"); //pausando o programa para que o usuário possa ver a mensagem
    return 0; //retornando 0 para indicar que a função foi executada com sucesso
}


int main() 
{
    int opcao=0; //Definindo as variaveis do menu
    int laco=1; //Definindo a variável laco como 1 para que o programa entre no loop

    for (laco=1; laco==1;) //Definindo o loop do menu, enquanto a variável laco for igual a 1, o programa continuará executando
    {

        setlocale(LC_ALL, "Portuguese"); //Sdefinindo a linguagem do programa para português

        printf("     Cartório da EBAC   \n"); // Inicio do menu
        printf("Escolha a opção desejada do menu:\n");
        printf("1. Registrar nome\n");
        printf("2. Consultar nome\n");
        printf("3. Deletar nome\n\n");
        printf("4. Sair\n\n"); // Fim da escolha do menu
        printf("Opçao:");

        scanf("%d", &opcao); //armazenando a opção escolhida pelo usuário

        switch (opcao) //Definindo as opções do menu
        {   
            case 1: //Caso o usuário escolha a opção 1, ele será direcionado para a função de registrar nome
                registro(); //chamando a função registro
                break; //fim do case 1

            case 2: //Caso o usuário escolha a opção 2, ele será direcionado para a função de consultar nome
                consulta(); //chamando a função consulta
                break; //fim do case 2

            case 3: //Caso o usuário escolha a opção 3, ele será direcionado para a função de deletar nome
                deletar(); //chamando a função deletar
                break; //fim do case 3

            case 4: //Caso o usuário escolha a opção 4, ele será direcionado para a função de sair do programa
                printf("Sair\n");
                laco=0; //Definindo o valor da variável laco como 0 para que o programa saia do loop e encerre
                break; //fim do case 4

            default: //Caso o usuário escolha uma opção inválida, ele será informado que a opção é inválida
                printf("Opção inválida\n");
                break; //fim do default
        }





    }

    return 0; //Retornando 0 para indicar que o programa foi executado com sucesso

}