#ifndef _BASE_DATABASE_H
#define _BASE_DATABASE_H

#include "sqlite3.h"

#include <string>

class BaseDatabase
{
protected:
	sqlite3* db;
public:
	bool LoadDatabase(const std::string& filepath);
	bool EmptyDatabase();
};

#endif