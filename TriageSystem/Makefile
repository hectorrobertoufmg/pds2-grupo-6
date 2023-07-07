INCLUDE := include
SRC := src
BUILD := build
BIN := bin
EXEC := main
TEST := teste_lista

<<<<<<< HEAD
${BIN}/${EXEC}: ${BUILD}/lista.o ${BUILD}/paciente.o ${BUILD}/funcoes.o ${BUILD}/anamnese.o ${BUILD}/exception.o ${BUILD}/setor.o ${BUILD}/medico.o ${BUILD}/main.o 
=======
${BIN}/${EXEC}: ${BUILD}/lista.o ${BUILD}/paciente.o ${BUILD}/funcoes.o ${BUILD}/main.o ${BUILD}/exception.o
>>>>>>> 8b5a285f9079a6f87f34f643e89489833fb09849
	@mkdir -p ${BIN}/
	g++ -std=c++17 $^ -o $@

${BUILD}/funcoes.o: ${SRC}/funcoes.cpp ${INCLUDE}/funcoes.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

<<<<<<< HEAD
${BUILD}/exception.o: ${SRC}/exception.cpp ${INCLUDE}/exception.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/paciente.o: ${SRC}/paciente.cpp ${INCLUDE}/paciente.hpp ${INCLUDE}/funcoes.hpp ${INCLUDE}/exception.hpp ${INCLUDE}/anamnese.hpp ${INCLUDE}/setor.hpp
=======
${BUILD}/exception.o: ${SRC}/exception.cpp ${INCLUDE}/exception.hpp ${INCLUDE}/exception.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/paciente.o: ${SRC}/paciente.cpp ${INCLUDE}/paciente.hpp ${INCLUDE}/funcoes.hpp
>>>>>>> 8b5a285f9079a6f87f34f643e89489833fb09849
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/lista.o: ${SRC}/lista.cpp ${INCLUDE}/lista.hpp ${INCLUDE}/paciente.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/anamnese.o: ${SRC}/anamnese.cpp ${INCLUDE}/anamnese.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/setor.o: ${SRC}/setor.cpp ${INCLUDE}/setor.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/medico.o: ${SRC}/medico.cpp ${INCLUDE}/medico.hpp ${INCLUDE}/lista.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/main.o: ${SRC}/main.cpp ${INCLUDE}/lista.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/teste_lista.o: ${SRC}/teste_lista.cpp ${INCLUDE}/lista.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

test_lista: ${BUILD}/lista.o ${BUILD}/paciente.o ${BUILD}/funcoes.o ${BUILD}/exception.o ${BUILD}/anamnese.o  ${BUILD}/setor.o ${BUILD}/teste_lista.o
	@mkdir -p ${BIN}/
	g++ -std=c++17 $^ -o ${BIN}/${TEST}

run: ${BIN}/${EXEC}
	@${BIN}/${EXEC}

run_test_lista: ${BIN}/${TEST}
	@${BIN}/${TEST}

clean:
	@rm -rf ${BIN}/ ${BUILD}/