#include "Loader.h"

#include <iostream>
#include <sstream>

Loader::Loader() :m_file(nullptr)
{

}

Loader::~Loader()
{
    if (m_file)
        this->CloseFile();
}

bool Loader::OpenFile(std::string _name)
{
    if (m_file)
    {
        std::cout << "A file is already open!" << std::endl;
        return true;
    }

    this->m_file = new std::fstream(_name.c_str());
    if (this->m_file->is_open())
    {
        std::cout << _name << " has successfully been opened!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Failed to open file " << _name << "!" << std::endl;
        delete m_file;
        m_file = nullptr;
    }
    return false;
}

bool Loader::LoadData(std::string _name)
{
    std::cout << "<Loader Output>" << std::endl;
    if (!this->OpenFile(_name))
        return false;

    int i = 0;
    for (std::vector<std::string>::iterator it = this->m_file_data.begin(); it != this->m_file_data.end(); ++i, ++it)
    {
        *m_file << *it;
    }
    std::cout << i << " rows of data written into file " << _name << "!" << std::endl;


    if (this->CloseFile())
    {
        std::cout << "<Loader Output END>" << std::endl;
        return true;
    }

    return false;
}

bool Loader::WriteData(std::string _name)
{
    std::cout << "<Writer Output>" << std::endl;
    if (!this->OpenFile(_name))
        return false;



    if (this->CloseFile())
    {
        std::cout << "<Loader Output END>" << std::endl;
        return true;
    }

    return false;
}

bool Loader::CloseFile()
{
    if (!m_file || !m_file->is_open())
    {
        std::cout << "No file is currently open!" << std::endl;
        return true;
    }

    this->m_file->close();
    std::cout << "File has successfully closed!" << std::endl;
    delete m_file;
    m_file = nullptr;
    if (!this->m_file)
        return true;

    std::cout << "File failed to close!" << std::endl;
    return false;
}

std::vector<std::string> Loader::GetData()
{
    return this->m_file_data;
}

void Loader::SetData(std::vector<std::string> _data)
{
    this->m_file_data = _data;
}
