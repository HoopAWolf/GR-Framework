#include "Editor.h"

#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

Editor::Editor() : textData(""), fileExist(false)
{
}

Editor::~Editor()
{
}

void Editor::startWriting(void)
{
	string textFileName = "";

	cout << "Please enter the text file name: ";
	getline(cin, textFileName);
	/*Check if .txt extension was added, if not, add to string.*/
	bool addExtension = true;
	for (unsigned i = 0; i < textFileName.length(); ++i)
	{
		if (textFileName[i] == '.')
		{
			if ((i + 3) < textFileName.length())
			{
				if (textFileName[i + 1] == 't' && textFileName[i + 2] == 'x' && textFileName[i + 3] == 't' && (i + 4) == textFileName.length())
				{
					addExtension = false;
					break;
				}
			}
		}
	}

	textFileName = addExtension ? textFileName +".txt" : textFileName + "";

	cout << "Enter the content you want to input (0 to exit): ";

	while (true)
	{
		string textInput = "";
		getline(cin, textInput);

		if (textInput == "0")
		{
			break;
		}

		this->writeToText(textFileName, textInput);
	}
}

void Editor::startLoading(void)
{
	string textFileName = "";

	cout << "Please enter the text file name: ";
	getline(cin, textFileName);

	/*Check if .txt extension was added, if not, add to string.*/
	bool addExtension = true;
	for (unsigned i = 0; i < textFileName.length(); ++i)
	{
		if (textFileName[i] == '.')
		{
			if ((i + 3) < textFileName.length())
			{
				if (textFileName[i + 1] == 't' && textFileName[i + 2] == 'x' && textFileName[i + 3] == 't' && (i + 4) == textFileName.length())
				{
					addExtension = false;
					break;
				}
			}
		}
	}

	textFileName = addExtension ? textFileName + ".txt" : textFileName + "";

	ifstream textFile(textFileName);
	if (textFile)
	{
		this->setFileExist(true);
	}
	else if (this->getFileExist())
		this->setFileExist(false);

	
	if (this->getFileExist())
	{
		string str;
		string textFileContents;
		while (std::getline(textFile, str))
		{
			textFileContents += str;
			textFileContents.push_back('\n');
		}
		this->setText(textFileContents);
	}
	else
		cout << "File does not exist." << endl;
}

void Editor::startDeleting(void)
{
	string textFileName = "";

	cout << "Please enter the text file name to delete: ";
	getline(cin, textFileName);

	/*Check if .txt extension was added, if not, add to string.*/
	bool addExtension = true;
	for (unsigned i = 0; i < textFileName.length(); ++i)
	{
		if (textFileName[i] == '.')
		{
			if ((i + 3) < textFileName.length())
			{
				if (textFileName[i + 1] == 't' && textFileName[i + 2] == 'x' && textFileName[i + 3] == 't' && (i + 4) == textFileName.length())
				{
					addExtension = false;
					break;
				}
			}
		}
	}

	textFileName = addExtension ? textFileName + ".txt" : textFileName + "";

	if (remove(textFileName.c_str()) != 0)
		perror("Error: ");
	else
		puts("File successfully deleted.");
}

void Editor::writeToText(string fileName, string text)
{
	ofstream myFile;
	/*Append to an existing file/create a new file for writing: 
	If a file with the same name already exists, append data at the end of the file. 
	If it does not exist, create a new empty text file.*/

	myFile.open(fileName, ios::app);
	myFile << text << endl;;
	myFile.close();
}

void Editor::loadText(void)
{
	cout << this->textData;
}

string Editor::getText(void)
{
	return this->textData;
}

bool Editor::getFileExist(void)
{
	return this->fileExist;
}

void Editor::setText(string data)
{
	this->textData = data;
}

void Editor::setFileExist(bool data)
{
	this->fileExist = data;
}

void Editor::deleteTextFile(string fileName)
{
}
