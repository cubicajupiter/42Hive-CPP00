/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:27:21 by jvalkama          #+#    #+#             */
/*   Updated: 2025/12/12 16:29:12 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MegaPhone.hpp"

int	main(int ac, char **av) {
	MegaPhone	mp;

	mp.amplify(mp.input(av));
	return 0;
}
