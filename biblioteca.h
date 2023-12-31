//Definindo a struct de tarefas
typedef struct {
    int prioridade;
    char categoria[20];
    char descricao[300];
    char estado[10];
} Tarefa; // Nomeando este tipo de struct como: Tarefa

//Definindo a struct que conterá as structs Tarefa
typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas; // Nomeando este tipo de struct como: ListaDeTarefas

int altera_categoria(int* verifica, ListaDeTarefas* lt, int indice);

int altera_andamento(int* verifica, ListaDeTarefas* lt, int indice);

//Função para cadastrar tarefas, que recebe um ponteiro de ListaDeTarefas como parâmetro e retorna um inteiro
int cadastrarTarefa(ListaDeTarefas *lt);

//Função para deletar tarefas, que recebe um ponteiro de ListaDeTarefas como parâmetro e retorna um inteiro
int deletarTarefa(ListaDeTarefas *lt);

//Função para alterar tarefas, que recebe um ponteiro de ListaDeTarefas como parâmetro e retorna um inteiro
int alterarTarefa(ListaDeTarefas *lt);

void zerarListaDeTarefas(ListaDeTarefas *lt);

//Função para deletar tarefas, que recebe uma struct ListaDeTarefas como parâmetro e retorna um inteiro
int listarTarefas(ListaDeTarefas lt);

//Função para imprimir o menu, sem parâmetros e sem retorno
void printMenu();

//Função para salvar tarefas em um arquivo binário, que recebe um ponteiro de ListaDeTarefas como parâmetro e retorna um inteiro
int salvarTarefas(ListaDeTarefas *lt);

//Função para salvar tarefas lidas de um arquivo binário, que recebe um ponteiro de ListaDeTarefas como parâmetro e retorna um inteiro
int carregarTarefas(ListaDeTarefas *lt);

int filtro_prioridade(ListaDeTarefas *lt);

int filtro_andamento(ListaDeTarefas *lt);

int verif_filtro(int escolha);