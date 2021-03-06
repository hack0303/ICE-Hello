// ICE-Hello.cpp: 定义控制台应用程序的入口点。
//
#include <stdafx.h>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <exception>
#include <jdbc/cppconn/connection.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/sqlstring.h>
using namespace sql;
using namespace std;
extern "C" void _parse();
extern char* username;
extern char* password;
extern char* url;
extern char* querycount;
int main()
{
	Driver* driver;
	Connection* conn;
	Statement* stmt;
	ResultSet* rst;
	_parse();//解析参数
	driver = get_driver_instance();
	conn = driver->connect(url,username,password);
	stmt = conn->createStatement();
	rst = stmt->executeQuery(querycount);
	while (rst->next()) 
	{
		cout << "count:" + rst->getInt(1) << endl;
	}
	rst->close();
	stmt->close();
	conn->close();
	system("pause");
    return 0;
}

