#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int MAX_DAYS = 30;

void inputTemperatures(float dayTemps[], float nightTemps[], int &dayCount);
void readTemperatures(float dayTemps[], float nightTemps[], int &dayCount);
void calculateFluctuation(float dayTemps[], float nightTemps[], int dayCount);
void calculateAverages(float dayTemps[], float nightTemps[], int dayCount);
void calculateMinMax(float dayTemps[], float nightTemps[], int dayCount);
void convertToFahrenheit(float tempCelsius);
void analyzeSuitability(float dayTemps[], float nightTemps[], int dayCount);
void displayTemperatures(float dayTemps[], float nightTemps[], int dayCount);

void displayTemperatures(float dayTemps[], float nightTemps[], int dayCount) {
    if (dayCount == 0) {
        cout << "No temperature data available to display." << endl;
        return;
    }

    cout << "Day and Night Temperatures:" << endl;
    for (int i = 0; i < dayCount; i++) {
        cout << "Day " << i + 1 << ": Day Temperature = " << dayTemps[i] << "°F, Night Temperature = " << nightTemps[i] << "°F" << endl;
    }
}

void inputTemperatures(float dayTemps[], float nightTemps[], int &dayCount) {
    ofstream outfile("temperatures.txt", ios::app);
    if (dayCount >= MAX_DAYS) {
        cout << "Maximum number of days reached. Cannot input more temperatures." << endl;
        return;
    }
    for (int i = dayCount; i < MAX_DAYS; i++) {
        cout << "Enter day temperature for day " << i + 1 << ": ";
        cin >> dayTemps[i];
        cout << "Enter night temperature for day " << i + 1 << ": ";
        cin >> nightTemps[i];
        outfile << dayTemps[i] << " " << nightTemps[i] << endl;
        dayCount++;
        if (dayCount == MAX_DAYS) {
            cout << "Maximum number of days reached." << endl;
            break;
        }
    }
    outfile.close();
}

void readTemperatures(float dayTemps[], float nightTemps[], int &dayCount) {
    dayCount = 0;
    ifstream infile("temperatures.txt");
    if (!infile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (infile >> dayTemps[dayCount] >> nightTemps[dayCount]) {
        dayCount++;
        if (dayCount == MAX_DAYS) {
            cout << "Maximum number of days loaded from the file." << endl;
            break;
        }
    }

    if (dayCount == 0) {
        cout << "No temperature data available in the file." << endl;
    } else {
        cout << "Successfully loaded temperature data from the file." << endl;
    }
    infile.close();
}

void calculateFluctuation(float dayTemps[], float nightTemps[], int dayCount) {
    float totalFluctuation = 0;
    for (int i = 0; i < dayCount; i++) {
        float dailyFluctuation = fabs(dayTemps[i] - nightTemps[i]);
        cout << "Day " << i + 1 << " temperature fluctuation: " << dailyFluctuation << "°F" << endl;
        totalFluctuation += dailyFluctuation;
    }
    float averageFluctuation = totalFluctuation / dayCount;
    cout << "Average temperature fluctuation: " << averageFluctuation << "°F" << endl;
}

void calculateAverages(float dayTemps[], float nightTemps[], int dayCount) {
    if (dayCount == 0) {
        cout << "No temperature data available." << endl;
        return;
    }

    float totalDayTemp = 0;
    float totalNightTemp = 0;
    for (int i = 0; i < dayCount; i++) {
        totalDayTemp += dayTemps[i];
        totalNightTemp += nightTemps[i];
    }
    float averageDayTemp = totalDayTemp / dayCount;
    float averageNightTemp = totalNightTemp / dayCount;
    cout << "Average day temperature: " << averageDayTemp << "°F" << endl;
    cout << "Average night temperature: " << averageNightTemp << "°F" << endl;
}

void calculateMinMax(float dayTemps[], float nightTemps[], int dayCount) {
    if (dayCount == 0) {
        cout << "No temperature data available." << endl;
        return;
    }

    float maxDayTemp = dayTemps[0];
    float minDayTemp = dayTemps[0];
    float maxNightTemp = nightTemps[0];
    float minNightTemp = nightTemps[0];

    for (int i = 1; i < dayCount; i++) {
        if (dayTemps[i] > maxDayTemp) maxDayTemp = dayTemps[i];
        if (dayTemps[i] < minDayTemp) minDayTemp = dayTemps[i];
        if (nightTemps[i] > maxNightTemp) maxNightTemp = nightTemps[i];
        if (nightTemps[i] < minNightTemp) minNightTemp = nightTemps[i];
    }
    
    cout << "Maximum day temperature: " << maxDayTemp << "°F" << endl;
    cout << "Minimum day temperature: " << minDayTemp << "°F" << endl;
    cout << "Maximum night temperature: " << maxNightTemp << "°F" << endl;
    cout << "Minimum night temperature: " << minNightTemp << "°F" << endl;
}

void convertToFahrenheit(float tempCelsius) {
    float tempFahrenheit = (tempCelsius * 9 / 5) + 32;
    cout << tempCelsius << "°C is equal to " << tempFahrenheit << "°F" << endl;
}

void analyzeSuitability(float dayTemps[], float nightTemps[], int dayCount) {
    int suitableDays = 0;
    for (int i = 0; i < dayCount; i++) {
        if (dayTemps[i] >= 70 && dayTemps[i] <= 80 && nightTemps[i] >= 55 && nightTemps[i] <= 62) {
            suitableDays++;
        }
    }
    cout << "Number of suitable days for orchid growth: " << suitableDays << endl;
}

int main() {
    float dayTemps[MAX_DAYS];
    float nightTemps[MAX_DAYS];
    int dayCount = 0;

    while (true) {
        cout << "Orchi-flora Planters Temperature Analyzing System" << endl;
        cout << "===============================================" << endl;
        cout << "1. Load temperatures from the file" << endl;
        cout << "2. Input temperatures for a month" << endl;
        cout << "3. Calculate daily temperature fluctuation" << endl;
        cout << "4. Calculate average day and night temperatures" << endl;
        cout << "5. Calculate maximum and minimum day and night temperatures" << endl;
        cout << "6. Convert temperature from Celsius to Fahrenheit" << endl;
        cout << "7. Analyze suitability for orchid growth" << endl;
        cout << "8. Display temperatures" << endl;  
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                readTemperatures(dayTemps, nightTemps, dayCount);
                break;
            case 2:
                inputTemperatures(dayTemps, nightTemps, dayCount);
                break;
            case 3:
                calculateFluctuation(dayTemps, nightTemps, dayCount);
                break;
            case 4:
                calculateAverages(dayTemps, nightTemps, dayCount);
                break;
            case 5:
                calculateMinMax(dayTemps, nightTemps, dayCount);
                break;
            case 6:
                float tempCelsius;
                cout << "Enter temperature in Celsius: ";
                cin >> tempCelsius;
                convertToFahrenheit(tempCelsius);
                break;
            case 7:
                analyzeSuitability(dayTemps, nightTemps, dayCount);
                break;
            case 8:
                displayTemperatures(dayTemps, nightTemps, dayCount);  
                break;
            case 9:
                cout << "Exiting the system..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 9." << endl;
        }
    }
    return 0;
}
