/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestRobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:12:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/02 13:18:01 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestRobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", false, 72, 137)
{
	std::cout << "RobotomyRequestForm constructor called with name " << _name << " and sign grade " << _sign_grade << std::endl;
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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
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
	if (this->_sign_grade < rob->getGrade())
		throw (RobotomyRequestForm::GradeTooLowException());
	else {
		_sign = true;
		}	
}
