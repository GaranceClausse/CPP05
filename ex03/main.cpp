/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:19:00 by gclausse          #+#    #+#             */
/*   Updated: 2022/08/19 18:19:00 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void	launch_exec(Form * form2)
{
	if (form2 == NULL)
		return ;
	Bureaucrat* office2 = new Bureaucrat("Patrick", 38);
	const Bureaucrat &cpy = *office2;
	try
	{		
		std::cout << std::endl;
		office2->signForm(form2);
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	try
	{		
		std::cout << std::endl;
		
		std::cout << "Form is now signed? " << (form2->getSigned() ? COLOR GREEN "yes" : COLOR RED "no" ) << COLOR RESET << std::endl<< std::endl;
		form2->execute(cpy);
		std::cout << std::endl;
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	delete form2;
	delete office2;
}

int	main()
{

	Intern someRandomIntern;
	Form* form2;
	form2 = someRandomIntern.makeForm("shrubbery cration", "Bender");
	launch_exec(form2);	
}