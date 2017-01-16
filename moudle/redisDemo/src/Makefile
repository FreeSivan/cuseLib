CXX = g++

CPPFLAGS += -I../include
LDFLAGS +=  -L../lib -lhiredis

BIN_DIR := ../bin

redisDemo : redisDemo.o
	${CXX} $^ -o ${BIN_DIR}/$@ ${LDFLAGS}

%.o : %.cpp
	$(CXX) $< -c -o $@ ${CPPFLAGS}

clean:
	@rm *.o ${BIN_DIR}/redisDemo -f
