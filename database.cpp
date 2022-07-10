//
// Created by yzxing on 7/10/2022.
//

#include <QMessageBox>
#include "database.h"

DatabaseManager::DatabaseManager() {

}

bool DatabaseManager::connectDatabase() {
	QSqlError err;
	// 数据库对象创建
	sql = QSqlDatabase::addDatabase("QMYSQL", "testConnect");
	// 设置相关参数
	sql.setHostName("localhost");    // 主机名(地址)
	sql.setPort(3306);        // 端口
	sql.setUserName("root");              //用户名
	sql.setPassword("123456");            //密码
	sql.open();
	//测试连接
	if (!sql.open()) {
		qDebug() << "不能连接" << "connect to mysql error" << sql.lastError().text();
		return false;
	} else {
		qDebug() << "连接成功" << "connect to mysql OK";
		return true;
	}
}

bool DatabaseManager::createDatabase() {
	//**********创建数据库
	sql = QSqlDatabase::database("testConnect");
	querystring = "CREATE DATABASE IF NOT EXISTS operatesql";
	sql.exec(querystring);
	if (sql.lastError().isValid()) {
		qDebug() << sql.lastError();
		qDebug() << "Create database failed.";
		return false;
	} else {
		qDebug() << "Create database successfully.";
	}

	QMessageBox::information(nullptr, "Warning", "Create Successful");
	return true;
}

bool DatabaseManager::createTable() {
	//**********创建数据表
	sql = QSqlDatabase::database("testConnect");
	sql.setDatabaseName("operatesql");
	if (!sql.open()) {
		qDebug() << "open failed";
		return false;
	} else {
		qDebug() << "create succeeded";
	}
	return true;
}

void DatabaseManager::setTableHeader() {
	querystring =
			"CREATE TABLE IF NOT EXISTS operatesql.test\
    (\
    name varchar(255),\
    cls varchar(255),\
    age int,\
    height int\
    )";
	sql.exec(querystring);
	if (sql.lastError().isValid()) {
		qDebug() << sql.lastError();
		qDebug() << "set table header failed.";
		return;
	} else {
		qDebug() << "set table header successfully.";
	}
	QMessageBox::information(nullptr, "Warning", "Create Successful");
}

void DatabaseManager::insertData() {
	TableInfo tableInfo;
	QSqlQuery qSqlQuery;
	QString sqlText = "insert into test(name,cls,age,height) values('name', 'cls', 20, 20)";
	sql.exec(sqlText);
	if (sql.lastError().isValid()) {
		qDebug() << sql.lastError();
		qDebug() << "insertData failed.";
		return;
	} else {
		qDebug() << "insertData successfully.";
	}
}

void DatabaseManager::selectData() {
	QString sqlText = "select * from test";
	QSqlQuery query = sql.exec(sqlText);
	while(query.next()){
		//取出并打印值
		qDebug() << query.value("name").toString()
		         << query.value("cls").toString()
		         << query.value("age").toInt()
		         << query.value("height").toInt();
	}
}
