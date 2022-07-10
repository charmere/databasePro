//
// Created by yzxing on 7/10/2022.
//

#ifndef DATABASEPRO_DATABASE_H
#define DATABASEPRO_DATABASE_H

#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlError>

class DatabaseManager {
public:
	struct TableInfo {
		QString name;
		QString cls;
		int age;
		int height;
	};

	explicit DatabaseManager();

	bool connectDatabase();

	bool createDatabase();

	bool createTable();

	void setTableHeader();

	void insertData();

	void selectData();

private:
	QSqlDatabase sql;
	QString querystring;
};

#endif //DATABASEPRO_DATABASE_H
