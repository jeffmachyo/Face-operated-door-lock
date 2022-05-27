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
        kill(pid, 10); 
    }
}

void sendDataToCloud(char *data) {
	startCloudTransfer(data);
	fflush(stdout);
	sleep(3);
	stopDataTransfer();
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
