RM =	cmd //C del



# Compilador

CC=g++ 



# Variaveis para os subdiretorios

LIB_DIR=lib

INC_DIR=include

SRC_DIR=src

OBJ_DIR=build

BIN_DIR=bin

DOC_DIR=doc

TEST_DIR=test
 


# Opcoes de compilacao

CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)



# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome

.PHONY: all init clean debug doxy doc



# Define o alvo (target) para a compilacao completa e os alvos de dependencia.

# Ao final da compilacao, remove os arquivos objeto.

all:	projeto2


debug: CFLAGS += -g -O0

debug: all




projeto2: $(OBJ_DIR)/main.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/openarquivo.o

	@echo "============="

	@echo "Ligando o alvo $@"

	@echo "============="

	$(CC) $(CFLAGS) -o $(BIN_DIR)/projeto2 $^

	@echo "+++ [Executavel projeto2 criado em  $(BIN_DIR)/projeto2] +++"

	@echo "============="







$(OBJ_DIR)/openarquivo.o: $(SRC_DIR)/openarquivo.cpp $(INC_DIR)/openarquivo.h

	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.cpp $(INC_DIR)/listagem.h $(INC_DIR)/menu.h $(INC_DIR)/lista.h $(INC_DIR)/openarquivo.h

	$(CC) -c $(CFLAGS) -o $@ $<


$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/menu.h

	$(CC) -c $(CFLAGS) -o $@ $<





doxy:
	
	doxygen -g

doc:

	$(RM) $(DOC_DIR)/*


	doxygen



# Alvo (target) usado para limpar os arquivos temporarios (objeto)

# gerados durante a compilacao, assim como os arquivos binarios/executaveis.

clean:

	$(RM) $(OBJ_DIR)/*




