/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Project 2 C
This uses classes to organize song information
*/

#include <iostream>
#include <fstream>
using namespace std;

class Song{
public:
    string name;
    string artist;
    int duration;
    string genre;
};


int g_capacity = 2;
int g_size = 0;

Song *g_songs = new Song[g_capacity];

/*
    @post             :   Replace the old global
                          dynamically allocated array
                          'g_songs' with new dynamically
                          allocated array of twice the 
                          capacity ('g_capacity' * 2). 
                          Update 'g_capacity' accordingly.
                          Make sure you copy the contents
                          of the old array to the new one.
*/
void allocateNew(){
    Song *bigger_g_songs = new Song[g_capacity*2];
    for(int i = 0; i<g_capacity; i++){
        bigger_g_songs[i] = g_songs[i];
    }
    delete[] g_songs;
    g_songs = bigger_g_songs;
    g_capacity = g_capacity*2;
}

/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the 'g_songs' and sets the 
                          value of 'g_size' to the number 
                          of songs read. Call 'allocateNew()' 
                          where necessary similar to Task A.
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
        g_songs[g_size].name = song;
        getline(fin, artist, '-');
        g_songs[g_size].artist = artist;
        getline(fin, genre, '-');
        g_songs[g_size].genre = genre;
        getline(fin, duration, ' ');
        g_songs[g_size].duration = stoi(duration);
        g_size++;
        if(g_size >= g_capacity){
            allocateNew();
        }
        getline(fin, junk);
        }
    }
    fin.close();
}

// Now returns a dynamic array of 'Song' objects instead of a 'string' objects
Song * getSongsFromDuration(int duration, int &durationsCount, int filter){
    int index = 0;
    durationsCount = 0;
    Song * result = new Song[g_size];
    for(int i = 0; i< g_size; i++){
        if(filter == 0){
            if(g_songs[i].duration > duration){
                durationsCount ++;
                result[index] = g_songs[i];
                index ++;
            }
        }else if(filter == 1){
            if(g_songs[i].duration < duration){
                durationsCount ++;
                result[index] = g_songs[i];
                index ++;
            }
        }else{
            if(g_songs[i].duration == duration){
                durationsCount ++;
                result[index] = g_songs[i];
                index ++;
            }
        }
    }  
    return result;
}
Song * getGenreSongs(string genre, int &genreCount){
    int index = 0;
    genreCount = 0;
    Song * result = new Song[g_capacity];
    for (int i = 0; i<g_capacity; i++){
        if (g_songs[i].genre == genre){
            genreCount++;
            result[index] = g_songs[i];
            index ++;
        }
    }
    return result;
}

// Change the implementation since we are using 'Song' class
string * getUniqueArtists(int &uniqueCount){
    uniqueCount = 0;
    string *result = new string[g_size];
    for (int i = 0; i < g_size; i++){
        int j = 0;
        for (j; j < i; j++){
            if (g_songs[i].artist == g_songs[j].artist){
                break;
            }
        }
        if (i == j){
            result[j] = g_songs[i].artist;
            uniqueCount++;
        }
    }
    return result;
}

string getFavoriteArtist(){
    string fave;
    int tally = 0;
    int topTally = 0;
    if (g_capacity == 0){
        fave = "NONE";
    }else{
        for (int i = 0; i < g_capacity; i++){
            for (int j = 0; j < g_capacity; j++){
                if (g_songs[i].artist == g_songs[j].artist){
                    tally++;
                }
            }
            if (topTally < tally){
                topTally = tally;
                fave = g_songs[i].artist;
            }
            tally = 0;
        }
    }
    return fave;
}

int main(){
    Song * genresongs;
    int count;
    readSongs("test.txt");
    genresongs = getSongsFromDuration(3,count,2);
    for(int i = 0; i < count; i++){
        cout<<genresongs[i].name<<endl;
    }
}