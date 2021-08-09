#ifndef header_hpp
#define header_hpp

using namespace std;

typedef struct header_file
{
    short int num_channels;
    int sample_rate;            // sample_rate denotes the sampling rate.
    short int bits_per_sample;
    int subchunk2_size;            // subchunk2_size denotes the number of samples.
} header;

#endif /* waveheader_hpp */
