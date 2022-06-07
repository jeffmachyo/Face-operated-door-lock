#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

static pid_t pid = 0;

void stopPic(void) {
    if (pid) {
        kill(pid, 10); // seems to stop with two signals separated
                       // by 1 second if started with -t 10 parameter
        sleep(1);
        kill(pid, 10);
    }
}

void takePic(char *filename) {
	if ((pid = fork()) == 0) {
        //char **cmd;
	execl("/usr/bin/raspistill",
		"/usr/bin/raspistill",
                "-n",
                "-vf",
                "-o",
                filename,
                NULL);

	}
}




