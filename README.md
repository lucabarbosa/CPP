# C++ Modules — 42 São Paulo

Repository with all the solutions for the C++ modules (CPP-00 through CPP-09)
from the [42 São Paulo](https://42sp.org.br/) curriculum. The goal here is to
consolidate, in practice, the transition from C to C++: object-oriented
programming, RAII, operator overloading, inheritance, polymorphism,
exception handling, templates, and the main STL containers/algorithms.

This README serves as a **summary and study guide**: for each module there is
a short explanation of the concepts covered and the list of corresponding
exercises. There is also an **[interactive HTML guide](cpp-guide.html)**
(in Portuguese BR) with practical usage examples of the main
functions/classes of each module, intended for quick reference.

> 📘 Want to study with annotated examples? Open [`cpp-guide.html`](cpp-guide.html)
> in your browser — it includes didactic explanations, code snippets, and
> links to external references (cppreference, etc).

---

## Table of Contents

- [Requirements](#requirements)
- [How to Build and Test](#how-to-build-and-test)
- [Repository Structure](#repository-structure)
- [Modules](#modules)
  - [CPP-00 — Namespaces, Classes, Static Members, Files](#cpp-00--namespaces-classes-static-members-files)
  - [CPP-01 — Memory, Pointers and References](#cpp-01--memory-pointers-and-references)
  - [CPP-02 — Operator Overloading (Ad-hoc Polymorphism)](#cpp-02--operator-overloading-ad-hoc-polymorphism)
  - [CPP-03 — Inheritance](#cpp-03--inheritance)
  - [CPP-04 — Polymorphism, Abstract Classes and Interfaces](#cpp-04--polymorphism-abstract-classes-and-interfaces)
  - [CPP-05 — Exception Handling](#cpp-05--exception-handling)
  - [CPP-06 — Casting (Type Conversions)](#cpp-06--casting-type-conversions)
  - [CPP-07 — Templates](#cpp-07--templates)
  - [CPP-08 — STL Containers and Algorithms](#cpp-08--stl-containers-and-algorithms)
  - [CPP-09 — Advanced STL / Final Project](#cpp-09--advanced-stl--final-project)
- [Coding Conventions](#coding-conventions)
- [Author](#author)

---

## Requirements

To compile and run the exercises you only need a Unix environment (Linux or
macOS) with the following tools:

| Tool | Recommended minimum version | Use |
|---|---|---|
| **g++** or **clang++** | with `-std=c++98` support | C++ compiler |
| **make** | any recent version (GNU Make) | Build automation |
| **valgrind** *(optional)* | any recent version | Memory leak checking |

All the code is written following the **C++98** standard, required by 42, and
compiled with the flags:

```
-Wall -Wextra -Werror -std=c++98
```

Quick install on Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential valgrind
```

On macOS (with Homebrew), the Xcode Command Line Tools already provide
`clang++` and `make`:

```bash
xcode-select --install
brew install valgrind # optional, limited support on macOS
```

---

## How to Build and Test

Each exercise (`exXX/`) is **independent** and has its own `Makefile` with
the standard targets:

| Target | What it does |
|---|---|
| `make` / `make all` | Compiles the `.cpp` files in the directory and generates the executable |
| `make clean` | Removes the object files (`.o`) |
| `make fclean` | Removes object files **and** the final executable |
| `make re` | Equivalent to `fclean` + `all` (full rebuild) |
| `make valgrind` *(when available)* | Runs the binary under `valgrind` to check for leaks |
| `make test` *(when available)* | Runs the binary with a ready-made test scenario |

### Building a single exercise

```bash
cd CPP-03/ex01
make
./scavtrap
```

### Building all exercises in the repository at once

There is no "root" Makefile, since each 42 module/exercise is evaluated
independently — but it's easy to generate all executables with a single
command from the root of the repository:

```bash
find . -name Makefile -execdir make \;
```

To clean everything (object files and binaries) at once:

```bash
find . -name Makefile -execdir make fclean \;
```

### Testing manually

Most exercises expect arguments via the command line or interact through
`stdin`. Check each exercise's `main.cpp` to see the expected usage, for
example:

```bash
cd CPP-09/ex01
make
echo "3 4 +" | ./RPN "3 4 +"
```

---

## Repository Structure

```
CPP/
├── CPP-00/            # Introduction to C++, classes, static members
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── CPP-01/            # Memory, pointers, references
│   ├── ex00 .. ex06/
├── CPP-02/            # Operator overloading (Fixed class)
│   ├── ex00 .. ex02/
├── CPP-03/            # Inheritance (ClapTrap, ScavTrap, FragTrap)
│   ├── ex00 .. ex02/
├── CPP-04/            # Polymorphism and abstract classes (Animal)
│   ├── ex00 .. ex02/
├── CPP-05/            # Exceptions (Bureaucrat, Form)
│   ├── ex00 .. ex03/
├── CPP-06/            # Casting (ScalarConverter, Serializer, dynamic_cast)
│   ├── ex00 .. ex02/
├── CPP-07/            # Templates
│   ├── ex00 .. ex02/
├── CPP-08/            # STL containers and algorithms
│   ├── ex00 .. ex02/
└── CPP-09/            # Advanced STL / complex algorithms
    ├── ex00 .. ex02/
```

Each `exXX/` contains, at minimum: the source files (`.cpp`/`.hpp`), a
demonstration `main.cpp`, and a `Makefile`.

---

## Modules

### CPP-00 — Namespaces, Classes, Static Members, Files

First contact with C++: class syntax, `std::string`, streams
(`iostream`/`fstream`), and the difference between the "C-like" approach and
the object-oriented approach to organizing a program.

**Concepts:** namespaces, classes and private/public members, `std::string`,
`std::cin`/`std::cout`, `static` members and methods (data shared by all
instances), fixed-size arrays of objects, and good allocation practices
(avoiding unnecessary `new`/`delete`).

| Exercise | Description |
|---|---|
| `ex00` | Megaphone — reading `argv`, transforming strings to uppercase |
| `ex01` | PhoneBook — `Contact` class + `PhoneBook` class with a static buffer of 8 contacts |
| `ex02` | Account — `static` members and methods, event logging across multiple instances |

### CPP-01 — Memory, Pointers and References

Focus on manual memory management (stack vs heap) and the practical
differences between pointers and references — the foundation for
understanding RAII in the following modules.

**Concepts:** heap allocation (`new`/`delete`) vs stack, pointers vs
references, pointers to class members/functions, `switch`, file handling
(`std::ifstream`/`std::ofstream`), dynamic arrays of objects, and the use of
`std::string::find`/`replace`.

| Exercise | Description |
|---|---|
| `ex00` | Zombie — object on the stack vs object on the heap (`newZombie` / `randomChump`) |
| `ex01` | Zombie Horde — dynamic array of objects (`zombieHorde`) |
| `ex02` | References vs pointers to the same variable |
| `ex03` | Weapon/HumanA/HumanB — attributes by reference vs by pointer |
| `ex04` | `sed`-like — file reading/writing and substring replacement |
| `ex05` | Harl — pointers to class methods (member function pointers) |
| `ex06` | Harl Filter — the same, but with log-level fallthrough (`switch`) |

### CPP-02 — Operator Overloading (Ad-hoc Polymorphism)

Implementation of a fixed-point numeric type (`Fixed`) to practice the
**Orthodox Canonical Form** (default constructor, copy constructor,
`operator=`, destructor) and overloading of arithmetic, comparison, and
increment/decrement operators.

**Concepts:** Orthodox Canonical Form, operator overloading
(`+ - * / == != < > <= >= ++ -- << >>`), fixed-point representation with
bitshifting, `int`/`float` ↔ fixed-point conversion, static members
(`min`/`max`).

| Exercise | Description |
|---|---|
| `ex00` | Fixed — basic Orthodox Canonical Form with fixed-point storage |
| `ex01` | Fixed — constructors from `int`/`float`, `toInt`/`toFloat` converters |
| `ex02` | Fixed — full operator overloading + static `min`/`max` |

### CPP-03 — Inheritance

A classic "monster" hierarchy (`ClapTrap → ScavTrap/FragTrap`) to understand
how constructors/destructors chain between base and derived classes, and how
to override behavior while reusing code.

**Concepts:** single and multiple inheritance, constructor/destructor call
order, `protected` vs `private`, method overriding, reuse via
`Base::method()`.

| Exercise | Description |
|---|---|
| `ex00` | ClapTrap — base class with hit points, energy, and attack damage |
| `ex01` | ScavTrap — inherits from ClapTrap, adds `guardGate` |
| `ex02` | FragTrap — second derived class, adds `highFivesGuys` |

### CPP-04 — Polymorphism, Abstract Classes and Interfaces

`Animal → Dog/Cat` hierarchy exploring runtime polymorphism, the reason for
using a `virtual` destructor, abstract classes, and pure interfaces.

**Concepts:** `virtual` functions and dynamic binding, virtual destructor
(avoiding memory leaks when deleting via a base pointer), abstract classes
(`= 0`), composition (has-a) with `Brain`, interfaces (100% abstract
classes).

| Exercise | Description |
|---|---|
| `ex00` | Animal/Dog/Cat — basic polymorphism and the "WrongAnimal" problem (without `virtual`) |
| `ex01` | Adds `Brain` — composition, deep copy in the copy constructor |
| `ex02` | Makes `Animal` an abstract class (non-instantiable) |

### CPP-05 — Exception Handling

Simulation of a bureaucratic workflow (`Bureaucrat` signs `Form`s), used as
a pretext to practice custom exceptions and the "Chain of Responsibility"
design pattern (Intern dynamically creates the right `Form`).

**Concepts:** `try`/`catch`/`throw`, custom exception classes (inheriting
from `std::exception`), `what()`, RAII applied to state validation,
hierarchy of abstract classes (`AForm`) with concrete actions
(`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`).

| Exercise | Description |
|---|---|
| `ex00` | Bureaucrat — exceptions for grade too high/too low |
| `ex01` | Form — form signing with permission validation |
| `ex02` | AForm + 3 concrete forms — polymorphic action execution |
| `ex03` | Intern — factory that creates the right `Form` from a `string` |

### CPP-06 — Casting (Type Conversions)

Exclusive focus on C++'s type conversion operators and on how to identify
an object's actual type at runtime.

**Concepts:** `static_cast`, `dynamic_cast`, `reinterpret_cast`,
`const_cast`, runtime type detection via RTTI, pointer serialization
(`uintptr_t`), handling special floating-point values (`nan`, `inf`).

| Exercise | Description |
|---|---|
| `ex00` | ScalarConverter — converts between `char`/`int`/`float`/`double` using `static_cast` |
| `ex01` | Serializer — converts a pointer to an integer and back using `reinterpret_cast` |
| `ex02` | Identify (A/B/C) — identifies an object's actual type using `dynamic_cast` |

### CPP-07 — Templates

Introduction to generic programming: writing functions and classes that
work for any type, without duplicating code.

**Concepts:** function templates, class templates, templates with multiple
type parameters, `typename`, implicit instantiation, generic arrays with
bounds checking via exceptions.

| Exercise | Description |
|---|---|
| `ex00` | Template functions `whatever(a, b)` — generic `max`/`swap` |
| `ex01` | `iter()` — applies a function to each element of a generic array |
| `ex02` | `Array<T>` — template class with safe access (`operator[]` with bounds check) |

### CPP-08 — STL Containers and Algorithms

First "serious" contact with the STL: sequence/associative containers and
the standard algorithms that operate over iterators.

**Concepts:** iterators (`begin`/`end`), generic algorithms (`std::find`),
containers (`std::vector`, `std::list`, `std::stack`, `std::deque`),
inheriting from an STL container to extend it with iteration.

| Exercise | Description |
|---|---|
| `ex00` | `easyfind()` — template function that uses `std::find` on any container |
| `ex01` | Span — stores integers and computes the shortest/longest span (difference) between them |
| `ex02` | MutantStack — extended `std::stack` made iterable |

### CPP-09 — Advanced STL / Final Project

Three independent exercises that require combining containers, input
parsing, and more sophisticated algorithms — the practical "final exam" of
the C++ common core.

**Concepts:** `std::map` for ordered lookup, robust input parsing and
validation, `std::stack` for expression evaluation, the **merge-insert
(Ford-Johnson / PmergeMe)** sorting algorithm with a performance comparison
between two different containers.

| Exercise | Description |
|---|---|
| `ex00` | BitcoinExchange — reads a quotes database (`csv`) into a `std::map` and converts values by date |
| `ex01` | RPN — reverse Polish notation calculator using `std::stack` |
| `ex02` | PmergeMe — sorts a sequence using the Ford-Johnson algorithm with two containers (e.g., `std::vector` and `std::list`) and compares execution time |

---

## Coding Conventions

- **Standard:** C++98 (`-std=c++98`), with `-Wall -Wextra -Werror` always
  enabled — no warnings are accepted.
- **Orthodox Canonical Form:** most classes implement a default constructor,
  copy constructor, `operator=`, and destructor, even when the compiler
  would generate equivalent versions — this is part of what 42 evaluates.
  Yes, C++ has this formalism because it inherits directly from C's manual
  resource management philosophy.
- **No containers/STL before CPP-08** (with the exception of `std::string`):
  modules 00 through 06 use only arrays and raw pointers, deliberately, to
  force an understanding of memory management before abstracting with the
  STL.
- **No `printf`/`scanf`:** all input/output uses streams (`iostream`), as
  C++ dictates.
- Each `Makefile` follows the `all` / `clean` / `fclean` / `re` pattern,
  with colored output indicating build success.

---

## Author

Made by **Luca Bento** ([@lucabarbosa](https://github.com/lucabarbosa) | lbento).
Feel free to use this repository as a study reference.