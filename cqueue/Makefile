CC=gcc
OBJ=*.o
FLAGS=-g -Wall
INCLUDES= -I .
FILE=c
TARGET=test

all: $(OBJ)
	@$(CC) ${FLAGS} ${INCLUDES} ${OBJ} -o ${TARGET}.out
	@echo Building...	[OK]

%.o: %.c
	@echo Building $*.${FILE}
	@$(CC) ${FLAGS} -c $*.${FILE} ${INCLUDES}

clean:
	@rm -rf *.o
	@rm -rf ${TARGET}.out
	@echo Cleaning...	[OK]

	
