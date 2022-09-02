/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:12:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/02 13:37:34 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery",false, 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called with name " << _name << " and sign grade " << _sign_grade << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy)
{
	std::cout << "ShrubberyCreationForm Operator = " << std::endl;
	_sign_grade = copy.getSignGrade();
	_name = copy.getName();
	_sign = copy.getSigned();
	_exec_grade = copy.getExecGrade();
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	std::cout <<COLOR  B_GREEN "ShrubberyCreationForm Copy constructor" COLOR RESET  << std::endl;
	operator=(copy);
}

std::string	ShrubberyCreationForm::getName(void) const
{
	return this->_name;
}

bool	ShrubberyCreationForm::getSigned(void) const
{
	return this->_sign;
}


int		ShrubberyCreationForm::getSignGrade(void) const
{
	return this->_sign_grade;
}

int		ShrubberyCreationForm::getExecGrade(void) const
{
	return this->_exec_grade;
}

void	ShrubberyCreationForm::beSigned(Bureaucrat *rob)
{
	if (this->_sign_grade < rob->getGrade())
		throw (ShrubberyCreationForm::GradeTooLowException());
	else {
		_sign = true;
		}	
}
