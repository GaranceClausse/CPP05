/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:12:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/02 15:24:44 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", false, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called with name " << _name << " and sign grade " << _sign_grade << std::endl;
	
}

void		RobotomyRequestForm::action()
{
	std::cout << "BRRRRROOOOM *** CRICKCRICK " << std::endl;
	if ((rand() % 2) + 1 ==  2)
		std::cout << _target << " has been lobotomised... " << std::endl;
	else 
		std::cout << _target << " lobotomisation failed... " << std::endl;


}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& copy)
{
	std::cout << "RobotomyRequestForm Operator = " << std::endl;
	_sign_grade = copy.getSignGrade();
	_name = copy.getName();
	_sign = copy.getSigned();
	_exec_grade = copy.getExecGrade();
	_target = copy.getTarget();
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)  : Form("Robotomy", false, 72, 45)
{
	std::cout <<COLOR  B_GREEN "RobotomyRequestForm Copy constructor" COLOR RESET  << std::endl;
	operator=(copy);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void	RobotomyRequestForm::beSigned(Bureaucrat *rob)
{
	if (this->_sign_grade < rob->getGrade() || this->_exec_grade < rob->getGrade())
		throw (RobotomyRequestForm::GradeTooLowException());
	else {
		_sign = true;
		
		}	
}
