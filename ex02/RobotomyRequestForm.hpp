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

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		/* data */
	public:
		RobotomyRequestForm(/* args */);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();


		std::string	getName(void) const;
		bool	getSigned(void) const;
		int		getSignGrade(void) const;
		int		getExecGrade(void) const;
		void	beSigned(Bureaucrat *rob);
};
