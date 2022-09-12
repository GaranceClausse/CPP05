/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:59:24 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/12 15:04:29 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

#include <fstream>

class Form;
class Bureaucrat;

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		Intern &operator=(const Intern &copy);
		~Intern();
		Form	*makeForm(std::string form, std::string target);
		class NotAForm : public std::exception
	{
	public:
		virtual const char * what()  const throw();
	};
						
};
