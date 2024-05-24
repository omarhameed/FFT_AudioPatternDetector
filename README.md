# 🎵 WaveProcessor README 🎵

## 📜 Description

WaveProcessor is a powerful tool designed to perform Fast Fourier Transform (FFT) on signal data, extract frequency components, and identify maximum frequency indices. It features functionalities for reading wave file data, processing it, and performing various audio editing tasks.

## 📁 Files

- **Signture.cpp**: Implements FFT and related functions.
- **Signture.h**: Header file for `Signture` class.
- **data.cpp**: Reads and processes data from wave files.
- **data.h**: Header file for `data` class.
- **edit.cpp**: Contains functions for audio editing.
- **edit.h**: Header file for `edit` class.
- **main.cpp**: Contains the main function for program execution.

## 🛠️ Compilation

To compile the program, use a C++ compiler. For example:

```sh
g++ -o waveprocessor main.cpp Signture.cpp data.cpp edit.cpp -lm
```
#  🚀 Execution
To run the compiled program:
```
./waveprocessor
```
📚 Usage
Upon running the program, follow the prompts to interact with various functionalities:

- Press [P]: Print the wave file header information.
- Press [L]: Loop the first track.
- Press [C]: Convert the file to mono.
- Press [M]: Merge two files.
- Press [S]: Print the signature of the files.
- Press [X]: Exit the program.
