
//  main.cpp
//  wave
//
//  Created by Omar Hameed  on 2020-12-02.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "header.h"
#include "data.h"
#include "edit.h"
#include "Signture.h"
using namespace std;


int main(void){
    char x;
    int loops = 0;
    header meta;
    header meta2;
    short* buffer;
    int num_samples = 0;
    FILE * infile;
    //FILE* outfile;
    short* buffer2;
    int num_samples2;
    header meta_out;
    
    FILE * outfile = fopen("Output.wav","wb");        // Create output ( wave format) file in write mode
    
    edit ed;
    data da;
    Signture sig;
    header size;
    da.data_reader();
    
    while(1){
    cout<<endl<<"Press [P] To Print Header "<<endl;
    cout<<"Press [L] to Loop the First Track"<<endl;
    cout<<"Press [C] to Convert File to Mono"<<endl;
    cout<<"Press [M] to Merge the Two Files"<<endl;
    cout<<"Press [S] to Print Signture"<<endl;
    cout<<"Press [X] to Exit"<<endl;
    cout <<  0xC9   <<"  The Sleezy Music Company " << endl;
    cin>>x;
    
    if(x=='P'){
        da.header_printer();
    }else if(x=='L'){
        cout<<"Number of Loops?"<<endl;
        cin>>loops;
        ed.loop_track(loops, meta, buffer, num_samples, outfile);       

        cout<<"loops"<<loops;

   }else if(x=='C'){
        ed.stereo_to_mono(num_samples, meta, buffer);

    }else if(x=='M'){
        ed.merge_files(meta_out, meta, meta2, num_samples, num_samples2, outfile, buffer, buffer2);
    }else if(x=='S'){
       da.signture_printer();
    }
	
	
	else if(x=='X'){
        return 0;
    }
	
	else{
        cout<<"INCORRECT INPUT PLEASE TRY AGAIN: "<<endl;
        }
   }
    fclose(outfile);
   return 0;
}
