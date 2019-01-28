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

#include "../../include/robotis_manipulator/robotis_manipulator_log.h"

using namespace rm_log;

void print(STRING str, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s", str.c_str());
  printf(ANSI_COLOR_RESET);
#endif
}
void print(STRING str, double data, uint8_t decimal_point, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
  DEBUG.print(data, decimal_point);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s %.*lf", str.c_str(), decimal_point, data);
  printf(ANSI_COLOR_RESET);
#endif
}
void print(const char* str, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s", str);
  printf(ANSI_COLOR_RESET);
#endif
}
void print(const char* str, double data, uint8_t decimal_point, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
  DEBUG.print(data, decimal_point);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s %.*lf", str, decimal_point, data);
  printf(ANSI_COLOR_RESET);
#endif
}


void println(STRING str, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.println(str);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s\n", str.c_str());
  printf(ANSI_COLOR_RESET);
#endif
}
void println(STRING str, double data, uint8_t decimal_point, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
  DEBUG.println(data, decimal_point);
#else
     if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s %.*lf\n", str.c_str(), decimal_point, data);
  printf(ANSI_COLOR_RESET);
#endif
}
void println(const char* str, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.println(str);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s\n", str);
  printf(ANSI_COLOR_RESET);
#endif
}
void println(const char* str, double data, uint8_t decimal_point, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
  DEBUG.println(data, decimal_point);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s %.*lf\n", str, decimal_point, data);
  printf(ANSI_COLOR_RESET);
#endif
}

void info(STRING str)
{
#if defined(__OPENCR__)
  DEBUG.print("[INFO] ");
  DEBUG.println(str);
#else
  printf("[INFO] %s\n", str.c_str());
#endif
}
void info(STRING str, double data, uint8_t decimal_point)
{
#if defined(__OPENCR__)
  DEBUG.print("[INFO] ");
  DEBUG.print(str);
  DEBUG.println(data, decimal_point);
#else
  printf("[INFO] %s %.*lf\n", str.c_str(), decimal_point, data);
#endif
}
void info(const char* str)
{
#if defined(__OPENCR__)
  DEBUG.print("[INFO] ");
  DEBUG.println(str);
#else
  printf("[INFO] %s\n", str);
#endif
}
void info(const char* str, double data, uint8_t decimal_point)
{
#if defined(__OPENCR__)
  DEBUG.print("[INFO] ");
  DEBUG.print(str);
  DEBUG.println(data, decimal_point);
#else
  printf("[INFO] %s %.*lf\n", str, decimal_point, data);
#endif
}
void warn(STRING str)
{
#if defined(__OPENCR__)
  DEBUG.print("[WARN] ");
  DEBUG.println(str);
#else
  printf(ANSI_COLOR_YELLOW);
  printf("[WARN] %s\n", str.c_str());
  printf(ANSI_COLOR_RESET);
#endif
}
void warn(STRING str, double data, uint8_t decimal_point)
{
#if defined(__OPENCR__)
  DEBUG.print("[WARN] ");
  DEBUG.print(str);
  DEBUG.println(data, decimal_point);
#else
  printf(ANSI_COLOR_YELLOW);
  printf("[WARN] %s %.*lf\n",str.c_str(), decimal_point, data);
  printf(ANSI_COLOR_RESET);
#endif
}
void warn(const char* str)
{
#if defined(__OPENCR__)
  DEBUG.print("[WARN] ");
  DEBUG.println(str);
#else
  printf(ANSI_COLOR_YELLOW);
  printf("[WARN] %s\n", str);
  printf(ANSI_COLOR_RESET);
#endif
}
void warn(const char* str, double data, uint8_t decimal_point)
{
#if defined(__OPENCR__)
  DEBUG.print("[WARN] ");
  DEBUG.print(str);
  DEBUG.println(data, decimal_point);
#else
  printf(ANSI_COLOR_YELLOW);
  printf("[WARN] %s %.*lf\n", str, decimal_point, data);
  printf(ANSI_COLOR_RESET);
#endif
}
void error(STRING str)
{
#if defined(__OPENCR__)
  DEBUG.print("[ERROR] ");
  DEBUG.println(str);
#else
  printf(ANSI_COLOR_RED);
  printf("[ERROR] %s\n", str.c_str());
  printf(ANSI_COLOR_RESET);
#endif
}
void error(STRING str, double data, uint8_t decimal_point)
{
#if defined(__OPENCR__)
  DEBUG.print("[ERROR] ");
  DEBUG.print(str);
  DEBUG.println(data, decimal_point);
#else
  printf(ANSI_COLOR_RED);
  printf("[ERROR] %s %.*lf\n", str.c_str(), decimal_point, data);
  printf(ANSI_COLOR_RESET);
#endif
}

void error(const char* str)
{
#if defined(__OPENCR__)
  DEBUG.print("[ERROR] ");
  DEBUG.println(str);
#else
  printf(ANSI_COLOR_RED);
  printf("[ERROR] %s\n", str);
  printf(ANSI_COLOR_RESET);
#endif
}
void error(const char* str, double data, uint8_t decimal_point)
{
#if defined(__OPENCR__)
  DEBUG.print("[ERROR] ");
  DEBUG.print(str);
  DEBUG.println(data, decimal_point);
#else
  printf(ANSI_COLOR_RED);
  printf("[ERROR] %s %.*lf\n", str, decimal_point, data);
  printf(ANSI_COLOR_RESET);
#endif
}
