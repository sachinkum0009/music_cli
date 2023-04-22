#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>

typedef std::vector<std::string> MusicList;

/**
 * music namespace
 * class Music
 * function to read the music files, play, pause and stop
*/
namespace music
{
    class Music {
        public:
        Music();
        ~Music();
        void run();
        private:
        /**
         * Function to get the music list 
         * from the music directory
        */
        void getMusic(MusicList* musicList);
        void showMusic();

        std::string _musicDirectory, _extension; // Directory containing music
        MusicList* myMusicList;
        

    };
} // namespace music
