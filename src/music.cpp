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
        // delete mp3File;
    }

    void Music::run() {
        printf("Welcome to Music CLI\n");
        getMusic(myMusicList);
        showMusic();
        int index = selectMusic();
        printf("length of music list is %lu\n", myMusicList->size());
        printf("index selected is %s\n", myMusicList->at(index-1).c_str());
        // mp3File = new Aquila::WaveFile(myMusicList->at(index));
    }
    void Music::showMusic() {
        uint64_t i = 0;
        for (auto iter = myMusicList->begin(); iter < myMusicList->end(); iter++) {
            i++;
            printf("%llu: %s\n", i, iter->c_str());

        }
    }
    void Music::getMusic(MusicList* musicList) {
        for (const auto & entry : std::filesystem::directory_iterator(_musicDirectory)) {
            // printf("Music %s\n", entry.path().c_str());
            // printf("File size is %lu\n", entry.file_size());
            // printf("Filename is %s", entry.path().filename().c_str());
            if (entry.path().filename().string().find(_extension) != std::string::npos) {
                // printf("mp3 file found\n");
                musicList->push_back(entry.path().filename().string());
            }
        }
    }

    int Music::selectMusic() {
        int index;
        printf("Select Music: ");
        scanf("%d", &index);
        return index;
    }
    
    void Music::play() {

    }

    void Music::pause() {

    }

    void Music::stop() {

    }


} // namespace Music
