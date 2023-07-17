/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Project 2 A
This creates a series of arrays from a file of songs
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
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    string junk, song, artist, genre, duration;
    while(getline(fin, song, ':')){
        if(song.length() == 1){
            continue;
        }else{
        cout<<song.length()<<endl;
        g_song_names[g_number_of_songs] = song;
        //cout<<song;
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
    //cout<<g_number_of_songs;
}
int main(){
    readSongs("test.txt");
}