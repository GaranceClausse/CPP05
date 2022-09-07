/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:52:12 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/07 12:44:47 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor "  << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :  _name(name),_grade(grade)
{
	if (_grade < 1)
		throw (Bureaucrat::GradeTooLowException());
	else if (_grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	else
		std::cout << "Bureaucrat constructor called with name : " << _name << " and grade : "<< _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& copy)
{
	std::cout << "Bureaucrat Operator = " << std::endl;
	_grade = copy.getGrade();
	_name = copy.getName();
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout <<COLOR  B_GREEN "Bureaucrat Copy constructor" COLOR RESET  << std::endl;
	operator=(copy);
}

const char * Bureaucrat::GradeTooHighException::what()  const throw() {
				return (char *)"You can't go higher than God!";
			}
		
const char * Bureaucrat::GradeTooLowException::what() const throw() {
				return (char *)"You can't go lower than Satan!";
			};

const int	&Bureaucrat::getGrade() const
{
	return this->_grade;
}

const std::string	&Bureaucrat::getName() const
{
	return this->_name;
}

void	Bureaucrat::incrementGrade()
{
	std::cout << "Let's increment the Bureaucrat " << _name << " grade..." << std::endl;
	if (_grade <= 1)
		throw GradeTooHighException();
	else	
		_grade--;
	std::cout << "Bureaucrat " << _name << " grade is now : " << _grade << std::endl << std::endl;

}

void	Bureaucrat::decrementGrade()
{
	std::cout << "Let's decrement the Bureaucrat " << _name << " grade..." << std::endl;
	if (_grade >= 150)
		throw (GradeTooLowException());
	else
		_grade++;
	std::cout << "Bureaucrat " << _name << " grade is now : " << _grade << std::endl << std::endl;
}

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const &copy)
{
	stream << copy.getName() << ", bureaucrat grade ";
	stream << copy.getGrade() << std::endl;
	return (stream);
}