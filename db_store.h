#ifndef DBSTORE_H
#define DBSTORE_H

int createDB(const char* s);
int createTable(const char* s);
int deleteData(const char* s);
int insertData(const char* s);
int updateData(const char* s);
int selectData(const char* s);
int callback(void* NotUsed, int argc, char** argv, char** azColName);


#endif
