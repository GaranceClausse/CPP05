/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:11:41 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/02 13:12:34 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(/* args */);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		virtual ~PresidentialPardonForm();


		virtual std::string	getName(void) const;
		virtual bool	getSigned(void) const;
		virtual int		getSignGrade(void) const;
		virtual int		getExecGrade(void) const;
		virtual void	beSigned(Bureaucrat *rob);
};
