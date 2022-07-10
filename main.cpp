#include <QApplication>
#include <QPushButton>
#include <QDebug>

#include "database.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	DatabaseManager databaseManager;
	databaseManager.connectDatabase();
	databaseManager.createDatabase();
	databaseManager.createTable();
	databaseManager.setTableHeader();
	databaseManager.insertData();
	databaseManager.selectData();


	return 0;
}
