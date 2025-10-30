# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    readme.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 19:51:55 by jpaim-so          #+#    #+#              #
#    Updated: 2025/10/30 19:53:08 by jpaim-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

We must be able to compile this project with and without the -D
BUFFER_SIZE flag in addition to the usual flags. You may choose any
default value you prefer.

You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

---

Does your function still work if the BUFFER_SIZE value is 9999? If
it is 1? 10000000? Do you know why?

---

Read as little data as possible each time get_next_line() is called.

If a newline character is encountered, return the current line
immediately.

Don’t read the whole file and then process each line.
