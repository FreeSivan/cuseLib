CXX=g++
CPPFLAGS += -I../include
LDFLAGS += -L../lib -lmemcached -lpthread
OBJECT := memcacheDemo.o
BIN_DIR := ../bin

memcacheDemo : ${OBJECT} 
	${CXX} $^ ${LDFLAGS} -o ${BIN_DIR}/$@
	@rm -f ${OBJECT}

%.o : %.cpp
	${CXX} $< ${CPPFLAGS} -c -o $@ 

clean:
	@rm -rf ${OBJECT} ${BIN_DIR}/$@
