#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {

   private :
      const std::string _name;
      bool _signed;
      const int _requiredSign;
      const int _requiredExec;

   public :
      std::string getName() const;
      int getRequiredSign() const;
      int getRequiredExec() const;
      bool getSigned() const ;

      void beSigned(const Bureaucrat &b);

      Form(const std::string &name, int requiredSign, int requiredExec);
      ~Form();
      Form(const Form &copy);
      Form &operator=(const Form &copy);

      class GradeTooHighException : public std::exception {
         public : 
            virtual const char *what() const throw() {
               return "Grade is too high!";
         }
      } ;
      class GradeTooLowException : public std::exception {
         public :
            virtual const char *what() const throw() {
               return "Grade is too low!";
         }
      } ;
} ;

std::ostream &operator<<(std::ostream &os, Form &form);

#endif