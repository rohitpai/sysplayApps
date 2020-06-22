#include<stdio.h>
#include "hiredis.h"

int main(int argc, char **argv) {

  int port = 6379;
  redisContext *c = redisConnect("127.0.0.1", port);
  if (c != NULL && c->err) {
      printf("Error: %s\n", c->errstr);
      // handle error
  } else {
      printf("Connected to Redis\n");
  }

  redisReply *reply;

  //reply = (redisReply *)redisCommand(c,"SET %s %s","foo","bar");
  //freeReplyObject(reply);

  reply = (redisReply *)redisCommand(c,"GET %s","foo");
  printf("%s\n",reply->str);
  freeReplyObject(reply);


  return 0;
}
