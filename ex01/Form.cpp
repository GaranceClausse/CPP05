/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:17:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/01 17:26:42 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(/* args */)
{
}

Form::~Form()
{
}


std::ostream&	operator<<(std::ostream& stream, Form const &copy)
{
	stream << copy.getName();
	stream << copy.getSigned();
	stream << copy.getSignGrade();
	stream << copy.getExecGrade();
	return (stream);
}