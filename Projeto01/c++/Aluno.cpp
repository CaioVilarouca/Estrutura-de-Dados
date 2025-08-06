#include <stdio.h>
#include <stdbool.h> 

int qtdAlunos = 0; // Var acumulativa 

// Definição da estrutura Aluno, que agrupa os dados de cada aluno
struct Aluno {
    char Nome[30];     
    float Notas[3];   
    char Sexo;         
    bool Aprovado;      
};

int main() {
    Aluno Turma[100]; // Vector de limite max de 100 alunos por turma
    char Resposta;

    do {
        printf("    Informe o nome do %i. aluno: ", qtdAlunos + 1);
        // Leia Nome do aluno e guarda o nome na posicao qtdAlunos no vetor Turma
        scanf("%s", Turma[qtdAlunos].Nome); 

        // instanciando o Vetor NOTA na linha 09
        for (int i = 1; i <= 3; i++){
            printf("    Informe a %i. nota: ", i);
            // Gravando o notas na posicao i do vetor nota q esta sendo gravado na posicao qtdAlunos no vetor Turma
            scanf("%f", &Turma[qtdAlunos].Notas[i]);
            // Acumulando a nota do aluno
            Turma[qtdAlunos].Notas[0] += Turma[qtdAlunos].Notas[0];
        }

        //Turma[qtdAlunos].Aprovado = Turma[qtdAlunos].Notas[0] / 3 >= 6; 
          // Pergunta se deseja adicionar mais alunos
        printf("Deseja cadastrar outro aluno? (S/N): ");
        scanf(" %c", &Resposta); // Corrigido: espaço antes do %c ignora enter anterior

        qtdAlunos++; // Incrementa a quantidade de alunos cadastrados
    } while (Resposta == 'S' || Resposta == 's');
    
}