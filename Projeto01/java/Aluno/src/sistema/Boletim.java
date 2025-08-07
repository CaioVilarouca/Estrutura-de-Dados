package sistema;

import java.util.Arrays;

public class Boletim {
	  	private Integer qtdProvas = 0;
	    protected Double[] notas;
	    private Double mediaAprovacao;

	    public Boletim() {
	    }

		public Double getMediaAprovacao() {
			return mediaAprovacao;
		}



		public void setMediaAprovacao(Double mediaAprovacao) {
			this.mediaAprovacao = mediaAprovacao;
		}



		// Inicializa o vetor de notas com base na quantidade de provas
	    public void inicializarNotas(int qtdProvas) {
	        this.qtdProvas = qtdProvas;
	        this.notas = new Double[qtdProvas];
	    }
	    
	    // Adiciona uma nota em uma posicao i do vetor notas
	    public void addNota(int i, double nota) {
	            notas[i] = nota;
	    }
	    
	   
	    public double calcularMedia() {
	        double soma = 0;
	        for (double nota : notas) {
	            soma += nota;
	        }
	        return soma / notas.length;
	    }

	    public boolean esAprovado() {
	        return calcularMedia() >= mediaAprovacao;
	    }


		@Override
		public String toString() {
			return "Boletim [qtdProvas=" + qtdProvas + ", notas=" + Arrays.toString(notas) + ", mediaAprovacao="
					+ mediaAprovacao;
		}

}
