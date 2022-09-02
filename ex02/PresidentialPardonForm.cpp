/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:12:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/02 13:37:56 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"



PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon",false, 145, 137)
{
	std::cout << "PresidentialPardonForm constructor called with name " << _name << " and sign grade " << _sign_grade << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& copy)
{
	std::cout << "PresidentialPardonForm Operator = " << std::endl;
	_sign_grade = copy.getSignGrade();
	_name = copy.getName();
	_sign = copy.getSigned();
	_exec_grade = copy.getExecGrade();
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	std::cout <<COLOR  B_GREEN "PresidentialPardonForm Copy constructor" COLOR RESET  << std::endl;
	operator=(copy);
}

std::string	PresidentialPardonForm::getName(void) const
{
	return this->_name;
}

bool	PresidentialPardonForm::getSigned(void) const
{
	return this->_sign;
}


int		PresidentialPardonForm::getSignGrade(void) const
{
	return this->_sign_grade;
}

int		PresidentialPardonForm::getExecGrade(void) const
{
	return this->_exec_grade;
}

void	PresidentialPardonForm::beSigned(Bureaucrat *rob)
{
	if (this->_sign_grade < rob->getGrade())
		throw (PresidentialPardonForm::GradeTooLowException());
	else {
		_sign = true;
		}	
}
