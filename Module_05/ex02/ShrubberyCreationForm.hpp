/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:36:47 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 13:39:36 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator= (const ShrubberyCreationForm&);

		const	std::string&	getTarget(void) const;
		void	ShrubberyAction(void) const;
		void	execute(Bureaucrat const & executor) const;

		class FileCreationException : public std::exception
		{
			public:
				const char* what() const throw();
		} FileCreationException;
};
