#ifndef TRAITS_CRAWL_EXPERIMENT_H
#define TRAITS_CRAWL_EXPERIMENT_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include<cmath>

class Experiment
{
	// INPUT MEMBER VARIABLES
	std::string exp_name;
	std::string creature;
	long population;
	std::string tr1_name;
	std::string tr2_name;
	std::string midtr_name;
	long tr1_count;
	long tr2_count;

public:
	// Constructor
	Experiment() :exp_name(), creature(), population(), tr1_name(),
		tr2_name(), midtr_name("Middle Trait"), tr1_count(), tr2_count() {}
	// Accessors

	

	//Files

	void read(std::istream& in) // reads input from file
	{
		using namespace std;

		// %%%%% EXPERIMENT NAME %%%%%
		while (in.peek() == '#') // looks for a '#'
		{
			in.ignore(INT_MAX, '\n'); //skips to next line if found(comment)
			in >> ws;
		}
		getline(in, exp_name); // Reads  name till newline
		size_t pos = exp_name.find('#'); // Finds position of first # (start of comment)
		if (pos != std::string::npos)
		{
			exp_name.erase(pos); //erases starting from # sign
		}

		// %%%%% CREATURE %%%%%
		while (in.peek() == '#') // looks for a '#'
		{
			in.ignore(INT_MAX, '\n'); //skips to next line if found(comment)
			in >> ws;
		}
		getline(in, creature); // Reads  name till newline
		pos = creature.find('#'); // Finds position of first # (start of comment)
		if (pos != std::string::npos)
		{
			creature.erase(pos); //erases starting from # sign
		}

		// %%%%% POPULATION %%%%%

		while (in.peek() == '#')
		{
			in.ignore(INT_MAX, ('\n'));
			in >> ws;
		}
		in >> population >> ws; // reads 

		// %%%%% TRAIT 1 NAME %%%%%
		while (in.peek() == '#') // looks for a '#'
		{
			in.ignore(INT_MAX, '\n'); //skips to next line if found(comment)
			in >> ws;
		}
		getline(in, tr1_name); // Reads  name till newline
		pos = tr1_name.find('#'); // Finds position of first # (start of comment)
		if (pos != std::string::npos)
		{
			tr1_name.erase(pos); //erases starting from # sign
		}

		// %%%%% TRAIT 2 NAME %%%%%
		while (in.peek() == '#') // looks for a '#'
		{
			in.ignore(INT_MAX, '\n'); //skips to next line if found(comment)
			in >> ws;
		}
		getline(in, tr2_name); // Reads  name till newline
		pos = tr2_name.find('#'); // Finds position of first # (start of comment)
		if (pos != std::string::npos)
		{
			tr2_name.erase(pos); //erases starting from # sign
		}

		// %%%%% TRAIT 1 COUNT %%%%%
		while (in.peek() == '#')
		{
			in.ignore(INT_MAX, ('\n'));
			in >> ws;
		}
		in >> tr1_count >> ws; // reads 

		// %%%%% TRAIT 2 COUNT %%%%%
		while (in.peek() == '#')
		{
			in.ignore(INT_MAX, ('\n'));
			in >> ws;
		}
		in >> tr2_count >> ws; // reads 
	}

	
	void write(std::ostream& out) // writes data to file
	{
		using namespace std;

		// Finding "Width" of name
		string::size_type name_length = midtr_name.length();
		if (tr1_name.length() > name_length)
		{
			name_length = tr1_name.length();
		}
		if (tr2_name.length() > name_length)
		{
			name_length = tr2_name.length();
		}
		// Finding "Width" of number

		short count_length;
		long midtr_count = population - tr1_count - tr2_count;
		count_length = log10(population) + 1;
	
		// Calculations
		
		double  tr1_perc = static_cast<double> (tr1_count + midtr_count / 2.0)
            *100/ population;
	    double  tr2_perc = static_cast<double> (tr2_count + midtr_count / 2.0) 
            *100/ population;

		short padding;
		short spacing = 4;
		short perc_length = 6;
        // calculates amount of spaces needed to center text
		padding = (80 - exp_name.length()) / 2;
		out << string(padding, ' ')  << exp_name  << endl;
		padding = (80 - creature.length()) / 2;
		out << string(padding, ' ') << creature << endl<< endl;

		// Trait 1
		out << right << setw(name_length) << tr1_name << ':' << 
            string(spacing, ' ');
		out << right << setw(count_length) << tr1_count << string(spacing, ' ') ;
		out << right << setw(perc_length) << setprecision(2)<< fixed 
            << tr1_perc << "%\n",
		
         // Mixed Trait
		out << right << setw(name_length) << midtr_name << ':' 
            << string(spacing, ' ');
		out << right << setw(count_length) << midtr_count << endl;
        
        //Trait 2
		out << right << setw(name_length) << tr2_name  << ':' <<  
            string((spacing-2), ' ') << '+' << ' ';
		out << right << setw(count_length) << tr2_count << string(spacing, ' ') ;
		out << right << setw(perc_length) << setprecision(2)  << fixed 
            << tr2_perc << "%\n" ;

        //Equals line under data
		out << right << string((name_length+ spacing-1), ' ') 
            << string(count_length +2, '-') << string(spacing, ' ') 
            << string(7, '-') << endl;
		//Total
		out << right << setw(name_length) << "Total" << ':' 
            << string(spacing, ' ');
		out << right << setw(count_length) << population 
            << string(spacing, ' ');
		out << right << setw(perc_length) << setprecision(2) 
            << fixed << tr1_perc +tr2_perc << "%\n\n\n";
	}



};

#endif /* TRAITS_CRAWL_EXPERIMENT_H */

