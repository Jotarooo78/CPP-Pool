/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:38:38 by marvin            #+#    #+#             */
/*   Updated: 2025/12/08 15:38:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(0.0, 0.0);
    Point b(10.0, 0.0);
    Point c(0.0, 10.0);
    Point point(5.0, 4.0);

    bool res = bsp(a, b ,c, point);
    if (res == 1)
        std::cout << "true" << std::endl;
    else if (res == 0)
        std::cout << "false" << std::endl;
    return 0;
}
