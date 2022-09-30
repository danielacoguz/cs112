/*
 * Application.cpp
 *
 *  Created on: Feb 14, 2020
 *      Author: vtn2
 */

#include "Application.h"

#include <iostream>
using namespace std;
#include "Song.h"
#include "PlayList.h"


Application::Application() {
	string fname;
	cout << "Welcome to the PlayList Manager" << endl << endl;
	cout << "Please enter a file containing a play list: " << flush;
	getline(cin, fname);
	myPlayList = PlayList(fname);
}

/*
 * Run the application.
 */
void Application::run() {
	while (true) {
		displayMenu();
		char choice = getChoice();
		// cout << "got choice " << choice << endl;
		if (choice == 'q') {
			break;
		}
		processChoice(choice);
	}
}

void Application::displayMenu() const {
	cout << "Please enter:" << endl;
	cout << "a - to add a new song to the playlist" << endl;
	cout << "r - to remove a song from the playlist" << endl;
	cout << "s - to save the playlist" << endl;
	cout << "A - to search the playlist for songs by a given artist" << endl;
	cout << "Y - to search the playlist for songs in a given year" << endl;
	cout << "P - to search the playlist for songs with a given phrase in the title" << endl;
	cout << "q - to quit" << endl;
}

char Application::getChoice() const {
	cout << endl << "Please enter your choice: " << flush;
	char choice;
	cin >> choice;
	cin.get();
	return choice;
}

Song Application::getSong() {
	string artist;
	string title;
	unsigned year;
	string yearStr;

	cout << "  Enter artist: ";
	getline(cin, artist);
	cout << "  Enter title: ";
	getline(cin, title);
	cout << "  Enter year: ";
	cin >> year;
    cin.get();
	return Song(title, artist, year);
}

void Application::processChoice(char choice) {
	switch(choice) {
	case 'a': {
		cout << "Add an song to the playlist..." << endl;
        // TODO
		break;
	}
	case 's': {
		myPlayList.save();
		break;
	}
	case 'r': {
		cout << "Remove a song from the playlist..." << endl;
		// TODO
		break;
	}
	case 'Y': {
		cout << "Searching playlist by year..." << endl;
		unsigned year;
		cout << "Enter year: ";
		cin >> year;
		cin.get();
        vector<Song> songs;
		songs = myPlayList.searchByYear(year);

		displaySongs(songs);
		break;
	}
	case 'P': {
		cout << "Searching playlist by title phrase..." << endl;
		string phrase;
		cout << "Enter phrase: ";
		cin >> phrase;
        vector<Song> songs;
		songs = myPlayList.SearchByTitlePhrase(phrase);

		displaySongs(songs);
		break;
	}
	case 'A': {
		cout << "Searching playlist by artist..." << endl;
		string artist;
		cout << "Enter artist: ";
		cin >> artist;
        // TODO
		vector<Song> songs;
		songs = myPlayList.searchByArtist(artist);

		displaySongs(songs);
		break;
	}
	}
}

void Application::displaySongs(vector<Song> songs) const {
    // TODO: call writeTo on each song, passing in cout.
}

