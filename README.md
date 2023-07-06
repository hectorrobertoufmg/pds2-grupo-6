# Sistema de Triagem de Pacientes

Este repositório tem como objetivo a entrega do projeto "Sistema de Triagem de Pacientes" desenvolvido em C++ para a disciplina de Programação e desenvolvimento de software II (PDS II) na Universidade Federal de Minas Gerais (UFMG).
*Projeto de Reprodução Acadêmica Sem Fins Lucrativos*

## Descrição

A triagem é um método eficiente que visa otimizar o atendimento a pacientes em situações de superlotação em hospitais e clínicas. Segundo Iserson e Moskop 2004, desde o século 18, a prática da triagem tem sido reconhecida, tendo como principal impulso o contexto de conflitos armados. Nesse sistema, pacientes com alto risco de morte são priorizados no atendimento, especialmente em ambientes hospitalares superlotados.

Neste projeto, adotamos o Protocolo de Triagem de Manchester como modelo, amplamente reconhecido por sua eficácia, conforme evidenciado por Azeredo et al, 2015. Esse sistema utiliza uma escala de cores para classificar os pacientes em cinco níveis de prioridade. Profissionais de saúde devidamente capacitados empregam uma série de perguntas e avaliações para determinar a cor de triagem atribuída a cada paciente. Essas avaliações envolvem informações sobre sintomas, histórico médico, sinais vitais e identificação de quaisquer fatores de risco.


## Autora e autores

Adrian Rios <br>
Gabriel Reis <br>
Hector Silva <br>
Miguel Tang <br>
Nayara Matos <br>


## Referências


Iserson, Kenneth V., and John C. Moskop. “Triage in Medicine, Part I: Concept, History, and Types.” Annals of Emergency Medicine 49, no. 3 (March 2007): 275–81. https://doi.org/10.1016/j.annemergmed.2006.05.019.

Azeredo, Thereza Raquel Machado, Helisamara Mota Guedes, Ricardo Alexandre Rebelo De Almeida, Tânia Couto Machado Chianca, e José Carlos Amado Martins. “Efficacy of the Manchester Triage System: A Systematic Review”. International Emergency Nursing 23, no 2 (abril de 2015): 47–52. https://doi.org/10.1016/j.ienj.2014.06.001.

📦TriageSystem
 ┣ 📂.vscode
 ┃ ┣ 📜c_cpp_properties.json
 ┃ ┗ 📜settings.json
 ┣ 📂bin
 ┃ ┗ 📜main
 ┣ 📂build
 ┃ ┣ 📜exception.o
 ┃ ┣ 📜funcoes.o
 ┃ ┣ 📜lista.o
 ┃ ┣ 📜main.o
 ┃ ┗ 📜paciente.o
 ┣ 📂include
 ┃ ┣ 📜exception.hpp
 ┃ ┣ 📜funcoes.hpp
 ┃ ┣ 📜lista.hpp
 ┃ ┗ 📜paciente.hpp
 ┣ 📂src
 ┃ ┣ 📜exception.cpp
 ┃ ┣ 📜funcoes.cpp
 ┃ ┣ 📜lista.cpp
 ┃ ┣ 📜main.cpp
 ┃ ┗ 📜paciente.cpp
 ┗ 📜Makefile
