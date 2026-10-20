#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {

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
      void execute(Bureaucrat const & executor) const;
      virtual void executeAction() const = 0;

      AForm(const std::string &name, int requiredSign, int requiredExec);
      virtual ~AForm();
      AForm(const AForm &copy);
      AForm &operator=(const AForm &copy);

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

      class FormNotSignedException : public std::exception {
         public : 
            virtual const char *what() const throw() {
               return "Form not signed!";
         }
      } ;
} ;

std::ostream &operator<<(std::ostream &os, AForm &Aform);

#endif