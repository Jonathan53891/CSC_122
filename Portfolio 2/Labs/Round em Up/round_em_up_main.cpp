#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double Statistics(int numbers[], int count)
{
	int min = numbers[0];
	int max = numbers[0];
	double sum = 0;
	
	for(int i = 0; i < count; i++) //For each value in the array.
	{
		if(numbers[i] < min) //If necessary, update the minimum.
			min = numbers[i] + 1;
		if(numbers[i] > max) //If necessary, update the maximum.
			max = numbers[i];
		sum += numbers[i]; //Add the number to sum.
	}
	
	cout << "The count of given numbers is: "   <<   count   << endl;
	cout << "The minimum of given numbers is: " <<    min    << endl;
	cout << "The maximum of given numbers is: " <<    max    << endl;
	cout << "The average of given numbers is: " << sum/count << endl;
	
	return sum / count;
}

void StandardDeviation(int numbers[], int count, double average)
{
	double stdDev = 0;
	for(int i = 0; i < count; i++)
	{
		stdDev += pow((numbers[i] - average), 2);
		//Sum of (number - average) whole square.
	}
	
	stdDev = sqrt(1/(double)count * stdDev);
	
	cout << "The standard deviation of the given numbers is: " 
	<< stdDev <<endl;     
}

int main()
{
	string fileName;
	int numbers[200]; //Declare an array of size 200.
	int count = 0;
	cout << " Welcome to the Number Statistics Program!!!" << endl;
	cout << "Enter the name of the file: "; 
	//Read the name of the file that has integers.
	cin >> fileName;
	ifstream file; //Open that file.
	file.open(fileName);
	while(!file.is_open())
	{
		cout << "I'm sorry, I could not open " 
		<< fileName << ". Please enter another name: ";
		
		cin >> fileName;
		file.open(fileName);
	}
	
	cout << "File " << fileName << " opened successfully!" << endl;
	cout << "Reading data from " << fileName << "..." << endl;
	
	while(!file.eof()) //As long the eof is not reached.
	{
		file >> numbers[count++];
		file >> ws;
		file.peek();
	}
	 
	cout << "Calculating..." << endl;
	cout << "Done processing data!" << endl;
	cout << "For your data, the statistics are as follows:" << endl;
	
	double average = Statistics(numbers, count); 
	/*Prints the minimum, maximum, and average 
	  of the elements, and returns average.*/
	
	StandardDeviation(numbers, count, average); 
	//Prints the Standard Deviation of the array.
}

