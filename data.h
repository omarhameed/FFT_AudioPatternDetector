//
//  data.h
//  wave
//
//  Created by Omar Hameed on 2020-12-02.
//

#ifndef data_h
#define data_h
#include "header.h"
#include "edit.h"

class data{
    
private:
    int* max_indicies;
    int* max_indicies2;
    int values_per_snippet ;
	int num_snippets;

public:

    header meta;
    header meta2;
    int data_reader(void);
    int header_printer(void);
    void signture_printer();
};

#endif /* data_h */
