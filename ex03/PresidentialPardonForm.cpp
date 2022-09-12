/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:12:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/12 15:26:08 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default constructor called"<< std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called with name " << _name << " and sign grade " << _sign_grade << std::endl;

}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << COLOR MAGENTA << executor.getName() << " will try to execute the form " << _name << COLOR RESET << std::endl;
	if (this->_sign == false)
		throw (NeedToBeSignedException());
	if (executor.getGrade() <= this->getExecGrade())
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

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy), _target(copy._target)
{
	std::cout <<COLOR  B_GREEN "PresidentialPardonForm Copy constructor" COLOR RESET  << std::endl;
}


std::string	PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void	PresidentialPardonForm::beSigned(Bureaucrat *rob)
{
	std::cout << "Let's try to sign the form" << std::endl;
	if (this->_sign_grade < rob->getGrade())
		throw (GradeTooLowException());
	else {
		_sign = true;
		}	
}
