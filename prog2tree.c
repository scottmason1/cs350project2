#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>

int main(int argc, char** argv){

  int opt, pFlag = 0, sFlag = 0, sleepTime = 1;
  int numLevels = 1, numChildren = 1;
  char usageString[] = "prog2tree [-u] [-N <num-levels>] [-M <num-children>] [-p] [-s <sleep-time]\n";

  while((opt = getopt(argc, argv, ":uN:M:ps:")) != -1){
    switch(opt){
      case 'u':
        fprintf(stderr, "Usage: %s", usageString);
        exit(1);
      case 'N':
        if(atoi(optarg) > 4){
          fprintf(stderr, "Levels cannot be higher than 4\n");
          return 0;
        }
        else{
          numLevels = atoi(optarg);
        }
        break;
      case 'M':
        if(atoi(optarg) > 3){
          fprintf(stderr, "Childen cannot be higher than 3\n");
          exit(1);
        }
        else{
          numChildren = atoi(optarg);
        }
        break;
      case 'p':
        pFlag = 1;
        break;
      case 's':
        sFlag = 1;
        sleepTime = atoi(optarg);
        break;
      case '?':
        fprintf(stderr, "Usage: %s", usageString);
        exit(1);
      }
    }

    for (int i = optind; i < argc; i++){
      fprintf(stderr, "Usage: %s", usageString);
      exit(1);
    }

    if(!pFlag && !sFlag){
      printf("ALIVE: Level %d process with pid=%d, child of ppid=%d\n", numLevels, getpid(), getppid());

      //int num = 1;
      int levels;
      char levels2[2];
      char children[2];

      sprintf(children, "%d", numChildren);
      pid_t childPID;

      //printf("NUm CHildren: %d", numChildren);

      //while(numLevels > 1){
        for(int j = 0; j < numChildren; j++){
          if(numLevels == 1){
            break;
          }

          childPID = fork();

          if(childPID < 0){
            perror("Couldn't fork.");
            exit(1);
          }

          if(childPID == 0){
            if(numLevels == 4){
              levels = 3;
            }
            if(numLevels == 3){
              levels = 2;
            }
            if(numLevels == 2){
              levels = 1;
            }

            sprintf(levels2, "%d", levels);
              //printf("Levels: %d\n Prog2Tree", levels);

	    execlp("./prog2tree", "./prog2tree", "-N", levels2, "-M", children, NULL);

            }
          }
          if(numLevels > 1){
            for(int i = 0; i < numChildren; i++){
              wait(NULL);
            }
          }
          else{
            sleep(sleepTime);
          }
          //num++;
        //}

      //}

      sleep(sleepTime);

      printf("EXITING: Level %d process with pid=%d, child of ppid=%d\n", numLevels, getpid(), getppid());
    }

    if(pFlag && !sFlag){
      printf("ALIVE: Level %d process with pid=%d, child of ppid=%d\n", numLevels, getpid(), getppid());


            //int num = 1;
            int levels;
            char levels2[2];
            char children[2];

            sprintf(children, "%d", numChildren);
            pid_t childPID;

            //printf("NUm CHildren: %d", numChildren);

            //while(numLevels > 1){
              for(int j = 0; j < numChildren; j++){
                if(numLevels == 1){
                  break;
                }
                childPID = fork();
                if(childPID < 0){
                  perror("Couldn't fork.");
                  exit(1);
                }

                if(childPID == 0){
                  if(numLevels == 4){
                    levels = 3;
                  }
                  if(numLevels == 3){
                    levels = 2;
                  }
                  if(numLevels == 2){
                    levels = 1;
                  }

                  sprintf(levels2, "%d", levels);
                    //printf("Levels: %d\n Prog2Tree", levels);

		  execlp("./prog2tree", "./prog2tree", "-N", levels2, "-M", children, "-p", NULL);


                  }
                }
                pause();
                //num++;
              //}

            //}

            //pause();

      printf("EXITING: Level %d process with pid=%d, child of ppid=%d\n", numLevels, getpid(), getppid());
    }

    if(!pFlag && sFlag){
      printf("ALIVE: Level %d process with pid=%d, child of ppid=%d\n", numLevels, getpid(), getppid());


            //int num = 1;
            int levels;
            char levels2[2];
            char children[2];
            char sleepyTime[10];

            sprintf(children, "%d", numChildren);
            sprintf(sleepyTime, "%d", sleepTime);
            pid_t childPID;

            //printf("NUm CHildren: %d", numChildren);

            //while(numLevels > 1){
              for(int j = 0; j < numChildren; j++){
                if(numLevels == 1){
                  break;
                }
                childPID = fork();
                if(childPID < 0){
                  perror("Couldn't fork.");
                  exit(1);
                }

                if(childPID == 0){
                  if(numLevels == 4){
                    levels = 3;
                  }
                  if(numLevels == 3){
                    levels = 2;
                  }
                  if(numLevels == 2){
                    levels = 1;
                  }

                  sprintf(levels2, "%d", levels);
                    //printf("Levels: %d\n Prog2Tree", levels);

		  execlp("./prog2tree", "./prog2tree", "-N", levels2, "-M", children, "-s", sleepyTime, NULL);


                  }
                }
                if(numLevels > 1){
                  for(int i = 0; i < numChildren; i++){
                    wait(NULL);
                  }
                }
                else{
                  sleep(sleepTime);
                }
                //num++;
              //}

            //}

            //sleep(sleepTime);
      printf("EXITING: Level %d process with pid=%d, child of ppid=%d\n", numLevels, getpid(), getppid());
    }

    if(pFlag && sFlag){
      fprintf(stderr, "Cannot use both -p and -s\n");
      exit(1);
    }

  return 0;
}
