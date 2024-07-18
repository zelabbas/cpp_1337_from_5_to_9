/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:36:35 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 18:41:29 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string);
		PresidentialPardonForm(const PresidentialPardonForm&);
		~PresidentialPardonForm(void);

		PresidentialPardonForm& operator= (const PresidentialPardonForm&);
		
		const std::string&	getTarget(void) const;
		void	PresidentialPardonFormAction(void) const;
		void	execute(Bureaucrat const & executor) const;
};