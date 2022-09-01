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
	try
	{
		Bureaucrat* a = new Bureaucrat(13);
		Bureaucrat* b = new Bureaucrat(1);
		Bureaucrat* c = new Bureaucrat(150);
		std::cout << std::endl;
		a->incrementGrade();
		b->incrementGrade();
		c->decrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException gth) {
		std::cout << gth.what();		
	}
	catch(Bureaucrat::GradeTooLowException gtl) {
		std::cout << gtl.what();		
	}


	
	
}