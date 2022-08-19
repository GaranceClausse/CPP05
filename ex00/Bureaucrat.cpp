/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:52:12 by gclausse          #+#    #+#             */
/*   Updated: 2022/08/19 18:12:22 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(/* args */)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& copy)
{
	std::cout << "Bureaucrat Operator = " << std::endl;
	_name = copy.getName();
	_grade = copy.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout <<COLOR  B_GREEN "Bureaucrat Copy constructor" COLOR RESET  << std::endl;
	operator=(copy);
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

int	Bureaucrat::getName() const
{
	return this->_name;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		_grade--;
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "You're already at the most important post there is!!" << std::endl;
	}
	
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		_grade++;
		if (grade > 150)
			throw (Bureaucrat::GradeTooHighException);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "You're already at the worst possible post!!" << std::endl;
	}	
}
