#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static pid_t pid = 0;

void sendDataToCloud(char *data);
void startCloudTransfer(char *data);

void stopDataTransfer(void) {
    if (pid) {
        kill(pid, 10); // seems to stop with two signals separated
                       // by 1 second if started with -t 10 parameter
        //sleep(1);
        //kill(pid, 10);
    }
}

void sendDataToCloud(char *data) {
	if ((pid = fork()) == 0) {
        char **cmd;
        
        cmd = malloc( 15 * sizeof(char **));
	cmd[0] = "/home/pi/sdk-workspace/aws-iot-device-sdk-cpp-v2/samples/pub_sub/basic_pub_sub/build/basic-pub-sub";// executable name
        cmd[1] = "--message"; // no preview
        cmd[2] = data; // default time (overridden by -s)
                               // but needed for clean exit
        //cmd[count + 3] = "10"; // 10 millisecond (minimum) time for -t
        //cmd[count + 4] = "-s"; // enable USR1 signal to stop recording
        cmd[3] = "--count"; // output file specifer
        cmd[4] = "1";
	cmd[5] = "--ca_file";
	cmd[6] = "~/certs/Amazon-root-CA-1.pem";
	cmd[7] = "--cert";
	cmd[8] = "~/certs/device.pem.crt";
	cmd[9] = "--key";
	cmd[10] = "~/certs/private.pem.key";
	cmd[11] = "--endpoint";
	cmd[12] = "a30qj2cejm4ocg-ats.iot.us-west-2.amazonaws.com";       
	cmd[13] = (char *)0; // terminator
        execv("/home/pi/sdk-workspace/aws-iot-device-sdk-cpp-v2/samples/pub_sub/basic_pub_sub/build/basic-pub-sub", cmd);
	}
}

void startCloudTransfer(char *data) {
	if ((pid = fork()) == 0) {
	execl("/home/pi/sdk-workspace/aws-iot-device-sdk-cpp-v2/samples/pub_sub/basic_pub_sub/build/basic-pub-sub",
		"/home/pi/sdk-workspace/aws-iot-device-sdk-cpp-v2/samples/pub_sub/basic_pub_sub/build/basic-pub-sub",
		"--topic",
		"topic_1",
		"--message",
		data, 
		"--count", 
		"1", 
		"--ca_file", 
		"/home/pi/certs/Amazon-root-CA-1.pem", 
		"--cert", 
		"/home/pi/certs/device.pem.crt",
		"--key", 
		"/home/pi/certs/private.pem.key", 
		"--endpoint", 
		"a30qj2cejm4ocg-ats.iot.us-west-2.amazonaws.com",
		NULL);
} 
}
