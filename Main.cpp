#include "Solutions.cpp"
#include "Class Film.cpp"
#include "Class File.cpp"
int main()
{
	Film F;
	File F2;
	vector<Film> FilmBook;
	ofstream out("Data.txt");
	out.close();
	thread t99([&]()//rewriting file every 30 seconds <- alternative of: �������� ����� ������� ����� ����������� ������ 30 ������ � ��������� ��������� � ����� � ���� ��� �� ���� ��������� ��������� ����
	{
		while (true)
		{
			F2.InFile(FilmBook);
			this_thread::sleep_for(chrono::milliseconds(30000));
		}
	});
	t99.detach();
	char ch;
	do
	{
		system("cls");
		cout << "FilBook" << endl;
		cout << "1.Add Film" << endl;
		cout << "2.Delete Film " << endl;
		cout << "3.Edit Film" << endl;
		cout << "4.Print" << endl;
		ch = _getch();
		switch (ch)
		{
		case'1':
		{
			thread t1([&]() {
				FilmBook = F.Add(FilmBook);
				});
			t1.join();
		}
		break;
		case'2':
		{
			if (FilmBook.size() != 0)
			{
				thread t2([&]() {
					FilmBook = F.Delete(FilmBook);
					cout << "Your Film was successfully deleted" << endl;
					system("pause");
					});
				t2.join();
			}
			else
			{
				cout << "You can't use this function, 'cause you don't have any Films" << endl;
				system("pause");
			}
			

		}
		break;
		case'3':
		{
			if (FilmBook.size() != 0)
			{
				thread t3([&]() {
					FilmBook = F.Redact(FilmBook);
					});
				t3.join();
			}
			else
			{
				cout << "You can't use this function, 'cause you don't have any Films" << endl;
				system("pause");
			}
		}
		break;
		case'4':
		{
			if (FilmBook.size() != 0)
			{
				thread t4([&]() {
					F.Print(FilmBook);
					});
				system("pause");
				t4.join();
			}
			else
			{
				cout << "You can't use this function, 'cause you don't have any Films" << endl;
				system("pause");
			}

		}
		break;
		}
	} while (ch != 27);
	
}