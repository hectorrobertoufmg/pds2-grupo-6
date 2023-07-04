INCLUDE := include
SRC := src
BUILD := build
BIN := bin
EXEC := main

${BIN}/${EXEC}: ${BUILD}/lista.o ${BUILD}/paciente.o ${BUILD}/funcoes.o ${BUILD}/main.o ${BUILD}/exception.o
	@mkdir -p ${BIN}/
	g++ -std=c++17 $^ -o $@

${BUILD}/funcoes.o: ${SRC}/funcoes.cpp ${INCLUDE}/funcoes.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/exception.o: ${SRC}/exception.cpp ${INCLUDE}/exception.hpp ${INCLUDE}/exception.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/paciente.o: ${SRC}/paciente.cpp ${INCLUDE}/paciente.hpp ${INCLUDE}/funcoes.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/lista.o: ${SRC}/lista.cpp ${INCLUDE}/lista.hpp ${INCLUDE}/paciente.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@

${BUILD}/main.o: ${SRC}/main.cpp ${INCLUDE}/lista.hpp
	@mkdir -p ${BUILD}
	g++ -std=c++17 -I ${INCLUDE} -c $< -o $@


run: ${BIN}/${EXEC}
	@${BIN}/${EXEC}

clean:
	@rm -rf ${BIN}/ ${BUILD}/