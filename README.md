
# Sistema de Triagem de Pacientes

## Índice

- [Visão geral](#descrição-geral)
- [Como Funciona](#como-funciona)
    - [Como inicializar](#como-inicializar)
    - [Como utilizar](#como-utilizar)
- [Folder tree](#folder-tree)
- [Constribuições](#autora-e-autores)
- [Referências](#referências)

Este repositório tem como objetivo a entrega do projeto "Sistema de Triagem de Pacientes" desenvolvido em C++ para a disciplina de Programação e desenvolvimento de software II (PDS II) na Universidade Federal de Minas Gerais (UFMG).<br>
*Projeto de Reprodução Acadêmica Sem Fins Lucrativos*

## Descrição geral

A triagem é um conjuto procedimentos que visam otimizar o atendimento a pacientes e tem como ponto nevrálgico a estratégia de atender os pacientes de  acordo com o risco de morte do assistido. Segundo [Iserson e Moskop 2004](https://doi.org/10.1016/j.annemergmed.2006.05.019), há registro da utilização de técnicas de triagem que datam do século 18. Além disso, no trabalho de [Iserson e Moskop 2004](https://doi.org/10.1016/j.annemergmed.2006.05.019) mostra que o desenvolvimento de estratégias de triagem teve sua origem essencialmente no contexto de conflitos armados    . 

Neste projeto, adotamos o Protocolo de Triagem de Manchester como modelo, amplamente reconhecido por sua eficiÊncia e eficácia, conforme evidenciado por [Azeredo et al, 2015](https://doi.org/10.1016/j.ienj.2014.06.001). Esse sistema utiliza uma escala de cores para classificar os pacientes em cinco níveis de prioridade. Profissionais de saúde devidamente capacitados empregam uma série de perguntas e avaliações para determinar a cor de triagem atribuída a cada paciente. Essas avaliações envolvem informações sobre sintomas, histórico médico, sinais vitais e identificação de quaisquer fatores de risco. Ao final, a cor atribuída representa o nível de gravidade da comorbidade do paciente, sendo a vermelha indicativo do mais grave e a azul do menos grave.

<div style= "text-align: right;"><br><sub><a href="#sistema-de-triagem-de-pacientes">Voltar ao topo</a></sub><br>
</div>

## Como funciona
O programa apresenta um processo simplificado para cadastro e avaliação de pacientes por um médico, além da respectiva distribuição dos pacientes para os médicos cadastrados. Dentre as funcionalidades, temos: <br>
    1. Adicionar Paciente: Permite cadastrar um novo paciente com informações como nome, idade, CPF e convênio médico. Também solicita a coleta de dados de anamnese para associar ao paciente, onde são avaliados aspectos como os sintomas, temperatura, pressão, peso, altura, entre outras informações acerca do indivíduo. <br>
    2. Editar Avaliação e Anamnese: Essa funcionalidade permite selecionar um paciente cadastrado e editar sua avaliação médica, alterando a cor da prioridade. Também oferece a opção de editar os dados da anamnese do paciente. <br>
    3. Visualizar Paciente: Permite mostrar as informações de cadastro do paciente, bem como os dados coletados na anamnese. <br>
    4. Remover Paciente: Permite remover um paciente cadastrado na lista. <br>
    
<div style= "text-align: right;"><br><sub><a href="#sistema-de-triagem-de-pacientes">Voltar ao topo</a></sub><br>
</div>

### Como inicializar
Vá para a pasta raíz do software e digite o seguinte comando: <br>

> make

Em seguida, quando tudo já estiver compilado digite:

> make run

### Como utilizar

Leia atentamente as opções fornecidas pelo "Menu".

Digite o número correspondente com a ação que você deseja tomar:

<div style= "text-align: right;"><br><sub><a href="#sistema-de-triagem-de-pacientes">Voltar ao topo</a></sub><br>
</div>

## Folder tree

📦TriageSystem<br>
 ┣ 📂bin<br>
 ┃ ┗ 📜main<br>
 ┣ 📂build<br>
 ┃ ┣ 📜exception.o<br>
 ┃ ┣ 📜funcoes.o<br>
 ┃ ┣ 📜lista.o<br>
 ┃ ┣ 📜main.o<br>
 ┃ ┗ 📜paciente.o<br>
 ┣ 📂include<br>
 ┃ ┣ 📜exception.hpp<br>
 ┃ ┣ 📜funcoes.hpp<br>
 ┃ ┣ 📜lista.hpp<br>
 ┃ ┗ 📜paciente.hpp<br>
 ┣ 📂src<br>
 ┃ ┣ 📜exception.cpp<br>
 ┃ ┣ 📜funcoes.cpp<br>
 ┃ ┣ 📜lista.cpp<br>
 ┃ ┣ 📜main.cpp<br>
 ┃ ┗ 📜paciente.cpp<br>
 ┗ 📜Makefile<br>

<div style= "text-align: right;"><br><sub><a href="#sistema-de-triagem-de-pacientes">Voltar ao topo</a></sub><br>
</div> 

## Autora e autores

[Adrian Rios](https://github.com/adrian-rios) <br>
[Gabriel Reis](https://github.com/gabriel-hrp) <br>
[Hector Silva](https://github.com/hectorrobertoufmg) <br>
[Miguel Tang](https://github.com/Mtangjr) <br>
[Nayara Matos](https://github.com/nayaramatos) <br>

<div style= "text-align: right;"><br><sub><a href="#sistema-de-triagem-de-pacientes">Voltar ao topo</a></sub><br>
</div>

## Referências


Iserson, Kenneth V., and John C. Moskop. “Triage in Medicine, Part I: Concept, History, and Types.” Annals of Emergency Medicine 49, no. 3 (March 2007): 275–81. https://doi.org/10.1016/j.annemergmed.2006.05.019.

Azeredo, Thereza Raquel Machado, Helisamara Mota Guedes, Ricardo Alexandre Rebelo De Almeida, Tânia Couto Machado Chianca, e José Carlos Amado Martins. “Efficacy of the Manchester Triage System: A Systematic Review”. International Emergency Nursing 23, no 2 (abril de 2015): 47–52. https://doi.org/10.1016/j.ienj.2014.06.001.

[Grupo Brasileiro de Classificação de Risco](https://www.gbcr.org.br).

[Nyakundi, H](https://www.freecodecamp.org/news/author/larymak/). (2021). "How to Write a Good README File for Your GitHub Project." freeCodeCamp.org. Recuperado de: https://www.freecodecamp.org/news/how-to-write-a-good-readme-file/.

<div style= "text-align: right;"><br><sub><a href="#sistema-de-triagem-de-pacientes">Voltar ao topo</a></sub><br>
</div>
