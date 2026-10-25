#include <iostream> 
#include <string>
using namespace std;
class Audio
{
public:
	virtual void Play()
	{
		cout << "Playing audio" << "\n";
	}
	virtual~Audio() {}
};
class Song : public Audio {
private:
	string title;
	string artist;
public:
	Song(string title, string artist)
	{
		this->title = title;
		this->artist = artist;
	}
	void Play() override
	{
		cout << "Playing song: " << title << " by " << artist << '\n';
	}
};
class Audiobook :public Audio {
private:
	string bookTitle;
	string author;
	string voice;
public:
	Audiobook(string bookTitle, string author, string voice)
	{
		this->bookTitle = bookTitle;
		this->author = author; this->voice = voice;
	}
	void Play() override
	{
		cout << "Listening to audiobook: " << bookTitle
			<< " by " << author
			<< ". Read by " << voice << '\n';
	}
};
int main() {
	int choice;
	cout << "Оберіть тип аудіо:" << endl;
	cout << "1. Song" << endl;
	cout << "2. Podcast" << endl;
	cout << "3. Audiobook" << endl;
	cout << "> ";
	cin >> choice;

	Audio* audio = nullptr;

	if (choice == 1)
	{
		string title, artist;

		cout << "Введіть назву пісні: ";
		cin.ignore();
		getline(cin, title);

		cout << "Введіть виконавця: ";
		getline(cin, artist);

		audio = new Song(title, artist);
	}
	else if (choice == 2)
	{
		string host, topic;

		cout << "Введіть ведучого: ";
		cin.ignore();
		getline(cin, host);

		cout << "Введіть тему: ";
		getline(cin, topic);

		audio = new Podcast(host, topic);
	}
	else if (choice == 3)
	{
		string bookTitle, author, voice;

		cout << "Введіть назву книги: ";
		cin.ignore();
		getline(cin, bookTitle);

		cout << "Введіть автора: ";
		getline(cin, author);

		cout << "Введіть голос: ";
		getline(cin, voice);

		audio = new Audiobook(bookTitle, author, voice);
	}
	else
	{
		cout << "Невірний вибір!" << endl;
		return 0;
	}

	audio->Play();

	delete audio;

};