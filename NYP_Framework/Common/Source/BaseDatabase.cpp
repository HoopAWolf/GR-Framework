#include "BaseDatabase.h"
#include "Loader.h"

template <class Object>
BaseDatabase<Object>::BaseDatabase(const std::string& name, const std::string& filePath)
    :k_name(name),k_filePath(filePath)
{

}

template <class Object>
BaseDatabase<Object>::~BaseDatabase()
{

}

template <class Object>
void BaseDatabase<Object>::init()
{
	Loader::GetInstance()->LoadData(this->k_filePath);
	std::vector<std::string> data = Loader::GetInstance()->GetData();
	int i = 1;
	for (std::vector<std::string>::iterator it = data.begin();it != data.end();++it)
	{
		this->m_database[i] = new Object(*i);
	}
}

template <class Object>
Object* BaseDatabase<Object>::getObject(int id)
{
	return this->m_database[id];
}