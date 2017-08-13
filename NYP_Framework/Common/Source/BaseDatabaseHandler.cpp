#include "BaseDatabaseHandler.h"

#include <stdarg.h>

bool BaseDatabaseHandler::LoadDatabase(const std::string& filepath)
{
	if (filepath.empty())
		return false;

	if (this->m_db)
		this->EmptyDatabase();

	if (sqlite3_open_v2(filepath.c_str(), &this->m_db, SQLITE_OPEN_READWRITE, NULL) == SQLITE_OK)
		return true;
	else
		return false;
}

bool BaseDatabaseHandler::EmptyDatabase()
{
	if (!m_db)
		return true;

	if (sqlite3_close_v2(this->m_db) == SQLITE_OK)
		return true;
	else
		return false;
}

bool BaseDatabaseHandler::ExecuteQuery(const std::string query, ...)
{
    sqlite3_stmt* st;
    std::string sql_command = this->m_query.str();
    sqlite3_prepare_v2(this->m_db, sql_command.c_str(), -1, &st, NULL);
    int cols = sqlite3_column_count(st);
    int result = 0;

    va_list vl;
    va_start(vl, query);

    while (true)
    {
        result = sqlite3_step(st);

        if (result == SQLITE_ROW)
        {
            std::stringstream sst;
            for (int col = 0; col < cols; col++)
            {
                std::string s = (char*)sqlite3_column_text(st, col);
                sst << s;
                if (col < cols - 1)
                    sst << ",";
            }
            this->m_return.push_back(sst.str());
        }
        else
        {
            break;
        }
    }
    sqlite3_finalize(st);

    return false;
}