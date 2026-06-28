#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void handler(int sig){
  exit(2);
}

void lancer(char *moteur, char *bot){
  char cmd_moteur[100], cmd_bot[100];
  sprintf(cmd_moteur, "./%s", moteur);
  sprintf(cmd_bot, "./%s", bot);
  
  int b2m[2];
  pipe(b2m);

  int pid;
  if((pid = fork()) != 0){
    if(fork() == 0){
      close(b2m[1]);
      dup2(b2m[0], STDIN_FILENO);
      close(b2m[0]);
      execlp(cmd_moteur, moteur, NULL);
      perror("moteur");
      exit(1);
    }
    wait(NULL);
    kill(pid, SIGKILL);
    kill(-getpid(), SIGKILL);
  } else {
    close(b2m[0]);
    dup2(b2m[1], STDOUT_FILENO);
    close(b2m[1]);
    while(true){
      sleep(1); // à modifier si calcul du nouveau plateau trop lent
      if(fork()==0){
	execlp(cmd_bot, bot, NULL);
	perror("bot");
      } else {
	wait(NULL);
      }
    }
    exit(1);
  }
}


int main(int argc, char **argv){
  //exec_moteur exec_bot
  if(argc != 3){
    fprintf(stderr, "%s, usage : %s exec_moteur exec_bot\n", argv[0], argv[0]);
    return 1;
  }

  lancer(argv[1], argv[2]);
  
  return 0;
}
