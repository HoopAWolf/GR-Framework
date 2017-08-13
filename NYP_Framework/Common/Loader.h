#ifndef _LOADER_H
#define _LOADER_H

#include <fstream>
#include <string.h>
#include <vector>
#include "Source\SingletonTemplate.h"

class Loader: public Singleton<Loader>
{
    friend Singleton <Loader>;
private:
    std::fstream* m_file;
    std::vector<std::string> m_file_data;
    Loader();
    ~Loader();

    bool OpenFile(std::string _name);
    bool CloseFile();

public:
    /*   
    Calling this function puts each line of a text file into a string vector.
    Use GetData() to retreive the data.
    */
    bool LoadData(std::string _name);

    /*
    Calling this function puts selected data into the text file.
    Use SetData() to set write data.
    */
    bool WriteData(std::string _name);

    std::vector<std::string> GetData();
    void SetData(std::vector<std::string> _data);
};

#endif