#include <string>
#if !defined(BEER_SONG_H)
#define BEER_SONG_H
#include "string"


namespace beer_song {
    std::string verse(int);
    std::string sing(int,int=0);
    //std::string sing(int);
}  // namespace beer_song

#endif // BEER_SONG_H