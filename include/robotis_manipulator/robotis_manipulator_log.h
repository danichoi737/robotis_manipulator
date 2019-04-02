/*******************************************************************************
* Copyright 2018 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Darby Lim, Hye-Jong KIM, Ryan Shim, Yong-Ho Na */

/**
 * @file robotis_manipulator_log.h
 * @brief
 * @details
 */

#ifndef ROBOTIS_MANIPULATOR_LOG_H
#define ROBOTIS_MANIPULATOR_LOG_H

#include <unistd.h>
#include <vector>

#if defined(__OPENCR__)
  #include <Eigen.h>
  #include <WString.h>
  #include "variant.h"

  #define DEBUG SerialBT2
#else
  #include <string>

  #define ANSI_COLOR_RED     "\x1b[31m"
  #define ANSI_COLOR_GREEN   "\x1b[32m"
  #define ANSI_COLOR_YELLOW  "\x1b[33m"
  #define ANSI_COLOR_BLUE    "\x1b[34m"
  #define ANSI_COLOR_MAGENTA "\x1b[35m"
  #define ANSI_COLOR_CYAN    "\x1b[36m"
  #define ANSI_COLOR_RESET   "\x1b[0m"
#endif

#if defined(__OPENCR__)
  typedef String		  STRING;
#else
  typedef std::string STRING;
#endif

namespace robotis_manipulator
{
namespace log{
  /**
   * @brief print
   * @param str
   * @param color
   */
  void print(STRING str, STRING color = "DEFAULT");
  /**
   * @brief print
   * @param str
   * @param data
   * @param decimal_point
   * @param color
   */
  void print(STRING str, double data, uint8_t decimal_point = 3, STRING color = "DEFAULT");
  /**
   * @brief print
   * @param str
   * @param color
   */
  void print(const char* str, STRING color = "DEFAULT");
  /**
   * @brief print
   * @param str
   * @param data
   * @param decimal_point
   * @param color
   */
  void print(const char* str, double data, uint8_t decimal_point = 3, STRING color = "DEFAULT");

  /**
   * @brief println
   * @param str
   * @param color
   */
  void println(STRING str, STRING color = "DEFAULT");
  /**
   * @brief println
   * @param str
   * @param data
   * @param decimal_point
   * @param color
   */
  void println(STRING str, double data, uint8_t decimal_point = 3, STRING color = "DEFAULT");
  /**
   * @brief println
   * @param str
   * @param color
   */
  void println(const char* str, STRING color = "DEFAULT");
  /**
   * @brief println
   * @param str
   * @param data
   * @param decimal_point
   * @param color
   */
  void println(const char* str, double data, uint8_t decimal_point = 3, STRING color = "DEFAULT");

  /**
   * @brief info
   * @param str
   */
  void info(STRING str);
  /**
   * @brief info
   * @param str
   * @param data
   * @param decimal_point
   */
  void info(STRING str, double data, uint8_t decimal_point = 3);
  /**
   * @brief info
   * @param str
   */
  void info(const char* str);
  /**
   * @brief info
   * @param str
   * @param data
   * @param decimal_point
   */
  void info(const char* str, double data, uint8_t decimal_point = 3);

  /**
   * @brief warn
   * @param str
   */
  void warn(STRING str);
  /**
   * @brief warn
   * @param str
   * @param data
   * @param decimal_point
   */
  void warn(STRING str, double data, uint8_t decimal_point = 3);
  /**
   * @brief warn
   * @param str
   */
  void warn(const char* str);
  /**
   * @brief warn
   * @param str
   * @param data
   * @param decimal_point
   */
  void warn(const char* str, double data, uint8_t decimal_point = 3);

  /**
   * @brief error
   * @param str
   */
  void error(STRING str);
  /**
   * @brief error
   * @param str
   * @param data
   * @param decimal_point
   */
  void error(STRING str, double data, uint8_t decimal_point = 3);
  /**
   * @brief error
   * @param str
   */
  void error(const char* str);
  /**
   * @brief error
   * @param str
   * @param data
   * @param decimal_point
   */
  void error(const char* str, double data, uint8_t decimal_point = 3);

  /**
   * @brief print_vector
   * @param vec
   * @param decimal_point
   */
  template <typename T> void print_vector(std::vector<T> &vec, uint8_t decimal_point = 3)
  {
  #if defined(__OPENCR__)
    DEBUG.print("(");
    for (uint8_t i = 0; i < vec.size(); i++)
    {
      DEBUG.print(vec.at(i), decimal_point);
      if(i != vec.size()-1)
        DEBUG.print(", ");
      else
        DEBUG.println(")");
    }
  #else
    printf("(");
    for (uint8_t i = 0; i < vec.size(); i++)
    {
      printf("%.*lf", decimal_point, vec.at(i));
      if(i != vec.size()-1)
        printf(", ");
      else
        printf(")\n");
    }
  #endif
  }

  /**
   * @brief print_vector
   * @param vec
   * @param decimal_point
   */
  template <typename vector> void print_vector(vector &vec, uint8_t decimal_point = 3)
  {
  #if defined(__OPENCR__)
    DEBUG.print("(");
    for (uint8_t i = 0; i < vec.size(); i++)
    {
      DEBUG.print(vec(i), decimal_point);
      if(i != vec.size()-1)
        DEBUG.print(", ");
      else
        DEBUG.println(")");
    }
  #else
    printf("(");
    for (uint8_t i = 0; i < vec.size(); i++)
    {
      printf("%.*lf", decimal_point, vec(i));
      if(i != vec.size()-1)
        printf(", ");
      else
        printf(")\n");
    }
  #endif
  }

  /**
   * @brief print_matrix
   * @param m
   * @param decimal_point
   */
  template <typename matrix> void print_matrix(matrix &m, uint8_t decimal_point = 3)
  {
  #if defined(__OPENCR__)

    for (uint8_t i = 0; i < m.rows(); i++)
    {
      if(i == 0)
        DEBUG.print("(");
      else
        DEBUG.print(" ");
      for (uint8_t j = 0; j < m.cols(); j++)
      {
        DEBUG.print(m(i, j), decimal_point);
        if(j != m.cols()-1)
          DEBUG.print(", ");
      }
      if(i != m.rows()-1)
        DEBUG.println("");
      else
        DEBUG.println(")");
    }
  #else

    for (uint8_t i = 0; i < m.rows(); i++)
    {
      if(i == 0)
        printf("(");
      else
        printf(" ");
      for (uint8_t j = 0; j < m.cols(); j++)
      {
        printf("%.*lf", decimal_point, m(i, j));
        if(j != m.cols()-1)
          printf(", ");
      }
      if(i != m.rows()-1)
        printf("\n");
      else
        printf(")\n");
    }
  #endif
  }

} //log
} //robotis_manipulator

#endif // ROBOTIS_MANIPULATOR_LOG_H
