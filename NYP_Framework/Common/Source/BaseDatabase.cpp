#include "BaseDatabase.h"

bool BaseDatabase::LoadDatabase(const std::string& filepath)
{
	if (filepath.empty())
		return false;

	if (this->db)
		this->EmptyDatabase();

	if (!sqlite3_open(filepath.c_str(), &this->db))
		return true;
	else
		return false;
}

bool BaseDatabase::EmptyDatabase()
{
	if (!db)
		return true;

	if (sqlite3_close(this->db))
		return true;
	else 
		return false;
}
