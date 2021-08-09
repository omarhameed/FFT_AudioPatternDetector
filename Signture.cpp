//
//  Signture.cpp
//  
//
//  Created by Omar Hameed  on 2020-12-10.
//
#include "Signture.h"
#include "data.h"
using namespace std;

void Signture::fft(complex* signal, int length, complex* temp_arr)  //length = 1,2,3...,(length/2)-2
{

	if (length > 1) {
		int k;
		int index;
		complex oddSig, exp, * odd_sig, * even_sig;
		even_sig = temp_arr;
		odd_sig = temp_arr + length / 2;

		for (k = 0; k < length / 2; k++) {// arr[k] is a signal and k is the size of its domain
			even_sig[k] = signal[2 * k]; //if even
			odd_sig[k] = signal[2 * k + 1];//if odd where k =1,2,..,(K/2)-1

		}
		fft(even_sig, length / 2, signal);
		fft(odd_sig, length / 2, signal);




		for (index = 0; index < length / 2; index++) {//Eulers formula exp^-ix = cosx - isinx
			exp.Re = cos(2 * PI * index / (double)length);
			exp.imag = -sin(2 * PI * index / (double)length);
			oddSig.Re = exp.Re * odd_sig[index].Re - exp.imag * odd_sig[index].imag;//real number
			oddSig.imag = exp.Re * odd_sig[index].imag + exp.imag * odd_sig[index].Re;//imag number
			signal[index].Re = even_sig[index].Re + oddSig.Re;
			signal[index].imag = even_sig[index].imag + oddSig.imag;
			signal[index + length / 2].Re = even_sig[index].Re - oddSig.Re;
			signal[index + length / 2].imag = even_sig[index].imag - oddSig.imag;
		}
	}
	return;
}


int* Signture::fft_max(short* data_line, int num_of_samples ){
	header size;
    int length_of_song = num_of_samples/1024;
    int number_of_snippets = length_of_song/5;
    short* channel_data = new short[num_of_samples];
    int maximums[length_of_song];
    int max_indicies[length_of_song];
	channel_data = data_line;// real numbered channel data, just for testing needs to be extracted from channel data

	//stores channel data with complex numbers
    complex* temp_data = new complex[num_of_samples];
    complex* temp_arr = new complex[num_of_samples];

    for (int i=0; i<num_of_samples; i++) {
        temp_data[i].Re = channel_data[i];
        temp_data[i].imag = 0; 

    }
    Signture temp;

    temp.fft(temp_data, num_of_samples, temp_arr);
	
    //Sorting fft to find max value (M)
    int max = 0;
	int iteration = 0;
	int index;
	int abs_data;
	for(int j=0; j<num_of_samples; j++){
		abs_data = sqrt((temp_data[j].Re * temp_data[j].Re) + (temp_data[j].imag * temp_data[j].imag));
		if(abs_data > max){
			max = abs_data;
			index = j;
		}
		int compare = (j+1)%1024;
		if(compare == 0){
			maximums[iteration] = max;
			max_indicies[iteration] = index;
			iteration++;
			max = 0;
		}
	}

	cout << max_indicies[704] << endl;
    return max_indicies;
}


