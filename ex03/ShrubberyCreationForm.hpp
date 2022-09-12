/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:11:41 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/07 12:29:44 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <fstream>


class ShrubberyCreationForm : public Form
{
private:
		std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	virtual ~ShrubberyCreationForm();

	virtual void	beSigned(Bureaucrat *rob);
	virtual void execute(Bureaucrat const & executor) const;
	std::string	getTarget(void) const;
};
