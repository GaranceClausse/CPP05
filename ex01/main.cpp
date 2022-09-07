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

int	main()
{
	Bureaucrat* a = new Bureaucrat("Roger", 13);
	Form*	form1 = new Form("Stupid form", 12, 6);

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
		
		std::cout << "Form is now signed? " << (form1->getSigned() ? COLOR GREEN "yes" : COLOR RED "no" COLOR RESET) << std::endl<< std::endl;
		a->incrementGrade();
		a->signForm(form1);
		std::cout << "Form is now signed? "  << (form1->getSigned() ? COLOR GREEN "yes" : COLOR RED "no"  ) << COLOR RESET << std::endl;
		std::cout << std::endl;
		a->signForm(form1);
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	delete form1;
	delete a;
}