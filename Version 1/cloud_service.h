#ifndef CLOUDSERV_H
#define CLOUDSERV_H

void sendDataToCloud(char *data);
void startCloudTransfer(char *data);

//void startPic(char *filename, char *options);
void stopDataTransfer(void);
//void takePic(char *filename);
#endif
