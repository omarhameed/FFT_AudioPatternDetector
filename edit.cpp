//
//  edit.cpp
//  wave
//
//  Created by Omar Hameed  on 2020-12-02.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "header.h"
#include "edit.h"
#include "data.h"

using namespace std;

void edit::stereo_to_mono(int num_samples, header meta, short* buffer){

    meta.subchunk2_size /= 2;
    meta.num_channels = 1;
    short* out_buffer = new short[num_samples];
    
    for (unsigned i = 0; i < num_samples; i += 1) {
      short left = buffer[i*2 + 0];
      short right = buffer[i*2 + 1];
      short monoSample = ((int)left + right) / 2;
      short monoSample2 = ((int)left + right) / 2;
      out_buffer[i] = monoSample;
    }
}
void edit::loop_track(int loops, header meta, short* buffer, int num_samples, FILE* outfile){
    meta.subchunk2_size *= (loops);
    fwrite(&meta, 1, sizeof(header), outfile);
    for (unsigned i = 0; i < loops; i ++) {
        fwrite(buffer, sizeof(short), num_samples, outfile);
    }
      
    meta.subchunk2_size = meta.subchunk2_size*loops;
}

void edit::merge_files(header meta_out, header meta, header meta2, int num_samples, int num_samples2, FILE* outfile, short* buffer, short* buffer2){
    meta_out.subchunk2_size = meta.subchunk2_size + meta2.subchunk2_size;
    
    fwrite(&meta_out, 1, sizeof(header), outfile);
    
    fwrite(buffer, sizeof(short), num_samples, outfile);
    fwrite(buffer2, sizeof(short), num_samples2, outfile);
}
