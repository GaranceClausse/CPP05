/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:17:34 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/02 12:15:25 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string _name;
		bool	_sign;
		int		_sign_grade;
		int		_exec_grade;
		
	public:
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form& copy);
		Form &operator=(const Form &copy);
		~Form();

		std::string	getName(void) const;
		bool	getSigned(void) const;
		int		getSignGrade(void) const;
		int		getExecGrade(void) const;
		void	beSigned(Bureaucrat *rob);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what()  const throw() {
			return (char *)"You're too high!!";
		}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw() {
			return (char *)"You're too low!!'";
		};
	};
};

std::ostream&	operator<<(std::ostream& stream, Form const &copy);