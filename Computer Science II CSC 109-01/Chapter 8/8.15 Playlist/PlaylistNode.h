/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef PLAYLIST_NODE_H
#define PLAYLIST_NODE_H

#include <string>
using std::string;

class PlaylistNode{
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
    public:
        PlaylistNode();
        PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void InsertAfter(PlaylistNode* nodePtr);
        void SetNext(PlaylistNode* nodePtr);
        void PrintPlaylistNode();
};

#endif
