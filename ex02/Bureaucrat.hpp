/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:52:29 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/07 12:38:57 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

#define COLOR "\033[;"
#define RED "31m"
#define GREEN "32m"
#define YELLOW "33m"
#define BLUE "34m"
#define MAGENTA "35m"
#define CYAN "36m"
#define B_RED "41m"
#define B_GREEN "42m"
#define B_YELLOW "43m"
#define B_BLUE	"44m"
#define RESET "\033[0m"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();
		const std::string	&getName() const;
		const int	&getGrade() const;
		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(Form* form);
		
		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char * what()  const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char * what() const throw();
		};


	private:
		std::string	_name;
		int	_grade;
				
};

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const &copy);