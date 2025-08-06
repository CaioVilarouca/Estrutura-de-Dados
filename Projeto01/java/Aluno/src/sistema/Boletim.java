package sistema;

public class Boletim {
	  private Integer qtdProvas = 0;
	    private Double[] notas;
	    private Double mediaAprovacao;
	    private boolean aprovado;

	    public Boletim() {
	    }

	    // Inicializa o vetor de notas com base na quantidade de provas
	    public void inicializarNotas(int qtdProvas) {
	        this.qtdProvas = qtdProvas;
	        this.notas = new Double[qtdProvas];
	    }
	    
	    // Adiciona uma nota em uma posicao i do vetor notas
	    public void addNota(Double nota, int i) {
	            notas[i] = nota;
	    }
}
