#pragma once
#include "Solutions^^.h"
#include "Class Film.cpp"
class File
{
public:

	void InFile(vector<Film> FilmBook)
	{

		ofstream out("Data.txt");
		if (!out.is_open())
		{
			cout << "File wasn't open :(" << endl;
			system("pause");
			return;
		}
		for (int i = 0; i < FilmBook.size(); i++)
		{
			out << "Name: " << FilmBook[i].get_name() << endl;
			out << "Author: " << FilmBook[i].get_AU() << endl;
			out << "Date: " << FilmBook[i].get_date() << endl;
			out << "Genre: ";
			for (int j = 0; j < FilmBook[i].get_genre().size(); j++)
			{
				out << FilmBook[i].get_genre()[j] << " ";
			}
			out << "\n";
			out << "Description: " << FilmBook[i].get_desription() << endl;
			out << "\n";
		}
	}
};