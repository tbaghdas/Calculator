/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btigran <btigran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:29:43 by btigran           #+#    #+#             */
/*   Updated: 2025/04/17 17:00:37 by btigran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int main()
{
	string formula;
	string result;
	string err_massage;
	
	formula = get_input();
	if (!check_input(formula))
	{
		err_massage = "Please input the correct formula, you can use only +, -, *, /, '.', ' ', (, ) symbols and all digits";
		print(err_massage);
		return (0);
	}
	result = parse_and_calc(formula);
	print(result);
}