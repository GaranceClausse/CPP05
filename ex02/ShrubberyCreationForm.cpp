/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:12:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/05 13:05:23 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called with name " << _name << " sign grade " << _sign_grade << " and exec grade " << _exec_grade << std::endl;
		
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << COLOR MAGENTA << executor.getName() << " will try to execute the form " << _name << COLOR RESET << std::endl;
	if (this->_sign == false)
		throw (NeedToBeSignedException());
	std::string str = this->getTarget() + "_shrubbery";
	const char *file_name = str.c_str();
	if (executor.getGrade() <= this->getExecGrade() && executor.getGrade() <= this->getSignGrade() && this->_sign == true)
	{
		std::cout << _name << " form has been executed by " << executor.getName() << " and file " << this->getTarget() << "_shrubbery has been created" << std::endl;
		std::ofstream MyFile(file_name);
		if (!MyFile)
			return ;
		MyFile << "                 # #### ####			" << std::endl;
        MyFile << "               ### \\/#|### |/####		" << std::endl;
        MyFile << "              ##\\/#/ \\||/##/_/##/_#	" << std::endl;
        MyFile << "            ###  \\/###|/ \\/ # ###	" << std::endl;
        MyFile << "          ##_\\_#\\_\\## | #/###_/_####" << std::endl;
        MyFile << "         ## #### # \\ #| /  #### ##/##	" << std::endl;
        MyFile << "          __#_--###`  |{,###---###-~	" << std::endl;
        MyFile << "                    \\ }{				" << std::endl;
        MyFile << "                     }}{				" << std::endl;
        MyFile << "                     }}{				" << std::endl;
        MyFile << "                     {{}				" << std::endl;
        MyFile << "               , -=-~{ .-^- _			" << std::endl;
        MyFile << "                     `}				" << std::endl;
        MyFile << "                      {				" << std::endl;
  		MyFile.close();
	}
	else
		throw (GradeTooLowException());
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form("Shrubbery", 145, 137)
{
	std::cout <<COLOR  B_GREEN "ShrubberyCreationForm Copy constructor" COLOR RESET  << std::endl;
	operator=(copy);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat *rob)
{
	std::cout << "Let's try to sign the form" << std::endl;
	if (this->_sign_grade < rob->getGrade())
		throw (GradeTooLowException());
	else {
		_sign = true;		
		}	
}
