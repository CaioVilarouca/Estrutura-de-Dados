package sistema;

import java.util.ArrayList;
import java.util.List;

public class Sistema {	
	private List <Boletim> turma = new ArrayList<>();
	
	public void addAlunosNaTurma(Boletim boletim) {
		turma.add(boletim);
	}
	
	public void listaDeAlunos() {
		for (Boletim x : turma) {
			System.out.println(x);
		}
	}
}
