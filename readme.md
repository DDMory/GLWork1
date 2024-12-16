# Computação Grafica - Trabalho 1

Desenvolvimento de programa que implementa transformações geometrias basicas em "objetos" 2D, tais como:

- Rotação;
- Translação;
- Escalonamento;
- Espelhamento.

## Tutorial

### Compilação

1. realizar clone do repo.

```bash
    git clone https://github.com/DDMory/GLWork1.git
```

2. acessar a pasta `src/` e compilar o arquivo `Trabalho.c`.

```bash
    cd src/ && gcc -o out Trabalho.c -lglut -lGL -lGLU -lm
```

3. Executar o executavel geral `out`.
```bash
    ./out
```

---
### Execução

Após compilar e executar, segue abaixo uma breve listagem de como realizar as transformações no desenho feito.

- ↑, ↓, ←, →: são as teclas principais para aplicar as transformações descritas.

- `M` : Tecla para aplicar o espelhamento, após clicar, o desenho será "movido" para a posição de seu espelhamento.

- `T` : Tecla para aplicar a tranlsção, após clicar, o usuario deverá pressionar uma das setas para indicar em que direção o desenho deve se mover.

- `R` : Tecla para aplicar a rotação, após clicar, o desenho será rotacionado/girado em algum dos sentidos.

- `S` : Tecla para aplicar o escalonamento, após clicar, o desenho terá sua escala alterada, aumentando/diminuindo seu tamanho.

- `I` : Tecla para resetar o desenho, após clicar, o desenho retornará ao ponto inicial, como se nenhuma transformação tivesse sido aplicado.

- `ESC` : Tecla para fechar/encerrar a execução.