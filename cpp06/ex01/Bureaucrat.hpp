#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>

class Form;

class Bureaucrat {

   private :

      const std::string _name;
      int _grade;

   public :

      Bureaucrat(const std::string &name, int grade);
      ~Bureaucrat();
      Bureaucrat(const Bureaucrat &copy);
      Bureaucrat &operator=(const Bureaucrat &copy);

      int getGrade() const;
      const std::string getName() const;
      void incrementGrade();
      void decrementGrade();

      void signForm(Form &form);
         
      class GradeTooHighException : public std::exception {
         public:
            virtual const char* what() const throw() {
               return "Grade is too high!";
         }
      };

      class GradeTooLowException : public std::exception {
         public:
            virtual const char* what() const throw() {
               return "Grade is too low!";
         }
      };
} ;

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif