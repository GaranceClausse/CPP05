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

int	main()
{
	Bureaucrat* a = new Bureaucrat("Roger", 138);
	const Bureaucrat &b = *a;
	Form*	form1 = new ShrubberyCreationForm("Tree Form");

	try
	{	
		std::cout << std::endl;
		form1->execute(b);
		std::cout << std::endl;
		a->signForm(form1);
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	try
	{	
		std::cout << std::endl;
		a->signForm(form1);
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	try
	{		
		std::cout << std::endl;
		
		std::cout << "Form is now signed? " << (form1->getSigned() ? COLOR GREEN "yes" : COLOR RED "no" ) << COLOR RESET << std::endl<< std::endl;
		form1->execute(b);
		std::cout << std::endl;
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	try
	{		
		std::cout << std::endl;
		a->incrementGrade();
		form1->execute(b);
		std::cout << std::endl;
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	delete form1;
	delete a;

	std::cout << std::endl;
	std::cout << COLOR YELLOW << "************************************************************************" << COLOR RESET<< std::endl;
	std::cout << std::endl;

	Bureaucrat* office2 = new Bureaucrat("Patrick", 38);
	const Bureaucrat &cpy = *office2;
	Form*	form2 = new RobotomyRequestForm("Frankenwhaaat");

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

	
	std::cout << std::endl;
	std::cout << COLOR YELLOW << "************************************************************************" << COLOR RESET<< std::endl;
	std::cout << std::endl;

	Bureaucrat* office3 = new Bureaucrat("Emmanuel", 6);
	const Bureaucrat &cpy2 = *office3;
	Form*	form3 = new PresidentialPardonForm("Jesse James");

	try
	{		
		std::cout << std::endl;
		office3->signForm(form3);
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	try
	{		
		std::cout << std::endl;
		
		std::cout << "Form is now signed? " << (form3->getSigned() ? COLOR GREEN "yes" : COLOR RED "no" ) << COLOR RESET << std::endl<< std::endl;
		form3->execute(cpy2);
		std::cout << std::endl;
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	try
	{		
		std::cout << std::endl;
		office3->incrementGrade();
		form3->execute(cpy2);
		std::cout << std::endl;
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}


	delete form3;
	delete office3;

	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotquest", "Bender");
	delete rrf;
}