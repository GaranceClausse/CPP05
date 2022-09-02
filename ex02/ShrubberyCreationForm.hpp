/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:11:41 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/02 15:38:15 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : virtual public Form
{
private:
		std::string _target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	virtual ~ShrubberyCreationForm();

	virtual void	beSigned(Bureaucrat *rob);
	virtual void			action();

	std::string	ShrubberyCreationForm::getTarget(void) const;
};
