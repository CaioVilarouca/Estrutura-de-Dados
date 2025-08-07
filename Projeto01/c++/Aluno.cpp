#include <stdio.h>
#include <stdbool.h> 

#define MAX_PROVAS 10 // Limites max de provas que oo sistema 

int qtdAlunos = 0, qtdProvas; // Var acumulativa 
float mediaAprovacao;

// Definição da estrutura Aluno, que agrupa os dados de cada aluno
struct Aluno {
    char Nome[30];  // Esse campo so permite 30 caractere    
    float Notas[MAX_PROVAS];   
   // char Sexo;         
    bool Resultado;      
};

int main() {

    Aluno Turma[100]; // Vector de limite max de 100 alunos por turma
    char Resposta;

    // Regra de negocio
    // Quantas provas vao ser aplicado para todos os alunos
    do {
        printf("\n   Infrome a quantidade de provas: ");
        scanf("%i", &qtdProvas);

        // Quantidade provas a ser aplicado do MAX 10 provas
        if(qtdProvas < 1 || qtdProvas > MAX_PROVAS){
            printf("\n Atencao! Entre 1 e 10 Provas.");
        }

        // Quantidade tem ser maior ou igual a um ou menor ou igual a dez
    }while(qtdProvas < 1 || qtdProvas > MAX_PROVAS);// Operador OU e ||


    // Media de aprovacao
    printf("\n Informe a media de para aprovacao: ");
    scanf("%f", &mediaAprovacao);

    do {
        
        // Leia Nome do aluno e guarda o nome na posicao qtdAlunos no vetor Turma
        printf("\n   Informe o nome do %i. aluno: ", qtdAlunos + 1);
        scanf("%s", Turma[qtdAlunos].Nome); 


        // Pecorrendo o vetor na linha 09
        for (int i = 1; i <= qtdProvas; i++){

            // Leia uma nota e guarde na posicao I das notas do aluno de numero qtdAlunos
            printf("    Informe a %i. nota: ", i);
            scanf("%f", &Turma[qtdAlunos].Notas[i]);// Um agregador container

            // A primeira posicao do vetor esta acomulando a soma das notas
            Turma[qtdAlunos].Notas[0] += Turma[qtdAlunos].Notas[i]; 
        }
        //Turma[qtdAlunos].Resultado = Turma[qtdAlunos].Notas[0] / qtdProvas >= mediaAprovacao; 

        // Pergunta se deseja adicionar mais alunos
        printf("Deseja cadastrar outro aluno? (S/N): ");
        scanf(" %c", &Resposta); // Corrigido: espaço antes do %c ignora enter anterior

        qtdAlunos++;
    } while (Resposta == 'S' || Resposta == 's');

    printf("\n  Quantidade de Alunos: [%d]  \n", qtdAlunos);
}