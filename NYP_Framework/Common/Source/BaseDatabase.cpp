#include "BaseDatabase.h"

bool BaseDatabase::LoadDatabase(const std::string& filepath)
{
	if (filepath.empty())
		return false;

	if (this->m_db)
		this->EmptyDatabase();

	if (sqlite3_open(filepath.c_str(), &this->m_db) == SQLITE_OK)
		return true;
	else
		return false;
}

bool BaseDatabase::EmptyDatabase()
{
	if (!m_db)
		return true;

	if (sqlite3_close(this->m_db) == SQLITE_OK)
		return true;
	else 
		return false;
}

template<typename First, typename ... Strings>
bool BaseDatabase::ExecuteQuery(First arg, const Strings&&... query)
{
	this->GenerateQuery(arg, query);
	sqlite3_stmt sqlstmt;
	sqlite3_prepare(&this->m_db,this->m_query.c_str())
}

void BaseDatabase::GenerateQuery()
{
	this->m_query.append(";");
}

template<typename First, typename ... Strings>
void BaseDatabase::GenerateQuery(First arg, const Strings&&... query)
{
	this->m_query.append(arg);
	GenerateQuery(query...);
}
