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
		
		// Coleta de dados de Alunos | Quantas provas a ser aplicadas | Notas
        System.out.print("Nome do aluno:");
        String nome = scanner.nextLine();
        // Coleta do nome com no máximo 30 caracteres
        if (nome.length() > 30) { // Retorna o numero de caracteres dentro da string
            nome = nome.substring(0, 30); // é usado para pegar uma parte (subtexto) 
            System.out.println("Nome foi cortado para 30 caracteres.");
        }
		
		System.out.print("Sexo do M | F :");
		char sexo = scanner.next().charAt(0);// Le apenas o primeiro caractere
		
		System.out.print("Quantas provas a ser aplicada: ");
		int qtedProvas = scanner.nextInt();
		
		Aluno aluno = new Aluno(nome, sexo);
		System.out.println(aluno);
		
		scanner.close();
	}
}
