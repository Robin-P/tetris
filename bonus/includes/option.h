/*
** option.h for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Mar 10 11:03:36 2017 benoit pingris
** Last update Mon Mar 13 13:03:05 2017 benoit pingris
*/

#ifndef OPTION_H_
# define OPTION_H_

#include <getopt.h>

struct option	options[] =
  {
    {"kl", required_argument, 0, 0},
    {"key-left", required_argument, 0, 1},
    {"kr", required_argument, 0, 2},
    {"key-right", required_argument, 0, 3},
    {"kt", required_argument, 0, 4},
    {"key-turn", required_argument, 0, 5},
    {"kd", required_argument, 0, 6},
    {"key-drop", required_argument, 0, 7},
    {"kp", required_argument, 0, 8},
    {"key-pause", required_argument, 0, 9},
    {"l", required_argument, 0, 10},
    {"level=", required_argument, 0, 11},
    {"map-size", required_argument, 0, 12},
    {"d", no_argument, 0, 13},
    {"debug", no_argument, 0, 14},
    {"w", no_argument, 0, 15},
    {"without-next", no_argument, 0, 16},
    {"kq", required_argument, 0, 17},
    {"key-quit", required_argument, 0, 18},
    {"help", no_argument, 0, 19},
    {0, 0, 0, 0},
  };

#endif /* !OPTION_H_ */
