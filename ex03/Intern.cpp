/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:59:22 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/12 15:18:10 by gclausse         ###   ########.fr       */
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

Form	*Intern::makeForm(std::string form, std::string target)
{
	Form * random_form(NULL);
	std::string tab[4] = {"presidential pardon", "robotomy request", "shrubbery creation", "invalid"};
	int i = 0;
	while (i < 4 && form.compare(tab[i]) != 0)
		i++;
	switch (i)
	{
		case 0:
		std::cout << "Intern creates " << form << std::endl;
		random_form = new PresidentialPardonForm(target);
		break;
		case 1:
		std::cout << "Intern creates " << form << std::endl;
		random_form = new RobotomyRequestForm(target);
		break;
		case 2:
		std::cout << "Intern creates " << form << std::endl;
		random_form = new ShrubberyCreationForm(target);
		break;
		default:
		std::cout << "You can't create a " << form << " form because it doesn't exists" << std::endl;
	}
		
	
	return random_form;
}