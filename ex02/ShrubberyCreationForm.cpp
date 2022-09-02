/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:12:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/02 15:24:44 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery",false, 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called with name " << _name << " sign grade " << _sign_grade << " and exec grade " << _exec_grade << std::endl;
		
}

void			ShrubberyCreationForm::action()
{
	std::ofstream MyFile(this->getTarget() + "_shrubbery");
	MyFile << "Ascii tree";
  	MyFile.close();
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
	_target = copy.getTarget();
	return (*this);
}


std::string	ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form("Shrubbery",false, 145, 137)
{
	std::cout <<COLOR  B_GREEN "ShrubberyCreationForm Copy constructor" COLOR RESET  << std::endl;
	operator=(copy);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat *rob)
{
	if (this->_sign_grade < rob->getGrade() || this->_exec_grade < rob->getGrade())
		throw (ShrubberyCreationForm::GradeTooLowException());
	else {
		_sign = true;		
		}	
}
