/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Project 2 B
This fetches stuff from arrays
*/
#include <iostream>
#include <fstream>
using namespace std;
int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size 
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names', 
                          'g_song_durations', 'g_genres'
*/
void allocateNew(){
    string *bigger_g_song_names = new string[2*g_curr_size];
    string *bigger_g_artist_names = new string[2*g_curr_size];
    int *bigger_g_song_durations = new int[2*g_curr_size];
    string *bigger_g_genres = new string[2*g_curr_size];
    for(int i =0; i<g_curr_size; i++){
        bigger_g_song_names[i] = g_song_names[i];
        bigger_g_artist_names[i] = g_artist_names[i];
        bigger_g_song_durations[i] = g_song_durations[i];
        bigger_g_genres[i] = g_genres[i];
    }
    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;
    g_song_names = bigger_g_song_names;
    g_artist_names = bigger_g_artist_names;
    g_song_durations = bigger_g_song_durations;
    g_genres = bigger_g_genres;
    g_curr_size = 2*g_curr_size;
}
/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the global-arrays and set the 
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate 
                          an array of larger size if the 
                          dynamic arrays reach full 
                          capacity.
*/
void readSongs(string filename){
    ifstream fin(filename);
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    string junk, song, artist, genre, duration;
    while(getline(fin, song, ':')){
        if(song.length() == 1){
            continue;
        }else{
        g_song_names[g_number_of_songs] = song;
        getline(fin, artist, '-');
        g_artist_names[g_number_of_songs] = artist;
        getline(fin, genre, '-');
        g_genres[g_number_of_songs] = genre;
        getline(fin, duration, ' ');
        g_song_durations[g_number_of_songs] = stoi(duration);
        g_number_of_songs++;
        if(g_number_of_songs >= g_curr_size){
            allocateNew();
        }
        getline(fin, junk);
        }
    }
    fin.close();
}

/*
    @param genre              :   A string representing a genre
    @param(&) genreCount      :   An integer that will keep track of the number of songs
    @return                   :   A pointer to a dynamically allocated array of strings 
    @post                     :   Return a pointer to a dynamically allocated array of strings
                                  containing the names of the songs of given 'genre' and 
                                  update 'genreCount' to be the number of songs found.
                                  Return a pointer to an empty dynamically allocated array
                                  if no songs are found of the given 'genre'
    
    For example : Let's say we have the following 'g_song_names':
                  ["Killshot", "Takeover", "Spectre", "Ether", "No Title"]
                  
                  Let's say we have the following 'g_genres':
                  ["HipHop", "HipHop", "EDM", "HipHop", "JPop"]
                  
                  We try the following code with the above global-arrays:
                  int main(){
                    int count = 0;
                    string * genreSongs = getGenreSongs("HipHop", count);
                  }

                  In this case, 'genreSongs' will be pointing to the following:
                  ["Killshot", "Takeover", "Ether"]
                  The value of 'count' will be updated to 3 because there
                  are three "HipHop" songs on the playlist 
*/
string * getGenreSongs(string genre, int &genreCount){
    int index = 0;
    genreCount = 0;
    string *genreSongs = new string[g_number_of_songs];
    for (int i = 0; i<g_number_of_songs; i++){
        if (g_genres[i] == genre){
            genreCount ++;
            genreSongs[index] = g_song_names[i];
            index ++;
        }
    }
    return genreSongs;
}

/*
    @param duration             :   The integer duration of the songs
    @param(&) durationsCount    :   An integer that will keep track of the number of songs
    @param filter               :   An integer(0, 1 or 2) representing the comparision filter
                                    0 = greater-than, 1 = less-than, 2 = equal-to
    @return                     :   A pointer to a dynamically allocated array of strings 
    @post                       :   Return a pointer to a dynamically allocated array of strings
                                    of songs that are either greater-than, less-than or equal-to
                                    the given 'duration' based on given 'filter'. Update parameter
                                    'durationsCount' with the number of songs found. Return a 
                                    pointer to an empty dynamically allocated array if no songs
                                    are found with the given parameters

    For example : Let's say we have the following 'g_song_names':
                  ["Major Crimes", "Never Fade Away", "Circus Minimus", "4aem", "Reaktion"]

                  Let's say we have the following 'g_song_durations':
                  [3, 4, 3, 5, 2]

                  We try the following code with the above global-arrays:
                  int main(){
                    int greater = 0;
                    int less = 0;
                    int equal = 0;
                    string * longSongs = getSongsFromDuration(3, greater, 0);
                    string * shortSongs = getSongsFromDuration(3, less, 1);
                    string * mediumSongs = getSongsFromDuration(3, equal, 2);
                  }

                  After running the above code, 'longSongs' will be:
                  ["Never Fade Away", "4aem"]
                  The value of 'greater' will be 2 because there are two songs 
                  greater than 3 mins duration

                  Similarly, 'shortSongs' will be:
                  ["Reaktion"]
                  The value of 'less' will be 1 because there is only one song 
                  less than 3 mins duration

                  Finally, 'mediumSongs' will be:
                  ["Major Crimes", "Circus Minimus"]
                  The value of 'equal' will be 2 because there are 2 songs
                  equal to 3 mins duration      
*/
string * getSongsFromDuration(int duration, int &durationsCount, int filter){
    int index = 0;
    durationsCount = 0;
    string * result = new string[g_number_of_songs];
    if(filter == 0){
        for(int i = 0; i<g_number_of_songs; i++){
            if(g_song_durations[i] > duration){
                durationsCount ++;
                result[index] = g_song_names[i];
                index ++;
            }
        }
    }else if(filter == 1){
        for(int i = 0; i<g_number_of_songs; i++){
            if(g_song_durations[i] < duration){
                durationsCount++;
                result[index] = g_song_names[i];
                index ++;
            }
        }
    }else{
        for(int i = 0; i<g_number_of_songs; i++){
            if(g_song_durations[i] == duration){
                durationsCount++;
                result[index] = g_song_names[i];
                index ++;
            }
        }
    }  
    return result;
}

/*
    @param      :   An integer that will keep track of unique artists
    @return     :   A pointer to a dynamically allocated array of strings 
    @post       :   Return a pointer to a dynamically allocated array of strings
                    containing the names of unique artists in 'g_artist_names'
                    and update 'uniqueCount' parameter to be the number of
                    unique artists found
    
    For example : Let's say we have the following 'g_artist_names':
                  ["Eminem", "Eminem", "Jay Z", "Jay Z", "Nas"]
                  
                  We try the following code with this 'g_artist_names':
                  int main(){
                    int count = 0;
                    string * uniques = getUniqueArtists(count);
                  }

                  In this case, 'uniques' will be pointing to the following:
                  ["Eminem", "Jay Z", "Nas"]
                  The value of 'count' will be updated to 3 because there
                  are three unique artists on the playlist     
*/
string * getUniqueArtists(int &uniqueCount){
    uniqueCount = 0;
    std::string *result = new std::string[g_number_of_songs];
    for (int i = 0; i < g_number_of_songs; i++){
        int j = 0;
        for (j; j < i; j++){
            if (g_artist_names[i] == g_artist_names[j]){
                break;
            }
        }
        if (i == j){
            result[j] = g_artist_names[i];
            uniqueCount++;
        }
    }
    return result;
}

/* 
    @return     :   A string with the artist with most songs in playlist
    @post       :   Find the artist with the most songs in the playlist
                    If there are multiple such artists, return any one of them.
                    Return "NONE" if the playlist is empty

    For example : Let's say we have the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Kendrick"]
                  The favorite artist here is "Kendrick" because he has 3 songs
                  However, consider the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Drake"]
                  In this case, the favorite artist is either "J.Cole" or "Kendrick"
                  because both artists have 2 songs which is greater than any 
                  other artists in the playlist
*/
string getFavoriteArtist(){
    string fave;
    int tally = 0;
    int topTally = 0;
    if (g_number_of_songs == 0){
        fave = "NONE";
    }else{
        for (int i = 0; i < g_number_of_songs; i++){
            for (int j = 0; j < g_number_of_songs; j++){
                if (g_artist_names[i] == g_artist_names[j]){
                    tally++;
                }
            }
            if (topTally < tally){
                topTally = tally;
                fave = g_artist_names[i];
            }
            tally = 0;
        }
    }
    return fave;
}