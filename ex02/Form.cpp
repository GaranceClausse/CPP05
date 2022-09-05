/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:17:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/05 11:44:39 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form constructor called with name " << _name << " and sign grade " << _sign_grade << " exec grade " << _exec_grade << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form&	Form::operator=(Form const& copy)
{
	std::cout << "Form Operator = " << std::endl;
	_sign_grade = copy.getSignGrade();
	_name = copy.getName();
	_sign = copy.getSigned();
	_exec_grade = copy.getExecGrade();
	return (*this);
}

Form::Form(const Form &copy)
{
	std::cout <<COLOR  B_GREEN "Form Copy constructor" COLOR RESET  << std::endl;
	operator=(copy);
}

std::string	Form::getName(void) const
{
	return this->_name;
}

bool	Form::getSigned(void) const
{
	return this->_sign;
}


int		Form::getSignGrade(void) const
{
	return this->_sign_grade;
}

int		Form::getExecGrade(void) const
{
	return this->_exec_grade;
}

void	Form::beSigned(Bureaucrat *rob)
{
	if (this->_sign_grade < rob->getGrade())
{		std::cout << "Form must be signed by someoone with higher rank" << std::endl;
		throw (Form::GradeTooLowException());
}
	else {
		_sign = true;
		}	
}

void Form::execute(Bureaucrat const & executor) const
{
	if (_exec_grade < executor.getGrade())
	{		
		std::cout << "Form must be executed by someone with higher rank" << std::endl;
		throw (GradeTooLowException());
	}
	else if (_sign == false)
		std::cout << "Form must be signed to be executed" << std::endl;
}

std::ostream&	operator<<(std::ostream& stream, Form const &copy)
{
	stream << copy.getName();
	stream << copy.getSigned();
	stream << copy.getSignGrade();
	stream << copy.getExecGrade();
	return (stream);
}