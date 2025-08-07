package sistema;

public class RegistroAluno {
    private Aluno aluno;
    private Boletim boletim;

    public RegistroAluno(Aluno aluno, Boletim boletim) {
        this.aluno = aluno;
        this.boletim = boletim;
    }

    public Aluno getAluno() {
        return aluno;
    }

    public Boletim getBoletim() {
        return boletim;
    }

    @Override
    public String toString() {
        return String.format("Nome: %-30s Sexo: %c Média: %.2f Situação: %s",
                aluno.getNome(),
                aluno.getSexo(),
                boletim.calcularMedia(),
                boletim.esAprovado() ? "Aprovado" : "Reprovado"
        );
    }
}
