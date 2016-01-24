all: pocrypter target

SRC_COMMON=pocrypt.c
CFLAGS=-g -O0

pocrypter: pocrypter.c ${SRC_COMMON}
	${CC} ${CFLAGS} $< ${SRC_COMMON} -o $@

target: target.c ${SRC_COMMON} 
	${CC} ${CFLAGS} $< ${SRC_COMMON} -o $@

.PHONY:
clean:
	rm pocrypter target
