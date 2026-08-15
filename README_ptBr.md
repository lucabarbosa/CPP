# C++ Modules — 42 São Paulo

Repositório com todas as resoluções dos módulos de C++ (CPP-00 a CPP-09) do
currículo da [42 São Paulo](https://42sp.org.br/). O objetivo aqui é consolidar,
na prática, a transição de C para C++: orientação a objetos, RAII,
sobrecarga de operadores, herança, polimorfismo, tratamento de exceções,
templates e os principais containers/algoritmos da STL.

Este README serve como **sumário e guia de estudo**: para cada módulo há uma
explicação curta dos conceitos trabalhados e a lista dos exercícios
correspondentes. Também há um **[guia interativo em HTML](cpp-guide.html)** (em Português BR)
com exemplos práticos de uso das principais funções/classes de cada módulo,
pensado para consulta rápida.

> 📘 Quer estudar com exemplos comentados? Abra o [`cpp-guide.html`](cpp-guide.html)
> no navegador — ele traz explicações didáticas, trechos de código e links
> para referências externas (cppreference, etc).

---

## Sumário

- [Requisitos](#requisitos)
- [Como compilar e testar](#como-compilar-e-testar)
- [Estrutura do repositório](#estrutura-do-repositório)
- [Módulos](#módulos)
  - [CPP-00 — Namespaces, Classes, Membros Estáticos, Arquivos](#cpp-00--namespaces-classes-membros-estáticos-arquivos)
  - [CPP-01 — Memória, Ponteiros e Referências](#cpp-01--memória-ponteiros-e-referências)
  - [CPP-02 — Sobrecarga de Operadores (Ad-hoc Polymorphism)](#cpp-02--sobrecarga-de-operadores-ad-hoc-polymorphism)
  - [CPP-03 — Herança](#cpp-03--herança)
  - [CPP-04 — Polimorfismo, Classes Abstratas e Interfaces](#cpp-04--polimorfismo-classes-abstratas-e-interfaces)
  - [CPP-05 — Tratamento de Exceções](#cpp-05--tratamento-de-exceções)
  - [CPP-06 — Casting (Conversões de Tipo)](#cpp-06--casting-conversões-de-tipo)
  - [CPP-07 — Templates](#cpp-07--templates)
  - [CPP-08 — Containers e Algoritmos da STL](#cpp-08--containers-e-algoritmos-da-stl)
  - [CPP-09 — STL Avançada / Projeto Final](#cpp-09--stl-avançada--projeto-final)
- [Convenções usadas nos códigos](#convenções-usadas-nos-códigos)
- [Autor](#autor)

---

## Requisitos

Para compilar e rodar os exercícios você precisa apenas de um ambiente Unix
(Linux ou macOS) com as seguintes ferramentas:

| Ferramenta | Versão mínima recomendada | Uso |
|---|---|---|
| **g++** ou **clang++** | com suporte a `-std=c++98` | Compilador C++ |
| **make** | qualquer versão recente (GNU Make) | Automação de build |
| **valgrind** *(opcional)* | qualquer versão recente | Checagem de memory leaks |

Todo o código é escrito seguindo o padrão **C++98**, exigido pela 42, e
compilado com as flags:

```
-Wall -Wextra -Werror -std=c++98
```

Instalação rápida no Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential valgrind
```

No macOS (com Homebrew), o Xcode Command Line Tools já traz `clang++` e
`make`:

```bash
xcode-select --install
brew install valgrind # opcional, suporte limitado no macOS
```

---

## Como compilar e testar

Cada exercício (`exXX/`) é **independente** e possui seu próprio `Makefile`
com os alvos padrão:

| Alvo | O que faz |
|---|---|
| `make` / `make all` | Compila os `.cpp` do diretório e gera o executável |
| `make clean` | Remove os arquivos objeto (`.o`) |
| `make fclean` | Remove objetos **e** o executável final |
| `make re` | Equivale a `fclean` + `all` (rebuild completo) |
| `make valgrind` *(quando disponível)* | Roda o binário sob `valgrind` para checar leaks |
| `make test` *(quando disponível)* | Roda o binário com um cenário de teste pronto |

### Compilar um único exercício

```bash
cd CPP-03/ex01
make
./scavtrap
```

### Compilar todos os exercícios do repositório de uma vez

Não há um Makefile "raiz", pois cada módulo/exercício da 42 é avaliado de
forma isolada — mas é fácil gerar todos os executáveis com um único
comando a partir da raiz do repositório:

```bash
find . -name Makefile -execdir make \;
```

Para limpar tudo (objetos e binários) de uma vez:

```bash
find . -name Makefile -execdir make fclean \;
```

### Testando manualmente

A maioria dos exercícios espera argumentos via linha de comando ou
interage via `stdin`. Consulte o `main.cpp` de cada exercício para ver o
uso esperado, por exemplo:

```bash
cd CPP-09/ex01
make
echo "3 4 +" | ./RPN "3 4 +"
```

---

## Estrutura do repositório

```
CPP/
├── CPP-00/            # Introdução a C++, classes, membros estáticos
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── CPP-01/            # Memória, ponteiros, referências
│   ├── ex00 .. ex06/
├── CPP-02/            # Sobrecarga de operadores (classe Fixed)
│   ├── ex00 .. ex02/
├── CPP-03/            # Herança (ClapTrap, ScavTrap, FragTrap)
│   ├── ex00 .. ex02/
├── CPP-04/            # Polimorfismo e classes abstratas (Animal)
│   ├── ex00 .. ex02/
├── CPP-05/            # Exceções (Bureaucrat, Form)
│   ├── ex00 .. ex03/
├── CPP-06/            # Casting (ScalarConverter, Serializer, dynamic_cast)
│   ├── ex00 .. ex02/
├── CPP-07/            # Templates
│   ├── ex00 .. ex02/
├── CPP-08/            # Containers e algoritmos STL
│   ├── ex00 .. ex02/
└── CPP-09/            # STL avançada / algoritmos complexos
    ├── ex00 .. ex02/
```

Cada `exXX/` contém, no mínimo: os arquivos-fonte (`.cpp`/`.hpp`), um
`main.cpp` de demonstração e um `Makefile`.

---

## Módulos

### CPP-00 — Namespaces, Classes, Membros Estáticos, Arquivos

Primeiro contato com C++: sintaxe de classes, `std::string`, streams
(`iostream`/`fstream`), e a diferença entre a forma "C-like" e a forma
orientada a objetos de organizar um programa.

**Conceitos:** namespaces, classes e membros privados/públicos, `std::string`,
`std::cin`/`std::cout`, membros e métodos `static` (dados compartilhados por
todas as instâncias), arrays de objetos de tamanho fixo, e boas práticas de
alocação (evitar `new`/`delete` desnecessários).

| Exercício | Descrição |
|---|---|
| `ex00` | Megaphone — leitura de `argv`, transformação de strings para maiúsculas |
| `ex01` | PhoneBook — classe `Contact` + classe `PhoneBook` com buffer estático de 8 contatos |
| `ex02` | Account — membros e métodos `static`, log de eventos entre múltiplas instâncias |

### CPP-01 — Memória, Ponteiros e Referências

Foco na gestão manual de memória (stack vs heap) e nas diferenças práticas
entre ponteiros e referências — a base para entender RAII nos módulos
seguintes.

**Conceitos:** alocação em heap (`new`/`delete`) vs stack, ponteiros vs
referências, ponteiros para membros de classe/função, `switch`, manipulação
de arquivos (`std::ifstream`/`std::ofstream`), arrays dinâmicos de objetos
e o uso de `std::string::find`/`replace`.

| Exercício | Descrição |
|---|---|
| `ex00` | Zombie — objeto na stack vs objeto no heap (`newZombie` / `randomChump`) |
| `ex01` | Zombie Horde — array dinâmico de objetos (`zombieHorde`) |
| `ex02` | Referências vs ponteiros de uma mesma variável |
| `ex03` | Weapon/HumanA/HumanB — atributos por referência vs por ponteiro |
| `ex04` | `sed`-like — leitura/escrita de arquivos e substituição de substring |
| `ex05` | Harl — ponteiros para métodos de uma classe (function pointers de membro) |
| `ex06` | Harl Filter — o mesmo, mas com fallthrough de níveis de log (`switch`) |

### CPP-02 — Sobrecarga de Operadores (Ad-hoc Polymorphism)

Implementação de um tipo numérico de ponto fixo (`Fixed`) para praticar a
**Orthodox Canonical Form** (construtor padrão, construtor de cópia,
`operator=`, destrutor) e sobrecarga de operadores aritméticos, de
comparação e de incremento/decremento.

**Conceitos:** Orthodox Canonical Form, sobrecarga de operadores
(`+ - * / == != < > <= >= ++ -- << >>`), representação de ponto fixo com
bitshifting, conversão `int`/`float` ↔ ponto fixo, membros estáticos
(`min`/`max`).

| Exercício | Descrição |
|---|---|
| `ex00` | Fixed — Orthodox Canonical Form básica com armazenamento em ponto fixo |
| `ex01` | Fixed — construtores a partir de `int`/`float`, conversores `toInt`/`toFloat` |
| `ex02` | Fixed — sobrecarga completa de operadores + `min`/`max` estáticos |

### CPP-03 — Herança

Uma hierarquia clássica de "monstros" (`ClapTrap → ScavTrap/FragTrap`) para
entender como construtores/destrutores encadeiam entre classe base e
derivada, e como sobrescrever comportamento mantendo reuso de código.

**Conceitos:** herança simples e múltipla, ordem de chamada de
construtores/destrutores, `protected` vs `private`, sobrescrita de métodos,
reuso via `Base::metodo()`.

| Exercício | Descrição |
|---|---|
| `ex00` | ClapTrap — classe base com pontos de vida, energia e dano de ataque |
| `ex01` | ScavTrap — herda de ClapTrap, adiciona `guardGate` |
| `ex02` | FragTrap — segunda classe derivada, adiciona `highFivesGuys` |

### CPP-04 — Polimorfismo, Classes Abstratas e Interfaces

Hierarquia `Animal → Dog/Cat` explorando polimorfismo em tempo de execução,
o motivo de usar destrutor `virtual`, classes abstratas e interfaces puras.

**Conceitos:** funções `virtual` e binding dinâmico, destrutor virtual
(evitar memory leaks ao deletar via ponteiro base), classes abstratas
(`= 0`), composição (has-a) com `Brain`, interfaces (classes 100%
abstratas).

| Exercício | Descrição |
|---|---|
| `ex00` | Animal/Dog/Cat — polimorfismo básico e o problema do "WrongAnimal" (sem `virtual`) |
| `ex01` | Adiciona `Brain` — composição, deep copy no construtor de cópia |
| `ex02` | Torna `Animal` uma classe abstrata (não instanciável) |

### CPP-05 — Tratamento de Exceções

Simulação de um fluxo burocrático (`Bureaucrat` assina `Form`s) usada como
pretexto para praticar exceções personalizadas e o padrão de projeto
"Chain of Responsibility" (Intern cria o `Form` certo dinamicamente).

**Conceitos:** `try`/`catch`/`throw`, classes de exceção customizadas
(herdando de `std::exception`), `what()`, RAII aplicado a validação de
estado, hierarquia de classes abstratas (`AForm`) com ações concretas
(`ShrubberyCreationForm`, `RobotomyRequestForm`,
`PresidentialPardonForm`).

| Exercício | Descrição |
|---|---|
| `ex00` | Bureaucrat — exceções de grade muito alta/baixa |
| `ex01` | Form — assinatura de formulário com validação de permissão |
| `ex02` | AForm + 3 formulários concretos — execução de ações polimórficas |
| `ex03` | Intern — fábrica que cria o `Form` certo a partir de uma `string` |

### CPP-06 — Casting (Conversões de Tipo)

Foco exclusivo nos operadores de conversão de tipo do C++ e em como
identificar o tipo real de um objeto em tempo de execução.

**Conceitos:** `static_cast`, `dynamic_cast`, `reinterpret_cast`,
`const_cast`, detecção de tipo em runtime via RTTI, serialização de
ponteiros (`uintptr_t`), tratamento de valores especiais de ponto
flutuante (`nan`, `inf`).

| Exercício | Descrição |
|---|---|
| `ex00` | ScalarConverter — converte entre `char`/`int`/`float`/`double` com `static_cast` |
| `ex01` | Serializer — converte um ponteiro em inteiro e vice-versa com `reinterpret_cast` |
| `ex02` | Identify (A/B/C) — identifica o tipo real de um objeto com `dynamic_cast` |

### CPP-07 — Templates

Introdução a *generic programming*: escrever funções e classes que
funcionam para qualquer tipo, sem duplicar código.

**Conceitos:** function templates, class templates, templates com múltiplos
parâmetros de tipo, `typename`, instanciação implícita, arrays genéricos
com verificação de limites via exceção.

| Exercício | Descrição |
|---|---|
| `ex00` | Funções template `whatever(a, b)` — `max`/`swap` genéricos |
| `ex01` | `iter()` — aplica uma função a cada elemento de um array genérico |
| `ex02` | `Array<T>` — classe template com acesso seguro (`operator[]` com bounds check) |

### CPP-08 — Containers e Algoritmos da STL

Primeiro contato "sério" com a STL: containers de sequência/associativos e
os algoritmos padrão que operam sobre iteradores.

**Conceitos:** iteradores (`begin`/`end`), algoritmos genéricos
(`std::find`), containers (`std::vector`, `std::list`, `std::stack`,
`std::deque`), herança de um container da STL para estendê-lo com
iteração.

| Exercício | Descrição |
|---|---|
| `ex00` | `easyfind()` — função template que usa `std::find` sobre qualquer container |
| `ex01` | Span — armazena inteiros e calcula menor/maior span (diferença) entre eles |
| `ex02` | MutantStack — `std::stack` estendida para ser iterável |

### CPP-09 — STL Avançada / Projeto Final

Três exercícios independentes que exigem combinar containers, parsing de
entrada e algoritmos mais sofisticados — o "exame final" prático do
tronco comum de C++.

**Conceitos:** `std::map` para lookup ordenado, parsing e validação
robusta de entrada, `std::stack` para avaliação de expressões, algoritmo
de ordenação **merge-insert (Ford-Johnson / PmergeMe)** com comparação de
performance entre dois containers distintos.

| Exercício | Descrição |
|---|---|
| `ex00` | BitcoinExchange — lê uma base de cotações (`csv`) em `std::map` e converte valores por data |
| `ex01` | RPN — calculadora de notação polonesa reversa usando `std::stack` |
| `ex02` | PmergeMe — ordena uma sequência com o algoritmo de Ford-Johnson usando dois containers (ex.: `std::vector` e `std::list`) e compara o tempo de execução |

---

## Convenções usadas nos códigos

- **Padrão:** C++98 (`-std=c++98`), com `-Wall -Wextra -Werror` sempre
  ativos — nenhum warning é aceito.
- **Orthodox Canonical Form:** a maioria das classes implementa construtor
  padrão, construtor de cópia, `operator=` e destrutor, mesmo quando o
  compilador geraria versões equivalentes — é parte do que a 42 avalia.
  Sim, C++ tem esse formalismo por herdar diretamente da filosofia de
  gerenciamento manual de recursos do C.
- **Sem containers/STL antes do CPP-08** (com exceção de `std::string`):
  os módulos 00 a 06 usam apenas arrays e ponteiros crus, propositalmente,
  para forçar o entendimento de gerência de memória antes de abstrair com a
  STL.
- **Sem `printf`/`scanf`:** toda entrada/saída usa streams (`iostream`),
  como manda o C++.
- Cada `Makefile` segue o padrão `all` / `clean` / `fclean` / `re`, com
  saída colorida indicando sucesso da build.

---

## Autor

Feito por **Luca Bento** ([@lucabarbosa](https://github.com/lucabarbosa) | lbento).
Sinta-se livre para usar este repositório como referência de estudo.
