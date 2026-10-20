#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {

   private :
      std::string _target;
   public:
      ShrubberyCreationForm(std::string const & target);
      ShrubberyCreationForm(ShrubberyCreationForm const &copy);
      ~ShrubberyCreationForm();
      ShrubberyCreationForm & operator=(ShrubberyCreationForm const &copy);
      
      void executeAction() const;
      std::string getTarget() const;
};

#endif