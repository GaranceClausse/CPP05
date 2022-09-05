/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:12:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/05 10:43:32 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"



PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardon", 145, 137), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called with name " << _name << " and sign grade " << _sign_grade << std::endl;

}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getExecGrade() && executor.getGrade() <= this->getSignGrade() && this->_sign == true)
	{
		std::cout << _target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw (GradeTooLowException());
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
	_target = copy.getTarget();
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form("PresidentialPardon", 145, 137)
{
	std::cout <<COLOR  B_GREEN "PresidentialPardonForm Copy constructor" COLOR RESET  << std::endl;
	operator=(copy);
}


std::string	PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void	PresidentialPardonForm::beSigned(Bureaucrat *rob)
{
	if (this->_sign_grade < rob->getGrade())
		throw (PresidentialPardonForm::GradeTooLowException());
	else {
		_sign = true;
		}	
}
