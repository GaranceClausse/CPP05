/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:59:22 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/12 15:43:24 by gclausse         ###   ########.fr       */
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

static Form	*newPPForm(std::string const &str)
{
	return (new PresidentialPardonForm(str));
}

static Form	*newRRForm(std::string const &str)
{
	return (new PresidentialPardonForm(str));
}

static Form	*newSCForm(std::string const &str)
{
	return (new PresidentialPardonForm(str));
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