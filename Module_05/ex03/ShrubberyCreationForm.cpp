/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:36:44 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 18:46:34 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137)
{
	this->target = "defaultTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target): AForm("Shrubbery", 145, 137)
{
	this->target = _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubbery) : AForm(shrubbery.getName(), shrubbery.getGradeRequiredtoSign(), shrubbery.getGradeRequiredtoExcute())
{
	*this = shrubbery;	
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubbery)
{
	if (this != &shrubbery)
		this->target = shrubbery.target;
	return (*this);
}

const char* ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return "failed to creat the output file!";
}

void printTree(std::ofstream& os)
{
	std::string tree = 
	"                            ___\n"
	"                _,-'\"\"   \"\"\"\"`--.            \n"
	"             ,-'          __,,-- \\            \n"
	"           ,'    __,--\"\"\"\"dF      \\)            \n"
	"          /   .-\"Hb_,--\"\"dF      /            \n"
	"        ,'       _Hb ___dF\"-._,-'            \n"
	"      ,'      _,-\"\"\"\"   \"\"--..__            \n"
	"     (     ,-'                  `.            \n"
	"      `._,'     _   _             ;            \n"
	"       ,'     ,' `-'Hb-.___..._,-'            \n"
	"       \\    ,'\"Hb.-'HH`-.dHF\"            \n"
	"        `--'   \"Hb  HH  dF\"            \n"
	"                \"Hb HH dF            \n"
	"                 \"HbHHdF            \n"
	"                  |HHHF            \n"
	"                  |HHH|            \n"
	"                  |HHH|            \n"
	"                  |HHH|            \n"
	"                  |HHH|            \n"
	"                  dHHHb            \n"
	"                .dFd|bHb.               o\n"
	"      o       .dHFdH|HbTHb.          o /\n"
	" \\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n"
	"##########################################\n";
	
	os << tree;
}

void	ShrubberyCreationForm::ShrubberyAction(void) const
{
	std::ofstream	out_file;

	out_file.open(this->target + "_shrubbery");
	if (!out_file.is_open())
	{
		std::cerr << "can't create the file " << this->target  << "_shrubbery" << std::endl;
		throw FileCreationException;
	}
	printTree(out_file);
	out_file.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);
	try
	{
		ShrubberyAction();
		std::cout << executor.getName() << " executed " << this->target << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const std::string& ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}