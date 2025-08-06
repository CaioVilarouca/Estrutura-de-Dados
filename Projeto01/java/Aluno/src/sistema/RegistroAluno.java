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
}
