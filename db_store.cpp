#include <sqlite3.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "base64.h"
#include <ctime>
#include <fstream>

using namespace std;

int createDB(const char* s);
int createTable(const char* s);
int deleteData(const char* s);
int insertData(const char* s);
int updateData(const char* s);
int selectData(const char* s);
int callback(void* NotUsed, int argc, char** argv, char** azColName);

class Door {
	private:
	string timeStamp;
	int doorStatus;
	string doorImage;

	public:
	Door() {}
	Door(string timeStamp,int doorStatus) {
		this->timeStamp = timeStamp;
		this->doorStatus = doorStatus;
	}
	Door(string timeStamp,int doorStatus,string image) {
		this->timeStamp = timeStamp;
		this->doorStatus = doorStatus;
		this->doorImage = image;
	}
	string getTimeStamp() {
		return timeStamp;
	}
	void setTimeStamp(string time) {
		this->timeStamp = time;
	}
	int getDoorStatus();
	void setDoorStatus(int doorStatus);
	string getImage();
	void setImage(string Image);

};

int Door::getDoorStatus() {
	return doorStatus;
}
void Door::setDoorStatus(int doorStatus) {
	this->doorStatus = doorStatus;
}

string Door::getImage() {
	return doorImage;
}

void Door::setImage(string image) {
	this->doorImage = image;
}


int createDB(const char* s)
{
	sqlite3* DB;
	
	int exit = 0;
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);

	return 0;
}

int createTable(const char* s)
{
	sqlite3 *DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS DOOR("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"TIME      TEXT NOT NULL, "
		"DOOR_STATE    INT NOT NULL, "
		"IMAGE       TEXT  NOT NULL);";


	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

	return 0;
}

int insertData(const char* s)
{
	sqlite3* DB;
	string line,encoded;
	ifstream input("Image-1.jpg",ios::in | ios:: binary);
	//ofstream output("text.txt");	

	time_t now = time(0);
	char* sec = ctime(&now);
	
	if (input.is_open()) {
		while (getline(input, line)) {
			 encoded = base64_encode(reinterpret_cast<const unsigned char*>(line.c_str()), line.length());
			//output << encoded;
		}
		input.close();
	}
	
	char* messageError;
	Door d1(sec,1,encoded);
    string st = "INSERT INTO DOOR (TIME, DOOR_STATE, IMAGE) VALUES('"+d1.getTimeStamp()+"', "+to_string(d1.getDoorStatus())+", '"+d1.getImage()+"');";
	string sql(st);
	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in insertData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records inserted Successfully!" << endl;
	
	return 0;
}

int selectData(const char* s)
{
	sqlite3* DB;
	char* messageError;

	string sql = "SELECT * FROM DOOR;";

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error in selectData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records selected Successfully!" << endl;

	return 0;
}

// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		// column name and value
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;

	return 0;
}
