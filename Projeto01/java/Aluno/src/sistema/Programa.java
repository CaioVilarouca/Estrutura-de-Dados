package sistema;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Programa {
	public static void main(String[] args) {
		new Programa().sistema();
	}
	
	public void sistema() {
		Locale.setDefault(Locale.US);
		Scanner scanner = new Scanner(System.in);
		
		// lista da turma
		List<RegistroAluno> turma = new ArrayList<>();
				
		char resposta;
		
        // Coleta de notas
		System.out.print("Quantas provas a ser aplicada: ");
        int qtdProvas = scanner.nextInt();
		System.out.print("Qual a media de aprovação: ");
        double media = scanner.nextDouble();
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
            
            // Media de aprovacao
            boletim.setMediaAprovacao(media);
			
            // Coleta de notas
            for (int i = 0; i < qtdProvas; i++) {
                System.out.printf("Nota da prova %d: ", i + 1);
                double nota = scanner.nextDouble();
                boletim.addNota(i, nota);
            }
            
            // Add aluno na turma
            RegistroAluno registro = new RegistroAluno(aluno, boletim);
            turma.add(registro);


            // Sair loop 
			System.out.print("Deseja cadastrar outro aluno? (S/N): ");
			resposta = scanner.next().charAt(0);
			
			System.out.println("----------------------------------------------------------------------------------------------");
			//limpa o \n
			scanner.nextLine();
			
			
		}while(resposta == 'S' || resposta == 's');
		
		// Ordenar por média
        turma.sort((a, b) -> Double.compare(b.getBoletim().calcularMedia(), a.getBoletim().calcularMedia()));

        // Exibir relatório
        System.out.println("\n--- RELATÓRIO FINAL (Ordenado por Média) ---");
        for (RegistroAluno reg : turma) {
            System.out.println(reg);
        }

        // Estatísticas por sexo
        int aprovadosM = 0, reprovadosM = 0;
        int aprovadosF = 0, reprovadosF = 0;

        for (RegistroAluno reg : turma) {
            char sexo = Character.toUpperCase(reg.getAluno().getSexo());
            boolean aprovado = reg.getBoletim().esAprovado();

            if (sexo == 'M') {
                if (aprovado) aprovadosM++;
                else reprovadosM++;
            } else if (sexo == 'F') {
                if (aprovado) aprovadosF++;
                else reprovadosF++;
            }
        }

        System.out.println("\n--- ESTATÍSTICAS POR SEXO ---");
        System.out.printf("Masculino - Aprovados: %d | Reprovados: %d\n", aprovadosM, reprovadosM);
        System.out.printf("Feminino  - Aprovados: %d | Reprovados: %d\n", aprovadosF, reprovadosF);

		
		scanner.close();
	}
}
