#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <cstdlib>
#include <vector>

//******************************************
// Checks to see if input is a valid long
void input_prot(long& input, const std::string& prompt,
        const std::string& error_prompt);

//min or max
void input_prot(long& input,const long& bound,
         const std::string& prompt, const std::string& error_prompt, const bool& bound_is_max
         ); 

//min and max
void input_prot(long& input,const long& min, const long& max, const std::string& prompt,
        const std::string& error_prompt
        );

//******************************************
// Checks to see if input is in list of longs
void list_input_prot(long& input, const std::vector<long>& list,
        const std::string& prompt, const std::string& error_prompt);


//******************************************
// Checks to see if input is a valid double
void input_prot(double& input, const std::string& prompt,
        const std::string& error_prompt);

// min or max
void input_prot(double& input,const double& bound,
         const std::string& prompt,
        const std::string& error_prompt, const bool& bound_is_max);

// min and max
void input_prot(double& input, const double& min, const double max, 
        const std::string& prompt, const std::string& error_prompt);

//******************************************
// Checks to see if input is in list of doubles
void list_input_prot(double& input, const std::vector<double>& list_input,
        const std::string& prompt,
        const std::string& error_prompt);


//******************************************
// Checks to see if input is a valid char
void input_prot(char& input, const std::string& prompt,
        const std::string& error_prompt);

//******************************************
// Checks to see if input is in list of chars
void list_input_prot(char& input, const std::vector<char>& list,
        const std::string& prompt,
        const std::string& error_prompt);

//******************************************
// Inputs string to vector
void list_input_char(const std::string& input, std::vector<char>& list);

#endif /* INPUT_H */
