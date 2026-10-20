#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class AForm;

class Intern {

   private : 
      AForm *createShrubbery(std::string target);
      AForm *createRobotomy(std::string target);
      AForm *createPardon(std::string target);

   public:

      Intern();
      Intern(const Intern &copy);
      ~Intern();
      Intern & operator=(Intern const &copy);

      AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif