#include <stdafx.h>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <exception>
using namespace std;
char* username;
char* password;
char* url;
char* driver;
char* querycount;
char* querysql;
char* _sql_querycount;
char* _sql_segmentquery;
const char REM = '#';
const char* EQ_REM = "=";
const char* _URL_STR = "url";
const char* _USERNAME_STR = "username";
const char* _PASSWORD_STR = "userpassword";
const char* _JDBC_DRIVEN_STR = "jdbcdriver";
const char* _PUBLIC_QUERY_SQL = "publicCount";
const char* _SEGMENT_QUERY_SQL = "jdbc.query.sql";
extern "C" void _parse() 
{
	ifstream inf;
	inf.open("config/jdbc.properties");
	if (!inf.is_open()) cout << "open inputstram fail" << endl;
	char* buffer = new char[4096];
	while (!inf.eof())
	{
		inf.getline(buffer, 1024);
		char* target = strchr(buffer, REM);
		if (target == NULL) {
			//cout << buffer << endl;
			char* str = NULL;
			try {
				if (strstr(buffer, _USERNAME_STR))
				{
					strtok(buffer, EQ_REM);
					username = strtok(NULL, EQ_REM);
					printf("username %s\n", username);
				}
				else if (strstr(buffer, _PASSWORD_STR))
				{
					strtok(buffer, EQ_REM);
					password = strtok(NULL, EQ_REM);
					printf("password %s\n", password);
				}
				else if (strstr(buffer, _URL_STR)) {
					strtok(buffer, EQ_REM);
					url = strtok(NULL, EQ_REM);
					printf("url %s\n", url);
				}
				else if (strstr(buffer, _JDBC_DRIVEN_STR))
				{
					strtok(buffer, EQ_REM);
					driver = strtok(NULL, EQ_REM);
					printf("driver %s\n", driver);
				}
				else if (strstr(buffer, _PUBLIC_QUERY_SQL))
				{
					strtok(buffer, EQ_REM);
					querycount = strtok(NULL, EQ_REM);
					printf("querycount %s\n", querycount);
				}
				else if (strstr(buffer, _SEGMENT_QUERY_SQL))
				{
					strtok(buffer, EQ_REM);
					querysql = strtok(NULL, EQ_REM);
					printf("querysql %s\n", querysql);
				}
			}
			catch (exception &e)
			{
				cout << "cause error" << e.what() << endl;
			}
		}

	}
	inf.close();
}