<div style="position: fixed; bottom: 0; right: 0;">
 <a href="#sistema-de-triagem-de-pacientes">Voltar ao topo</a></div>


# Sistema de Triagem de Pacientes


Este repositório tem como objetivo a entrega do projeto "Sistema de Triagem de Pacientes" desenvolvido em C++ para a disciplina de Programação e desenvolvimento de software II (PDS II) na Universidade Federal de Minas Gerais (UFMG).
*Projeto de Reprodução Acadêmica Sem Fins Lucrativos*

## Descrição geral

A triagem é um método eficiente que visa otimizar o atendimento a pacientes em situações de superlotação em hospitais e clínicas. Segundo Iserson e Moskop 2004, desde o século 18, a prática da triagem tem sido reconhecida, tendo como principal impulso o contexto de conflitos armados. Nesse sistema, pacientes com alto risco de morte são priorizados no atendimento, especialmente em ambientes hospitalares superlotados.

Neste projeto, adotamos o Protocolo de Triagem de Manchester como modelo, amplamente reconhecido por sua eficácia, conforme evidenciado por Azeredo et al, 2015. Esse sistema utiliza uma escala de cores para classificar os pacientes em cinco níveis de prioridade. Profissionais de saúde devidamente capacitados empregam uma série de perguntas e avaliações para determinar a cor de triagem atribuída a cada paciente. Essas avaliações envolvem informações sobre sintomas, histórico médico, sinais vitais e identificação de quaisquer fatores de risco.

### Como funciona?  

Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam mattis posuere diam, ac pulvinar quam congue non. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Phasellus consectetur fringilla nisi, vel rutrum justo finibus ac

### Como utilizar
Vá para a pasta raíz do software e digite o seguinte comando: <br>
> make

Em seguida, quando tudo já estiver compilado digite:

> make run

Leia atentamente as opções fornecidas pelo "Menu".

Digite o número correspondente com a ação que você deseja tomar:

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

                                                                           
## Autora e autores

[Adrian Rios](https://github.com/adrian-rios) <br>
[Gabriel Reis](https://github.com/gabriel-hrp) <br>
[Hector Silva](https://github.com/hectorrobertoufmg) <br>
[Miguel Tang](https://github.com/Mtangjr) <br>
[Nayara Matos](https://github.com/nayaramatos) <br>


## Referências


Iserson, Kenneth V., and John C. Moskop. “Triage in Medicine, Part I: Concept, History, and Types.” Annals of Emergency Medicine 49, no. 3 (March 2007): 275–81. https://doi.org/10.1016/j.annemergmed.2006.05.019.

Azeredo, Thereza Raquel Machado, Helisamara Mota Guedes, Ricardo Alexandre Rebelo De Almeida, Tânia Couto Machado Chianca, e José Carlos Amado Martins. “Efficacy of the Manchester Triage System: A Systematic Review”. International Emergency Nursing 23, no 2 (abril de 2015): 47–52. https://doi.org/10.1016/j.ienj.2014.06.001.

[Nyakundi, H](https://www.freecodecamp.org/news/author/larymak/). (2021). "How to Write a Good README File for Your GitHub Project." freeCodeCamp.org. Recuperado de: https://www.freecodecamp.org/news/how-to-write-a-good-readme-file/.

