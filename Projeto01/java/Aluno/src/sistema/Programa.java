package sistema;

import java.util.Locale;
import java.util.Scanner;

public class Programa {
	public static void main(String[] args) {
		new Programa().sistema();
	}
	
	public void sistema() {
		Locale.setDefault(Locale.US);
		Scanner scanner = new Scanner(System.in);
		
		Sistema turma = new Sistema();
		
		char resposta;
		
        // Coleta de notas
		System.out.print("Quantas provas a ser aplicada: ");
        int qtdProvas = scanner.nextInt();
        scanner.nextLine(); // limpa o \n
        
		do {			
			// Objeto boletim esta dentro loop porque cada aluno tem ter seu proprio boletim
			Boletim boletim = new Boletim();
			
			// Coleta de dados de Alunos | Quantas provas a ser aplicadas | Notas
	        System.out.print("Nome do aluno: ");
	        String nome = scanner.nextLine();
	        
	        // Coleta do nome com no máximo 30 caracteres
	        if (nome.length() > 30) { // Retorna o numero de caracteres dentro da string
	            nome = nome.substring(0, 30); // é usado para pegar uma parte (subtexto) 
	            System.out.println("Nome foi cortado para 30 caracteres.");
	        }
			
			System.out.print("Sexo do M | F :");
			char sexo = scanner.next().charAt(0);// Le apenas o primeiro caractere
			
			// Add dados de aluno no objeto Aluno
			Aluno aluno = new Aluno(nome, sexo);
			
			// Tamanho do vetor Notas
            boletim.inicializarNotas(qtdProvas);
			
            // Coleta de notas
            for (int i = 0; i < qtdProvas; i++) {
                System.out.printf("Nota da prova %d: ", i + 1);
                double nota = scanner.nextDouble();
                boletim.addNota(i, nota);
            }
            
            // Add aluno na turma
            turma.addAlunosNaTurma(boletim);

            // Sair loop 
			System.out.print("Deseja cadastrar outro aluno? (S/N): ");
			resposta = scanner.next().charAt(0);
			
			System.out.println("----------------------------------------------------------------------------------------------");
			// Scanner para consumir a quebra de linha
			scanner.nextLine();
		}while(resposta == 'S' || resposta == 's');
		
		turma.listaDeAlunos();
		
		scanner.close();
	}
}
