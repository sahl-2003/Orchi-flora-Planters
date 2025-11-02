# Orchi-flora Planters Temperature Analyzing System

A C++ application for analyzing daily and nightly temperature data to assess suitability for orchid growth. This program provides various temperature analysis features including fluctuation calculations, statistical analysis, and growth suitability assessment.

## Overview

This program manages and analyzes temperature data for up to 30 days, tracking both day and night temperatures. It can load data from a file, accept manual input, and perform various calculations to help assess optimal conditions for orchid cultivation.

## Features

- **Temperature Data Management**
  - Load temperature data from `temperatures.txt` file
  - Input new temperature data manually
  - Store data in a text file for persistence

- **Temperature Analysis**
  - Calculate daily temperature fluctuations
  - Compute average day and night temperatures
  - Find maximum and minimum temperatures for both day and night periods
  - Convert temperatures from Celsius to Fahrenheit

- **Growth Suitability Analysis**
  - Analyze temperature conditions for optimal orchid growth
  - Identifies days suitable for orchid growth based on:
    - Day temperature: 70-80°F
    - Night temperature: 55-62°F

- **Data Display**
  - View all recorded temperature data in a formatted table

## Files

- `KDHDCSE7422_Thaslim Mohemmed Sahl.cpp` - Main source code file
- `temperatures.txt` - Data file containing day and night temperature pairs
- `KDHDCSE7422_Thaslim Mohemmed Sahl.exe` - Compiled executable (Windows)

## Compilation

### Using g++ (GCC)
```bash
g++ -o temperature_analyzer "KDHDCSE7422_Thaslim Mohemmed Sahl.cpp"
```

### Using Microsoft Visual C++
```bash
cl "KDHDCSE7422_Thaslim Mohemmed Sahl.cpp" /Fe:temperature_analyzer.exe
```

## Running the Program

### Windows
```bash
.\KDHDCSE7422_Thaslim Mohemmed Sahl.exe
```

### Linux/Mac (after compilation)
```bash
./temperature_analyzer
```

## Usage

Upon running the program, you will see a menu with the following options:

1. **Load temperatures from the file** - Reads existing temperature data from `temperatures.txt`
2. **Input temperatures for a month** - Manually enter day and night temperatures (up to 30 days)
3. **Calculate daily temperature fluctuation** - Shows daily temperature differences and average fluctuation
4. **Calculate average day and night temperatures** - Computes and displays average temperatures
5. **Calculate maximum and minimum temperatures** - Finds the highest and lowest temperatures
6. **Convert temperature from Celsius to Fahrenheit** - Temperature conversion utility
7. **Analyze suitability for orchid growth** - Determines how many days meet optimal orchid growth conditions
8. **Display temperatures** - Shows all recorded temperature data
9. **Exit** - Terminates the program

## Temperature Data Format

The `temperatures.txt` file stores temperature data in a simple format:
- Each line contains two floating-point numbers separated by a space
- First number represents day temperature (°F)
- Second number represents night temperature (°F)

Example:
```
75 60
78 69
79 65
```

## Optimal Orchid Growth Conditions

The program considers a day suitable for orchid growth when:
- Day temperature is between **70-80°F**
- Night temperature is between **55-62°F**

## Requirements

- C++ compiler supporting C++11 or later
- Standard C++ libraries: `<iostream>`, `<fstream>`, `<cmath>`
- Windows/Linux/Mac OS with command-line interface

## Author

**Thaslim Mohemmed Sahl**  
Student ID: CMUst20315136  
Course: CSE4002 / KDHDCSE7422

## Notes

- The program supports a maximum of 30 days of temperature data
- Temperature values are stored in Fahrenheit
- The program appends new temperature data to the existing `temperatures.txt` file
- Make sure `temperatures.txt` exists in the same directory as the executable for file operations to work correctly

## License

This project is part of an academic assignment.

