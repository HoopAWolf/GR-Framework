#ifndef _BASE_DATABASE_HANDLER_H
#define _BASE_DATABASE_HANDLER_H

#include "sqlite3.h"
#include "SingletonTemplate.h"

#include <sstream>
#include <string>
#include <iostream>
#include <vector>

class BaseDatabaseHandler:public Singleton<BaseDatabaseHandler>
{
    friend Singleton<BaseDatabaseHandler>;
protected:
    typedef std::vector<std::string> query;
	sqlite3* m_db;
	std::stringstream m_query;
    query m_return;
    
public:
	bool LoadDatabase(const std::string& filepath);
	bool EmptyDatabase();

    bool ExecuteQuery(const std::string query, ...);

	template<typename ... Strings>
	std::string GenerateQuery(const Strings&... query)
	{
		using List = int[];
		(void)List {
			0, ((void)(this->m_query << query), 0) ...
		};
		this->m_query << ";";
		std::cout << this->m_query.str() << std::endl;
	}

    query GetReturnedQuery() { return this->m_return; }
};

#endif