#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
// #include "aquila/aquila.h"

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
        void play();
        void pause();
        void stop();
        private:
        /**
         * Function to get the music list 
         * from the music directory
        */
        void getMusic(MusicList* musicList);
        /**
         * 
         * Shows the list of musics available
         * 
         * 
        */
        void showMusic();
        /**
         * Function to select the index of music to play
         * @return uint8_t
        */
        int selectMusic();
        

        std::string _musicDirectory, _extension; // Directory containing music
        MusicList* myMusicList;
        // Aquila::WaveFile *mp3File;
        

    };
} // namespace music
