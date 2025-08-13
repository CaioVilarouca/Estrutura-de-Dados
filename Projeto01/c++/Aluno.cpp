#include <stdio.h>
#include <stdbool.h> 
#include <ctype.h>

#define MAX_PROVAS 10 // Limites max de provas que o sistema 

int qtdAlunos=0, qtdProvas; // Var acumulativa 
float mediaAprovacao;

// Definicao da estrutura Aluno, que agrupa os dados de cada aluno
struct Aluno {
    char Nome[30];  // Esse campo so permite 30 caractere    
    float Notas[MAX_PROVAS];   
    char Sexo;         
    bool Resultado;      
};

int main() {

    Aluno Turma[100]; // Vector de limite max de 100 alunos por turma
    char Resposta;


    // Novas variaveis para estatisticas por sexo
    int totalMasc=0, totalFem=0;
    int aprovMasc=0, aprovFem=0;
    int reprovMasc=0, reprovFem=0;


    // Regra de negocio
    // Quantas provas vao ser aplicado para todos os alunos
    do {
        printf("\n   Informe a quantidade de provas: (Limite max de 10 provas.)");
        scanf("%i", &qtdProvas);

        // Quantidade provas a ser aplicado do MAX 10 provas
        if(qtdProvas < 1 || qtdProvas > MAX_PROVAS){
            printf("\n Atencao! Entre 1 e 10 Provas.");
        }

        // Quantidade tem ser maior ou igual a um ou menor ou igual a dez
    }while(qtdProvas < 1 || qtdProvas > MAX_PROVAS);// Operador OU e ||

    // Regra de negocio
    do {
      // Media de aprovacao
      printf("\n Informe a media de para aprovacao: (Media entre 5 e 8): ");
      scanf("%f", &mediaAprovacao);
    } while ( mediaAprovacao < 5 or mediaAprovacao > 8);

    do {
        
        // Leia Nome do aluno e guarda o nome na posicao qtdAlunos no vetor Turma
        printf("\n   Informe o nome do %i. aluno: ", qtdAlunos + 1);
        scanf("%s", Turma[qtdAlunos].Nome); 


        //  Entrada do sexo com validacao (aceita M ou F)
        do {
            printf("    Informe o sexo (M/F): ");
            scanf(" %c", &Turma[qtdAlunos].Sexo);
            Turma[qtdAlunos].Sexo = toupper(Turma[qtdAlunos].Sexo); // forca letra maiuscula
        } while (Turma[qtdAlunos].Sexo != 'M' && Turma[qtdAlunos].Sexo != 'F');


        // Pecorrendo o vetor na linha 09
        Turma[qtdAlunos].Notas[0] = 0;// Essa intrucao nao eh opcional! por causa da linha 75
        for (int i = 1; i <= qtdProvas; i++){

            // Leia uma nota e guarde na posicao I das notas do aluno de numero qtdAlunos
            printf("    Informe a %i. nota: ", i);
            scanf("%f", &Turma[qtdAlunos].Notas[i]);// Um agregador container

            // A primeira posicao do vetor esta acomulando a soma das notas
            Turma[qtdAlunos].Notas[0] += Turma[qtdAlunos].Notas[i]; 
        }


        // Calc a media do aluno
        // Resultado recebe o True ou False
        Turma[qtdAlunos].Resultado=Turma[qtdAlunos].Notas[0] / qtdProvas >= mediaAprovacao; 
        // Evita HARD CODED

        //  Atualiza as estatisticas de acordo com o sexo e se foi aprovado ou nao
        if (Turma[qtdAlunos].Sexo == 'M') {
            totalMasc++;
            if (Turma[qtdAlunos].Resultado)
                aprovMasc++;
            else
                reprovMasc++;
        } else {
            totalFem++;
            if (Turma[qtdAlunos].Resultado)
                aprovFem++;
            else
                reprovFem++;
        }


        // Pergunta se deseja adicionar mais alunos
        printf("Deseja cadastrar outro aluno? (S/N): ");
        scanf(" %c", &Resposta); // Corrigido: espaço antes do %c ignora enter anterior

        qtdAlunos++;
    } while (Resposta == 'S' || Resposta == 's');
    // Fim do loop 
    
    // Resultado do dados coletados
    printf("\n  Quantidade de Alunos: [%d]  \n", qtdAlunos);

    printf("\n--- Alunos Aprovados ---\n");
    for (int i = 0; i < qtdAlunos; i++) {
        // true ou false
        if (Turma[i].Resultado) {
            printf("Nome: %-10s | Sexo: %c | Situacao: [ Aprovado ] com a media %0.2f \n", Turma[i].Nome, Turma[i].Sexo, mediaAprovacao);
        }
    }

    printf("\n--- Alunos Reprovados ---\n");
    for (int i = 0; i < qtdAlunos; i++) {
        // resultado for diferente de true 
        if (!Turma[i].Resultado) {
            printf("Nome: %-10s | Sexo: %c | Situacao: [ Reprovado ] com a media %0.2f \n", Turma[i].Nome, Turma[i].Sexo, mediaAprovacao);
        }
    }

    printf("\n------- ESTATISTICAS POR SEXO -------\n");

    printf("\nMasculino:\n");
    printf("  Total:     %d\n", totalMasc);
    printf("  Aprovados: %d\n", aprovMasc);
    printf("  Reprovados:%d\n", reprovMasc);

    printf("\nFeminino:\n");
    printf("  Total:     %d\n", totalFem);
    printf("  Aprovadas: %d\n", aprovFem);
    printf("  Reprovadas:%d\n", reprovFem);

}