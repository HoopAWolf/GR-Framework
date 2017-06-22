#ifndef EDITOR_H
#define EDITOR_H

#include <string>

using std::string;

class Editor
{
public:
	Editor();
	~Editor();
	/*Start Functions*/
	void startWriting(void);
	void startLoading(void);
	void startDeleting(void);

	/*Write*/
	void writeToText(string fileName, string text);
	/*Load*/
	void loadText(void);
	/*Delete*/
	void deleteTextFile(string fileName);

	/*Getter for Text*/
	string getText(void);

	/*Getter for File Exist Status*/
	bool getFileExist(void);

	/*Setter for Text*/
	void setText(string data);

	/*Setter for File Exist Status*/
	void setFileExist(bool data);

private:
	string textData;
	bool fileExist;

protected:
};

#endif