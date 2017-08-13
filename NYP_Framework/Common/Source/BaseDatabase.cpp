#include "BaseDatabase.h"
#include "BaseDatabaseHandler.h"

template <class Object>
BaseDatabase<Object>::BaseDatabase(const std::string& name, const std::string& filePath, const std::string& tableName)
    :k_name(name),k_filePath(filePath),k_tableName(tableName)
{

}

template <class Object>
BaseDatabase<Object>::~BaseDatabase()
{

}

template <class Object>
void BaseDatabase<Object>::init()
{
    BaseDatabaseHandler* dbHandler = BaseDatabaseHandler::GetInstance();
    dbHandler->LoadDatabase(this->k_filePath);
    
}

template <class Object>
Object* BaseDatabase<Object>::getObject(int id)
{

}