#ifndef _BASE_DATABASE_H
#define _BASE_DATABASE_H

#include <string>
#include <map>

template <class Object>
class BaseDatabase
{
protected:
	const std::string k_name, k_filePath;
    std::map<int, Object*> m_database;
public:
	BaseDatabase(const std::string& name,const std::string& filePath);
	~BaseDatabase();
	void init();
	Object* getObject(int id);
};

#endif