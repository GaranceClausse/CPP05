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
		a->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException)
	{
		std::cout << "ya qqc que jai pas compris..." << std::endl;
	}

	
	
}