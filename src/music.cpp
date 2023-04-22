#include "include/music.hpp"

namespace music
{
    Music::Music() { 
        myMusicList = new MusicList();
        _musicDirectory = "/Users/mac/zzzzz/cpp/basics/my_project/music";
        _extension = ".mp3";

    }
    Music::~Music() {
        delete myMusicList;
    }

    void Music::run() {
        printf("Welcome to Music CLI\n");
        getMusic(myMusicList);
        showMusic();
    }
    void Music::showMusic() {
        for (auto iter = myMusicList->begin(); iter < myMusicList->end(); iter++) {
            printf("%s\n", iter->c_str());

        }
    }
    void Music::getMusic(MusicList* musicList) {
        for (const auto & entry : std::filesystem::directory_iterator(_musicDirectory)) {
            // printf("Music %s\n", entry.path().c_str());
            // printf("File size is %lu\n", entry.file_size());
            // printf("Filename is %s", entry.path().filename().c_str());
            if (entry.path().filename().string().find(_extension) != std::string::npos) {
                printf("mp3 file found\n");
                musicList->push_back(entry.path().filename().string());
            }
        }
    }


} // namespace Music
