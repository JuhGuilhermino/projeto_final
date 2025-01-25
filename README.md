# Gerenciador de Arquivos

Esse projeto, desenvolvido por [Júlia Guilhermino](https://github.com/JuhGuilhermino), consiste em um gerenciador pessoal de leituras implementado em C++ utilizando a [[#Arquitetura Game Loop]]. Ele foi utilizado como trabalho final da disciplina de *Boas Práticas de Programação* do *Bacharelado em Ciência da Computação da UFRN.* 
#### Índice
- [[#Sobre]]
- [[#Implementação]]
	- [[#Base de Dados]]
	- [[#Classes]]
- [[#Boas Práticas Implementadas]]
	-  [[#Arquitetura Game Loop]]
	- [[#Clean Code]]
	- [[#Testes]]
- [[#Instalação]]
---
## Sobre
---
O objetivo desse projeto é desenvolver um sistema de gerenciamento de leituras para um acervo específico como: biblioteca, editora ou um banco de dados de livros, etc. Dessa forma os usuários desse acervo podem ter acesso prévio a lista de obras disponíveis, buscar novas obras, registrar e avaliar suas próprias leituras.
Essa versão foi feita para ser executada no terminal e utiliza uma [[#Base de Dados]] simples. Baseado nessa estrutura foram definidas as seguintes funcionalidades:
- **Cadastro de Usuário:** solicita alguns dados e cria uma biblioteca pessoal, uma base de dados que permite que usuário salve livros de interesse.
- **Pesquisar Livros:** buscar livros salvos no acervo.
- **Salvar Livros:**  armazenar um livro na biblioteca pessoal e classifica-los como "lido", "lendo", "quero ler", "abandonado" .
- **Visualizar livros salvos:** quais e quantos livros forma salvos em cada categoria na biblioteca pessoal.
- **Registrar Progresso de Leitura:** marcar em qual página dos livros salvos como "lendo"  o usuário está.
- **Contador de Páginas:** indica quantas páginas o usuário leu.
- **Avaliar Leituras:** dar uma nota de 0 (muito ruim) à 5 (muito bom) a livros salvos na biblioteca pessoal.
- **Exibir Perfil do Usuário:** permite que um usuário visualiza seus dados pessoais, leituras em andamento e suas estatísticas de leitura.
Essas funcionalidades e indicadores podem ser facilmente adaptadas e aprimoradas para um tipo de acervo específico ou uso de um banco de dados e outras tecnologias e plataformas.

---
## Implementação
___
A implementação do projeto foi feita na linguagem C++ utilizado o paradigma de orientação a objetos a partir de uma base dados.
### Classes
O projeto possui X classes:
- **Simulation:**  principal classe do projeto.  Ela controla todo o fluxo do sistema utilizando a [[#Arquitetura Game Loop]]. 
- **Book:** representa um livro do acervo com os atributos referente ao projeto da base de dados. Seus métodos permitem o acesso aos atributos do livro e realizam atualizações dos dados.
- **User:** armazena dados de cadastro do usuário e um vetor com os livros salvos na sua biblioteca particular. Seus métodos permitem acesso aos dados do usuário para validação de login, estatísticas de leitura, busca por livros e etc. 
- **Database:** possui dois vetores com os livros e usuários cadastrados no sistema. É através dela que a classe *Simulation* acessa os dados. Também é responsável pela validação do login e cadastro de usuários.
### Base de Dados
Para simular um banco de dados foram utilizados arquivos `.txt` .  Essa escolha foi feita em função do tempo e da proposta do trabalho que era desenvolver um sistema funcional para trabalhar aspectos de boas práticas de programação. Todos os dados referentes a cadastro de usuários são fictícios, utilizados apenas para simular o sistema de gerenciamento como um todo.
O principal arquivo é o `books.txt`. Ele é responsável por armazenar os dados dos livros do acervo utilizando o seguinte formato:
```
	Nº de Identificação (ID)
	Título
	Autor(a)
	Editora
	Ano da versão
	Número de Páginas
	Nota dos Leitores
	Quantos Usuários Marcaram Como "lido"
	Quantos Usuários Marcaram Como "lendo"
	Quantos Usuários Marcaram Como "quero ler"
	Quantos Usuários Marcaram Como "abandonado"

	Nº de Indetificação (ID)
	...
```
Cada livro é representado como um `struct` e identificado com um ID de números inteiros.
Os dados dados pessoais do usuário informados na hora do cadastro, bem como suas estatísticas de leitura são armazenados no arquivo `users.txt`. A estrutura do arquivo segue o seguinte formato:
```
	Nº de Identificação (ID)
	Nome de Usuário
	Senha
	Nome Completo
	Quantidade de livros "lido"
	Quantidade de livros "lendo"
	Quantidade de livros "quero ler"
	Quantidade de livros "abandonado"

	Nº de Identificação (ID)
```
Cada usuário também possui um arquivo contendo os dados da sua biblioteca pessoal. O nome do arquivo é o nome de usuário definido na hora do cadastro, exemplo: `fulana23.txt`. A estrutura dos dados é no seguinte formato:
```
	Nº de Identificação do Livro (ID)
	Status na Biblioteca
	Progresso de Leitura em Nº de Páginas
```
O "status" do livro na biblioteca é representado na base de dados por um inteiro com a seguinte identificação:
	0 - quero ler;
	1 - lendo;
	2 - lido;
	3 - abandonado.
___
## Status da Implementação
Check-list das etapas de implementação do projeto:
- [x] Planejamento do escopo do projeto, definição dos estados e elaboração do diagrama de estados.
- [ ] Base de dados.
	- [x] Fase 1: instanciação dos objetos das classes `Book` e `User` de forma manual diretamente nos métodos `void read_books()` e `void read_users()`. Usada apenas na fase inicial do desenvolvimento.
	- [ ] Fase 2: implementação da [[#Base de Dados]].
		*OBS: talvez seja necessária a criação de uma nova classe para escrita e leitura de arquivos a fim de manter os padrões do Clean Code.*
- [x] Estrutura da arquitetura game loop e fluxo dos estados.
	- [x] Processamento dos dados cadastrados.
	- [x] Validação do login.
	- [x] Realização de cadastro do novo usuário.
	- [x] Exibir dados do perfil.
		- [ ] atualização das estáticas do livro após salvamento esta estranha.
	- [x] Manipular opções do menu do perfil
		- [x] Pesquisar livro
			- [ ] Erro na fase 1 da base de dados a um erro ao salvar os títulos dos livros impede que alguns títulos sejam identificados
		- [x] Visualização dos livros buscados.
		- [x] Salvar livros na biblioteca pessoal.
			- [ ] O livro aparece como se verificado dentro da do método `void add_book(int id, int status, int num_pages, int read_pages)`, mas não é identificada quando manipulado na classe `Database`.
		- [ ] Registrar progresso de leitura.
		- [ ] Buscar livro dentro da biblioteca pessoal.
- [x] Implementação das classes.

___
## Boas Práticas Implementadas
___
Os três assuntos de boas práticas escolhidos para implementar foram: padrões de projeto (com a arquitetura game loop), testes e clean code.
### Arquitetura Game Loop
Esse padrão de projeto enxerga um programa como um ciclo de repetição de três métodos: 
- `void process_events()` : realiza a leitura de dados fornecidos pelo usuário;
- `void update()`: atualiza o sistema com base nas entradas do usuário;
- `void render()` : renderiza a interface após as atualizações.
Além deles ela possui dois métodos que auxiliam no gerenciamento do loop:
- `void initialize()` : chama os métodos da classe `Database` para realizar da base de dados.
- `bool is_over()`: controla a execução do loop.
Para controlar o fluxo de ações foram definidos os seguintes estados:
- **STARTING:** carrega todas as variáveis e dados necessários para o funcionamento do sistema;
- **WELCOME:** pergunta se o usuário deseja fazer o *login* ou realizar o *cadastro no sistema*;
- **LOGIN:** verifica informações de login e carrega dados do usuário.
- **SUBSCRIBING:** realiza cadastro no sistema garantindo que não hajam usuários diferentes como o mesmo acesso.
- **PROFILE:** exibe dados e estatísticas do usuário e exibe as opções do menu.
- **LIBRARY:** exibe lista de livros os usuário de acordo com o status informado.
- **SEARCHING:** busca por um novo livro no acervo.
- **VIEW_BOOK:** exibe os dados de um livro buscado.
- **SAVING:** usuário adiciona a um livro buscado na sua biblioteca pessoal.
- **READING_PROGRESS:** registra o progresso de leitura.
- **QUITTING:** salva todas as atualizações e encerra o programa.
### Clean Code
Aspectos do clean code implementados:
- Classes com papel bem definido.
- Os nomes das classes são bem claros e fazem referências diretas aos seus papeis no sistema.
- A nomeclatura das classes, atributos métodos e variáveis seguem o mesmo padrão com palavras compostas separadas por `_`.
- Foram definidas referencias `enum` para facilitar a identificação dos estados e consultas do usuário que determinam o fluxo de execução.	
	EX:	````
	``` cpp
	//=== Estados que represetam a simulação do sistema.
	enum e_states{
		STARTING = 0,  //< Carrega dados
		WELCOME,       //< Opções de incializaçaõ
		LOGIN,         //< Realiza login
		SUBSCRIBING,   //< Realiza cadastro
		PROFILE,       //< Exibe perfil do usuário e menu
		LIBRARY,       //< Busca livros na biblioteca pessoal
		READING_PROGRESS,  //< Atualiza histórioco de leitura
		SEARCHING,     //< Busca livros no acervo
		VIEW_BOOK,     //< Viazualiza dados de um livro
		SAVING,        //< Salva livro na biblioteca pessoal
		QUITTING       //< Slava de dados e encerra o sistema
	};
	//=== Uso dos estados
	void Simulation::process_events(){
	    if(state == e_states::STARTING){
	        // Não faz nada
	    } else if(state == e_states::WELCOME){
	        std::cin >> option;
	    } else if (state == e_states::LOGIN){
	        std::cout << "Nome de Usuário:   ";
	        std::cin >> username;
	        std::cout << "Senha:   ";
	        std::cin >> password;
	    } else if (state == e_states::SUBSCRIBING){
	        std::cout << "Nome Completo >>>   ";
	        std::cin >> name;
	        std::cout << "Nome de Usuário >>>   ";
	        std::cin >> username;
	        std::cout << "Senha >>>   ";
	        std::cin >> password;
	    } else if (state == e_states::PROFILE){
	        std::cin >> menu_option;
	    } else if (state == e_states::SEARCHING){
	        std::cin >> title;
	    } else if (state == e_states::VIEW_BOOK){
	        std::cin >> save;
	    } else if (state == e_states::SAVING){
	        std::cin >> reading_status;
	    } else if (state == e_states::READING_PROGRESS){
	
	    } else if (state == e_states::LIBRARY){
	
	    } else if (state == e_states::QUITTING){
	        std::cin >> quitting_option;
	    }
	}
	```
### Programação Defensiva
Todas as entradas do programam recebem um tratamento para evitar erros e interrupções no fluxo. Caso algum erro seja identificado ele é esclarecido e o usuário recebe orientações de como proceder.
EX:
``` cpp
//Verificação das informações de login
if (data.search_user(username) < 0){
	std::cout << "\n ERRO: usuário não cadastrado.\n";
	// Atualiza estado
	state = e_states::WELCOME;
} else {
	user = data.search_user(username);
	if (data.valid_password(user, password)){
		// Usuário validado, atualiza estado
		state = e_states::PROFILE;
	} else {
		std::cout << "\n ERRO: senha incorreta.\n";
	}        
}
```
___
## Instalação
___
Instruções para executar e rodar o código:
1. Criar uma pasta `build` e dentro dela:
	1. Executar o comando `cmake ..`. e em seguida `make` para gerar o executável.
	2. Executar o programa com o comando `./main`

