#pragma once
#include "Solutions^^.h"
class Film
{
	string name;
	int Date;
	vector<string> genre;
	int genreL;
	string Author;
	string description;
public:
	string get_name() { return name; }
	int get_date() { return Date; }
	vector<string> get_genre() { return genre; }
	int get_gL() { return genreL; }
	string get_AU() { return Author; }
	string get_desription() { return description; }
	Film input()
	{

		Film tmp;
		cinX(tmp.name, "Enter Film Name: ");
	ret1:cinX(tmp.Date, "Enter date: ", '+');
		if (tmp.Date < 1950 || tmp.Date > 2022)
		{
			cout << "Wrong Date, try again." << endl;
			system("pause");
			system("cls");
			goto ret1;
		}
	ret2:cinX(tmp.genreL, "Enter genre amount(1-3): ", '+');
		if (tmp.genreL > 3)
		{
			cout << "Pls, enter amount 1-3, try again." << endl;
			system("pause");
			system("cls");
			goto ret2;
		}
		tmp.genre.resize(tmp.genreL);
		for (int i = 0; i < tmp.genreL; i++)
		{
			cinX(tmp.genre[i], "Enter genre: ");
		}
		cinX(tmp.Author, "Enter Author: ");
		cinX(tmp.description, "Enter small desription: ");
		return tmp;

	}
	vector<Film> Add(vector<Film> FilmBook)
	{

		FilmBook.resize(FilmBook.size() + 1);
		FilmBook[FilmBook.size() - 1] = input();
		return FilmBook;

	}
	void Show(Film tmp)
	{
		cout << "Name: [" << tmp.name << "]" << endl;
		cout << "Author: [" << tmp.Author << "]" << endl;
		cout << "Date: [" << tmp.Date << "]" << endl;
		cout << "Genre: [ ";
		for (int i = 0; i < tmp.genre.size(); i++)
		{
			cout << tmp.genre[i] << " ";
		}
		cout << "]" << endl;
		cout << "Description: [" << tmp.description << "]" << endl;
	}
	void Print(vector<Film> FilmBook)
	{
		for (int i = 0; i < FilmBook.size(); i++)
		{
			Show(FilmBook[i]);
			cout << "\n";
		}
	}
	vector<Film> Delete(vector<Film> Book)
	{
		int pos;
		cout << "You have: " << Book.size() << " films(aviable positions 0-" << Book.size() - 1 << ")" << endl;
	ret3:cinX(pos, "Enter position which you wanna delete: ", 'o');
		if (pos >= Book.size())
		{
			cout << "Out of range, try again" << endl;
			system("pause");
			system("cls");
			goto ret3;
		}
		Book.erase(Book.begin() + pos);
		return Book;
	}
	vector<Film> Redact(vector<Film> Book)
	{
		int pos;
	ret4:cinX(pos, "Enter position which you wanna edit: ", 'o');
		if (pos >= Book.size())
		{
			cout << "Out of range, try again" << endl;
			system("pause");
			system("cls");
			goto ret4;
		}
		Book[pos] = input();
		return Book;
	}
};