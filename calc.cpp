/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btigran <btigran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:08:17 by btigran           #+#    #+#             */
/*   Updated: 2025/04/17 18:27:24 by btigran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

string get_input()
{
	string str = NULL;
	
	std::cin >> str;
	
	return (str);
}


bool check_input(string formula)
{

	int    length = 0;
	int    parenthesis_count = 0;
	int    j = 0;
	string allowed_characters = "0123456789.+-*/() ";
	string operands = "+-*/";
	//string digits = "0123456789";
	
	length = formula.length();
	for (int i = 0; i < length; i++)
	{
		if (!(allowed_characters.find(formula[i])))
		{
			return (false);
		}
		if (operands.find(formula[i]))
		{
			j = i;
			while (j < length - 1 && formula[j] == ' ')
			{
				j++;
			}
			if (formula[j] != '(' && (formula[j] > '9' || formula[j] < '0'))
			{
				return (false);
			}
			j = i;
			while (j > 0 && formula[j] == ' ')
			{
				j--;
			}
			if (formula[j] != '(' && (formula[j] > '9' || formula[j] < '0'))
			{
				return (false);
			}
		}
		if (formula[i] == '(')
		{
			parenthesis_count++;
		}
		if (formula[i] == ')')
		{
			parenthesis_count--;
		}
		if (parenthesis_count < 0)
		{
			return (false);
		}
	}
	if (parenthesis_count != 0)
	{
		return (false);
	}
	
	return (true);
}


void print(string str)
{
	std::cout << str << std:endln;
}


string parse_and_calc(string formula)
{
	int    length = 0;
	int    start_parenthesis = 0;
	int    size = 0;
	string results = "";
	//string simplified = formula;

	length = formula.length();
	for (int i = 0; i < length; i++)
	{
		if (formula[i] == '(')
		{
			start_parenthesis = i;
		}
		if (formula[i] == ')')
		{
			size = i - start_parenthesis - 1;
			results = parse_and_calc(formula.substr(start_parenthesis + 1, size));
			formula.replace(start_parenthesis, size + 1, results);
			length = formula.length();
			i = start_parenthesis + results.length();
		}
	}
	results = basic_calculator(formula);
	
	return (results);
}
