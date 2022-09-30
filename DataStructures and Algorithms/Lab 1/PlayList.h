/* PlayList.h declares class PlayList.
 * Student 1 Name and Username:Daniela Contreras
 * Date: 09/07/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include "Song.h"
#include <vector>   // STL vector

#include <string>
using namespace std;

class PlayList {
public:
	PlayList();
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song>searchByYear(unsigned year) const;
	vector<Song> searchByArtist(const string& artist) const;
	vector<Song>SearchByTitlePhrase(const string & phrase) const;
	void addSong(const Song & newSong);
	void removeSong(const Song & song);
	void save();
private:
	vector<Song> mySongs;
};

#endif /*PLAYLIST_H_*/
