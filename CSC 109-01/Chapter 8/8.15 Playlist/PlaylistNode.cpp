/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "PlaylistNode.h"
#include <iostream>

using std::cout;
using std::endl;

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    this->nextNodePtr = nullptr;
}

string PlaylistNode::GetID() {
    return this->uniqueID;
}

string PlaylistNode::GetSongName() {
    return this->songName;
}

string PlaylistNode::GetArtistName() {
    return this->artistName;
}

int PlaylistNode::GetSongLength() {
    return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return this->nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* tempNext = nullptr;

    tempNext = this->nextNodePtr;
    this->nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = tempNext;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    this->nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}