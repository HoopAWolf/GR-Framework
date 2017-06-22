#ifndef _BASE_DATABASE_H
#define _BASE_DATABASE_H

#include "sqlite3.h"

#include <string>

class BaseDatabase
{
protected:
	sqlite3* m_db;
	std::string m_query;
public:
	bool LoadDatabase(const std::string& filepath);
	bool EmptyDatabase();

	template<typename First, typename ... Strings>
	bool ExecuteQuery(First arg,const Strings&&... query);

	void GenerateQuery();

	template<typename First, typename ... Strings>
	void GenerateQuery(First arg, const Strings&&... query);
};

#endif