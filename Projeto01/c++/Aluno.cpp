#include <stdio.h>
#include <stdbool.h> 

//#define MAX_PROVA 10;

int qtdAlunos = 0, qtdProvas; // Var acumulativa 


// Definição da estrutura Aluno, que agrupa os dados de cada aluno
struct Aluno {
    char Nome[30];  // Esse campo so permite 30 caractere    
    float Notas[3];   
   // char Sexo;         
   // bool Resultado;      
};

int main() {

    Aluno Turma[100]; // Vector de limite max de 100 alunos por turma
    char Resposta;


    do {


        // Regra de negocio
        do {
            printf("\n   Infrome a quantidade de provas: ");
            scanf("%i", &qtdProvas);

            // Quantidade provas a ser aplicado do MAX 10 provas
            if( qtdProvas < 1 || qtdProvas > 10){
                printf("\n Atencao! Entre 1 e 10 Provas.");
            }

            // Quantidade tem ser maior ou igual a um ou menor ou igual a dez
        }while(qtdProvas < 1 || qtdProvas > 10);

        
        // Leia Nome do aluno e guarda o nome na posicao qtdAlunos no vetor Turma
        printf("    Informe o nome do %i. aluno: ", qtdAlunos + 1);
        scanf("%s", Turma[qtdAlunos].Nome); 


        // Pecorrendo o vetor na linha 09
        for (int i = 1; i <= 2; i++){

            // Leia uma nota e guarde na posicao I das notas do aluno de numero qtdAlunos
            printf("    Informe a %i. nota: ", i);
            scanf("%f", &Turma[qtdAlunos].Notas[i]);// Um agregador container

            // A primeira posicao do vetor esta acomulando a soma das notas
            Turma[qtdAlunos].Notas[0] += Turma[qtdAlunos].Notas[i]; 
        }
        //Turma[qtdAlunos].Resultado = Turma[qtdAlunos].Notas[0] / 3 >= 6; 

        // Pergunta se deseja adicionar mais alunos
        printf("Deseja cadastrar outro aluno? (S/N): ");
        scanf(" %c", &Resposta); // Corrigido: espaço antes do %c ignora enter anterior

        //qtdAlunos++; // Incrementa a quantidade de alunos cadastrados
    } while (Resposta == 'S' || Resposta == 's');


    printf("\n A soma das notas: %.2f", Turma[qtdAlunos].Notas[0]);
    printf("\n A soma das notas: %.2f", Turma[qtdAlunos].Notas[0] / 3);
}