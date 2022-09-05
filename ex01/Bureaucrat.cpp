/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:52:12 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/05 12:21:51 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) :  _name(name),_grade(grade)
{
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
	_grade--;
		if (_grade < 1)
			throw GradeTooHighException();
	std::cout << "Bureaucrat " << _name << " grade is now : " << _grade << std::endl << std::endl;

}

void	Bureaucrat::decrementGrade()
{
	std::cout << "Let's decrement the Bureaucrat " << _name << " grade..." << std::endl;
	_grade++;
		if (_grade > 150)
			throw (GradeTooLowException());
}

void	Bureaucrat::signForm(Form* form)
{
	if (this->getGrade() > form->getSignGrade())
		std::cout << this->getName() << " couldn't sign the form " << form->getName() << " because its grade is too low!" << std::endl;
	else
	{
		form->beSigned(this);
		std::cout << this->getName() << " signed the form " << form->getName() << std::endl;
	}

}

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const &copy)
{
	stream << copy.getName();
	stream << copy.getGrade();
	return (stream);
}