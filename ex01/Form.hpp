/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:17:34 by gclausse          #+#    #+#             */
/*   Updated: 2022/09/01 17:20:19 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string _name;
		bool	sign = false;
		int		_sign_grade;
		int		_exec_grade;
		
	public:
		Form(/* args */);
		~Form();
};

