//
//  edit.h
//  wave
//
//  Created by Omar Hameed  on 2020-12-02.
//

#ifndef edit_h
#define edit_h
#include "data.h"
#include "header.h"
class edit{
    
private:
    //int loops;
    //int num_samples;
public:
    void stereo_to_mono(int,header,short*);
    void loop_track(int,header,short*,int,FILE*);
    void merge_files(header,header,header,int,int,FILE*,short*,short*);
};

#endif /* edit_h */
