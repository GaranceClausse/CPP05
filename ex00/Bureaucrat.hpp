/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:52:29 by gclausse          #+#    #+#             */
/*   Updated: 2022/08/19 18:31:03 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

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

class Bureaucrat
{
	public:
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();
		const std::string	&getName() const;
		const int	&getGrade() const;
		void	incrementGrade(void);
		void	decrementGrade(void);
		
		class GradeTooHighException
		{
		private:
			/* data */
		public:
			GradeTooHighException(/* args */) {
				std::cout << "You can't go higher than God!" << std::endl;
			};
			~GradeTooHighException();
		};
		
		class GradeTooLowException
		{
		private:
			/* data */
		public:
			GradeTooLowException(/* args */){
				std::cout << "You can't go lower than Satan!" << std::endl;
			};
			~GradeTooLowException();
		};


	private:
		std::string	_name;
		int	_grade;
				
};
