/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:17:34 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/01 17:27:42 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string _name;
		bool	sign = false;
		int		_sign_grade;
		int		_exec_grade;
		
	public:
		Form(/* args */);
		~Form();

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

td::ostream&	operator<<(std::ostream& stream, Form const &copy);