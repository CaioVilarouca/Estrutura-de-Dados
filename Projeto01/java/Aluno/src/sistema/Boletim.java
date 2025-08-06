package sistema;

import java.util.Arrays;

public class Boletim {
	  	private Integer qtdProvas = 0;
	    protected Double[] notas;
	    private Double mediaAprovacao;
	    private boolean aprovado;

	    public Boletim() {
	    }
	    
	    

	    public Integer getQtdProvas() {
			return qtdProvas;
		}



		public void setQtdProvas(Integer qtdProvas) {
			this.qtdProvas = qtdProvas;
		}



		public Double[] getNotas() {
			return notas;
		}



		public void setNotas(Double[] notas) {
			this.notas = notas;
		}



		public Double getMediaAprovacao() {
			return mediaAprovacao;
		}



		public void setMediaAprovacao(Double mediaAprovacao) {
			this.mediaAprovacao = mediaAprovacao;
		}



		public boolean isAprovado() {
			return aprovado;
		}



		public void setAprovado(boolean aprovado) {
			this.aprovado = aprovado;
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

		@Override
		public String toString() {
			return "Boletim [qtdProvas=" + qtdProvas + ", notas=" + Arrays.toString(notas) + ", mediaAprovacao="
					+ mediaAprovacao + ", aprovado=" + aprovado + "]";
		}
}
