/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers_test.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:28:54 by charles           #+#    #+#             */
/*   Updated: 2020/04/26 14:45:27 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_TEST_HPP
#define FT_CONTAINERS_TEST_HPP

#include <algorithm>
#include <iostream>
#include <string>

#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../src/vector.hpp"

static pid_t testSegvPid;
extern std::string testName;
extern std::string testContainer;

#define SANDBOX(x)                                                             \
  do {                                                                         \
    testSegvPid = fork();                                                      \
    if (testSegvPid == -1)                                                     \
      abort();                                                                 \
    if (testSegvPid == 0) {                                                    \
      do {                                                                     \
        (void)(x);                                                             \
      } while (0);                                                             \
      exit(EXIT_SUCCESS);                                                      \
    }                                                                          \
    wait(&testSegvPid);                                                        \
  } while (0)

#define ASSERT(x)                                                              \
  do {                                                                         \
    SANDBOX(x);                                                                \
    if (!WIFEXITED(testSegvPid))                                               \
      log("\e[41m[FAIL SEGV  ] \e[0m", __FILE__, __LINE__, #x);                           \
    else if (!(x))                                                             \
      log("\e[0;31m[FAIL ASSERT] \e[0m", __FILE__, __LINE__, #x);                           \
    else                                                                       \
      log("\e[0;32m[PASS       ] \e[0m", __FILE__, __LINE__, #x);                           \
  } while (0)

#define TEST_SEGV(x)                                                           \
  do {                                                                         \
    SANDBOX(x);                                                                \
    if (!WIFEXITED(testSegvPid))                                               \
      log("\e[41m[FAIL SEGV  ] \e[0m", __FILE__, __LINE__, #x);                           \
    else                                                                       \
      log("\e[0;32m[PASS       ] \e[0m", __FILE__, __LINE__, #x);                           \
  } while (0)

/*
** log.cpp
*/

void log(const std::string &prefix, const std::string &filename, int lineNum,
         const std::string &code);

/*
** vector_test.cpp
*/

void vectorTest();

/*
** list_test.cpp
*/

/*
** stack_test.cpp
*/

#endif
