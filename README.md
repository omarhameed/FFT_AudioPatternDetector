# 🎵 WaveProcessor README 🎵

Welcome to **WaveProcessor**! This project provides a set of tools for processing and analyzing WAV audio files. It includes functionality for Fast Fourier Transform (FFT), identifying maximum values, reading audio data, and performing various audio manipulations such as converting stereo to mono, looping tracks, and merging files.

## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#Description)
3. [Files](#Files)
4. [Compilation](#Compilation)
5. [Execution](#Execution)
6. [Usage](#Usage)

## Introduction

WaveProcessor is designed to help users perform advanced audio processing tasks. It includes the following features:
- FFT for signal analysis
- Maximum value identification in FFT results
- Reading audio data from WAV files
- Audio manipulations such as stereo to mono conversion, looping tracks, and merging audio files
- Signature comparison for audio snippet matching
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
##  🚀 Execution
To run the compiled program:
```
./waveprocessor
```
## 📚 c

Upon running the program, follow the prompts to interact with various functionalities:

- Press [P]: Print the wave file header information.
- Press [L]: Loop the first track.
- Press [C]: Convert the file to mono.
- Press [M]: Merge two files.
- Press [S]: Print the signature of the files.
- Press [X]: Exit the program.
