/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:17:34 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/07 13:44:18 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

#include <fstream>

class Bureaucrat;

class Form
{
	protected:
		std::string _name;
		bool	_sign;
		int		_sign_grade;
		int		_exec_grade;
		std::string	_target;
		
	public:
		Form();
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form& copy);
		Form &operator=(const Form &copy);
		virtual ~Form();

		std::string	getName(void) const;
		bool	getSigned(void) const;
		int		getSignGrade(void) const;
		int		getExecGrade(void) const;
		virtual void	beSigned(Bureaucrat *rob) = 0;
		virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what()  const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw() ;
	};
	class NeedToBeSignedException : public std::exception
	{
	public:
		virtual const char * what()  const throw();
	};
	class IsSignedException : public std::exception
	{
	public:
		virtual const char * what()  const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, Form const &copy);