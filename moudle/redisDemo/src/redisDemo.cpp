#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis.h>


int main(int argc, char **argv) {
	unsigned int j;
	redisContext *c;
	redisReply *reply;
	const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
	int port = (argc > 2) ? atoi(argv[2]) : 6379;

	struct timeval timeout = {1, 500000};
	c = redisConnectWithTimeout(hostname, port, timeout);	

	if (c == NULL) {
		printf("Connection error: can't allocate redis context\n");
		exit(1);
	}
	if (c->err) {
		printf("Connection error: %s\n", c->errstr);
		redisFree(c);
	}
	
	reply = (redisReply *)redisCommand(c, "PING");
	printf ("PING: %s\n", reply->str);
	freeReplyObject(reply);
	
	reply = (redisReply *)redisCommand(c,"SET %s %s", "foo", "hello world");
	printf("SET: %s\n", reply->str);
	freeReplyObject(reply);

	reply = (redisReply *)redisCommand(c,"GET foo");
	printf("GET foo: %s\n", reply->str);
	freeReplyObject(reply);

	return 0;
}
