/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:59:22 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/12 16:00:48 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor "  << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	std::cout <<COLOR  B_GREEN "Intern Copy constructor" COLOR RESET  << std::endl;
	*this = copy;
}

Intern& Intern::operator=(const Intern &copy)
{
	std::cout << "Intern Operator = " << std::endl;
	(void)copy;
	return *this;
}

static Form	*newPPForm(std::string const &str)
{
	return (new PresidentialPardonForm(str));
}

static Form	*newRRForm(std::string const &str)
{
	return (new RobotomyRequestForm(str));
}

static Form	*newSCForm(std::string const &str)
{
	return (new ShrubberyCreationForm(str));
}

Form	*Intern::makeForm(std::string form, std::string target)
{
	Form * random_form(NULL);
	Form *(*fctptr[3])(std::string const &str) = {
		&newPPForm, &newRRForm, &newSCForm
	};
	std::string tab[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (tab[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			random_form = fctptr[i](target);
			return random_form ;			
		}
	}
	std::cout << "You can't create a " << form << " form because it doesn't exists" << std::endl;	
	return random_form;
}