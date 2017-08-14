#include "BaseDatabase.h"

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
    
}

template <class Object>
Object* BaseDatabase<Object>::getObject(int id)
{

}