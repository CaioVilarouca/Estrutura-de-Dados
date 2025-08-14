#include <stdio.h>
#include <stdbool.h> 
#include <ctype.h>

#define MAX_PROVAS 10 // Limites max de provas 

int qtdAlunos = 0, qtdProvas; // Var acumulativa 
float MediaAprovacao;

// Definicao da estrutura Aluno, que agrupa os dados de cada aluno
struct Aluno { 
    char Nome[30];  // Esse campo so permite 30 caractere    
    float Notas[MAX_PROVAS];   
    float NotaObtida; // media final do aluno
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
    do {
        // Quantas provas vao ser aplicado para todos os alunos
        printf("\n Informe a quantidade de provas: (Limite max de 10 provas.)");
        scanf("%i", &qtdProvas);

        // Quantidade provas a ser aplicado MAX 10 provas
        // || Se a primeira condicao ja for true, nao avalia a segunda
        if(qtdProvas < 1 || qtdProvas > MAX_PROVAS){
            printf("\n Atencao! Entre 1 e 10 Provas.");
        }

        // || Se a primeira condicao ja for true, nao avalia a segunda
    }while(qtdProvas < 1 || qtdProvas > MAX_PROVAS);// Operador OU e ||

    do {
      // Media de aprovacao
      printf("\n Informe a media de para aprovacao: (Media entre 05 e 08): ");
      scanf("%f", &MediaAprovacao);
    } while ( MediaAprovacao < 5 || MediaAprovacao > 8);

    do {
        // Leia Nome do aluno e guarda o nome na posicao qtdAlunos no vetor Turma
        printf("\n Informe o nome do %i. aluno: ", qtdAlunos + 1);
        scanf(" %29[^\n]", Turma[qtdAlunos].Nome); 

        //  Entrada do sexo com validacao (aceita M ou F)
        do {
            printf("Informe o sexo (M/F): ");
            scanf(" %c", &Turma[qtdAlunos].Sexo);
            Turma[qtdAlunos].Sexo = toupper(Turma[qtdAlunos].Sexo); // forca a letra maiuscula
        } while (Turma[qtdAlunos].Sexo != 'M' && Turma[qtdAlunos].Sexo != 'F');

        // Pecorrendo o vetor na linha 09
        Turma[qtdAlunos].Notas[0] = 0;// Essa intrucao nao eh opcional! por causa da linha 75
        for (int i = 1; i <= qtdProvas; i++){

            // Leia uma nota e guarde na posicao I das notas do aluno de numero qtdAlunos
            printf("    Informe a %i. nota: ", i);
            scanf("%f", &Turma[qtdAlunos].Notas[i]);// Um agregador container

            // Acomulando a soma das notas na posicao 0 do vetor
            Turma[qtdAlunos].Notas[0] += Turma[qtdAlunos].Notas[i]; 
        }

        // Calc a media do aluno
        // Evita HARD CODED com a var MediaAprovacao
        // Resultado recebe o True ou False
        Turma[qtdAlunos].Resultado = Turma[qtdAlunos].Notas[0] / qtdProvas >= MediaAprovacao; // Resultado da media do aluno
        Turma[qtdAlunos].NotaObtida = Turma[qtdAlunos].Notas[0] / qtdProvas; // Calc da nota final do aluno

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

}
// codigo antigo
/*   // Resultado do dados coletados
    printf("\n  Quantidade de Alunos: [%d]  \n", qtdAlunos);

    printf("\n--- Alunos Aprovados ---\n");
    for (int i = 0; i < qtdAlunos; i++) {
        // true ou false
        if (Turma[i].Resultado) {
            printf("Nome: %-10s | Sexo: %c | Situacao: [Aprovado] A media solicitada foi %0.2f e a nota obtida \n", Turma[i].Nome, Turma[i].Sexo, MediaAprovacao);
        }
    }        

    printf("\n--- Alunos Reprovados ---\n");
    for (int i = 0; i < qtdAlunos; i++) {
        // resultado for diferente de true 
        if (!Turma[i].Resultado) {
            printf("Nome: %-10s | Sexo: %c | Situacao: [Reprovado] A media solicitada foi %.2f e a nota obtida \n", Turma[i].Nome, Turma[i].Sexo, MediaAprovacao);
        }
    }

    printf("\n------- ESTATISTICAS POR SEXO -------\n");

    printf("\nMasculino:\n");
    printf("  Total:     %d\n", totalMasc);
    printf("  Aprovados: %d\n", aprovMasc);
    printf("  Reprovados:%d\n", reprovMasc);
    printf("  Porcetagem de alunos Masc %.2f \n", ((float)aprovMasc / totalMasc) * 100);
  


    printf("\nFeminino:\n");
    printf("  Total:     %d\n", totalFem);
    printf("  Aprovadas: %d\n", aprovFem);
    printf("  Reprovadas:%d\n", reprovFem);*/