/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:11:41 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/02 13:12:34 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>  
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();

		virtual void	beSigned(Bureaucrat *rob);
		virtual void execute(Bureaucrat const & executor) const;
		std::string	getTarget(void) const;

};
