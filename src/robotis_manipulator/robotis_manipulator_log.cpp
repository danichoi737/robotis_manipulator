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


void RM_LOG::PRINT(STRING str, STRING color)
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
void RM_LOG::PRINT(STRING str, double data, uint8_t point, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
  DEBUG.print(data, point);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s %.*lf", str.c_str(), point, data);
  printf(ANSI_COLOR_RESET);
#endif
}
void RM_LOG::PRINT(const char* str, STRING color)
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
void RM_LOG::PRINT(const char* str, double data, uint8_t point, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
  DEBUG.print(data, point);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s %.*lf", str, point, data);
  printf(ANSI_COLOR_RESET);
#endif
}


void RM_LOG::PRINTLN(STRING str, STRING color)
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
void RM_LOG::PRINTLN(STRING str, double data, uint8_t point, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
  DEBUG.println(data, point);
#else
     if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s %.*lf\n", str.c_str(), point, data);
  printf(ANSI_COLOR_RESET);
#endif
}
void RM_LOG::PRINTLN(const char* str, STRING color)
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
void RM_LOG::PRINTLN(const char* str, double data, uint8_t point, STRING color)
{
#if defined(__OPENCR__)
  DEBUG.print(str);
  DEBUG.println(data, point);
#else
       if(color == "RED")      printf(ANSI_COLOR_RED);
  else if(color == "GREEN")    printf(ANSI_COLOR_GREEN);
  else if(color == "YELLOW")   printf(ANSI_COLOR_YELLOW);
  else if(color == "BLUE")     printf(ANSI_COLOR_BLUE);
  else if(color == "MAGENTA")  printf(ANSI_COLOR_MAGENTA);
  else if(color == "CYAN")     printf(ANSI_COLOR_CYAN);
  printf("%s %.*lf\n", str, point, data);
  printf(ANSI_COLOR_RESET);
#endif
}

void RM_LOG::INFO(STRING str)
{
#if defined(__OPENCR__)
  DEBUG.print("[INFO] ");
  DEBUG.println(str);
#else
  printf("[INFO] %s\n", str.c_str());
#endif
}
void RM_LOG::INFO(STRING str, double data, uint8_t point)
{
#if defined(__OPENCR__)
  DEBUG.print("[INFO] ");
  DEBUG.print(str);
  DEBUG.println(data, point);
#else
  printf("[INFO] %s %.*lf\n", str.c_str(), point, data);
#endif
}
void RM_LOG::INFO(const char* str)
{
#if defined(__OPENCR__)
  DEBUG.print("[INFO] ");
  DEBUG.println(str);
#else
  printf("[INFO] %s\n", str);
#endif
}
void RM_LOG::INFO(const char* str, double data, uint8_t point)
{
#if defined(__OPENCR__)
  DEBUG.print("[INFO] ");
  DEBUG.print(str);
  DEBUG.println(data, point);
#else
  printf("[INFO] %s %.*lf\n", str, point, data);
#endif
}
void RM_LOG::WARN(STRING str)
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
void RM_LOG::WARN(STRING str, double data, uint8_t point)
{
#if defined(__OPENCR__)
  DEBUG.print("[WARN] ");
  DEBUG.print(str);
  DEBUG.println(data, point);
#else
  printf(ANSI_COLOR_YELLOW);
  printf("[WARN] %s %.*lf\n",str.c_str(), point, data);
  printf(ANSI_COLOR_RESET);
#endif
}
void RM_LOG::WARN(const char* str)
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
void RM_LOG::WARN(const char* str, double data, uint8_t point)
{
#if defined(__OPENCR__)
  DEBUG.print("[WARN] ");
  DEBUG.print(str);
  DEBUG.println(data, point);
#else
  printf(ANSI_COLOR_YELLOW);
  printf("[WARN] %s %.*lf\n", str, point, data);
  printf(ANSI_COLOR_RESET);
#endif
}
void RM_LOG::ERROR(STRING str)
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
void RM_LOG::ERROR(STRING str, double data, uint8_t point)
{
#if defined(__OPENCR__)
  DEBUG.print("[ERROR] ");
  DEBUG.print(str);
  DEBUG.println(data, point);
#else
  printf(ANSI_COLOR_RED);
  printf("[ERROR] %s %.*lf\n", str.c_str(), point, data);
  printf(ANSI_COLOR_RESET);
#endif
}

void RM_LOG::ERROR(const char* str)
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
void RM_LOG::ERROR(const char* str, double data, uint8_t point)
{
#if defined(__OPENCR__)
  DEBUG.print("[ERROR] ");
  DEBUG.print(str);
  DEBUG.println(data, point);
#else
  printf(ANSI_COLOR_RED);
  printf("[ERROR] %s %.*lf\n", str, point, data);
  printf(ANSI_COLOR_RESET);
#endif
}