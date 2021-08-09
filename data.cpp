//
//  data.cpp
//  wave
//
//  Created by Omar Hameed on 2020-12-02.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "data.h"
#include "edit.h"
#include "Signture.h"

int data::data_reader(void){
	string filename;
	string filename2;

    
    cout << "First Input filename:" << endl;
    cin >> filename;   	
    FILE * infile = fopen(filename.c_str(),"rb");        // Open wave file in read mode
    cout << "Second Input filename:" << endl;
    cin >> filename2;
    FILE * infile2 = fopen(filename2.c_str(),"rb");        // Open wave file in read mode
    fread(&meta, 1, sizeof(header), infile);
    fread(&meta2, 1, sizeof(header), infile2);
    
    int num_samples = meta.subchunk2_size / sizeof(short);
    short* buffer = new short[num_samples];
    int num_samples2 = meta2.subchunk2_size / sizeof(short);
    short* buffer2 = new short[num_samples2];    //for (int w = 0 ; w<num_samples2; w = w+100){cout << *buffer2 ; }
    fread(buffer, sizeof(short), num_samples, infile);
    fread(buffer2, sizeof(short), num_samples2, infile2);
    
    
    Signture sig;
    Signture sig2;
    //int* max_indicies;
    //int* max_indicies2;
    max_indicies = sig.fft_max(buffer,num_samples);
    max_indicies2 = sig2.fft_max(buffer2,num_samples2);    
     values_per_snippet = meta.sample_rate*5/1024;
    int num_segments = num_samples/1024;
    num_snippets = num_segments/values_per_snippet;
    int num_segments2 = num_samples2/1024;
    int partial_match;
	int x=0;
    int i;
    int k;
    
    for( i=0; i<num_snippets; i++){ //for each 5s snippet
    	
		for(int j=0; j<num_segments2-values_per_snippet; j++){
		    //Iterate through all segments of the other song until we reach the last n, where n is the length of a snippet
    		partial_match = 0;
    		//Initialize for each comparison of a snippet to a set of values in the song signature
    		
			for( k=0; k<values_per_snippet; k++){
    		
				if(max_indicies[k] == max_indicies2[k]){ //if one of the indicies in the snippet matches
    				partial_match++;
				}
					
				}
			}
				if(partial_match > values_per_snippet*0.95 ){ //if the two sections are more than 95% similar
					cout << "Match found  with more than 95% similarity in snippet " << i <<"" << endl;
					cout << "The files involved are " << filename << " and " << filename2;
					
				}
		}
	

    return 0;
}

int data::header_printer(void){


    cout << " Number of channels is "<< meta.num_channels << endl;
    cout << " Sampling rate of the input wave file is "<< meta.sample_rate <<" Hz" << endl;
    cout << " Number of samples per channel are " << meta.subchunk2_size/meta.num_channels/2 << " samples" << endl;
    cout << " Number of samples in wave file are " <<meta.subchunk2_size/meta.num_channels<< " samples" << endl;
    cout << " Bits per sample are " << meta.bits_per_sample << " bits" << endl;

	return 0;
}

void data::signture_printer(){
	cout << "The signture for the first file is {";
	for( int i=0; i<num_snippets; i++){
		for( int k=0; k<values_per_snippet; k++){
			cout << max_indicies[k] << "," ;
}
}
	cout << " } "<< endl;
	cout << "The signture for the second file is {";
	for( int i=0; i<num_snippets; i++){
		for( int k=0; k<values_per_snippet; k++){
			cout << max_indicies2[k] << "," ;
}
}cout << "} "<< endl;
}

