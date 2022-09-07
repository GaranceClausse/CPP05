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
	Bureaucrat* b = new Bureaucrat("Albert", 1);
	Bureaucrat* c = new Bureaucrat("Valerie", 150);


	try
	{
		
		std::cout << std::endl;
		a->incrementGrade();
		b->incrementGrade();
		c->decrementGrade();
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;		
	}
	std::cout << *b;
	Bureaucrat* d = new Bureaucrat("Jean-Eude", 150);
	try
	{
		
		std::cout << std::endl;
		d->decrementGrade();
	}
	catch(std::exception &e) {
		std::cout << COLOR RED << e.what() << COLOR RESET<< std::endl << std::endl;			
	}
	delete a;
	delete b;
	delete c;
	delete d;
}