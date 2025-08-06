package sistema;

public class Aluno {
	private String nome;
	private char sexo;
	
	public Aluno() {
		
	}

	public Aluno(String nome, char sexo) {
		super();
		this.nome = nome;
		this.sexo = sexo;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public char getSexo() {
		return sexo;
	}

	public void setSexo(char sexo) {
		this.sexo = sexo;
	}

	@Override
	public String toString() {
		return "Aluno [nome=" + nome + ", sexo=" + sexo + "]";
	}
}
