/*
* Definitions.h
* HRVO Library
*
* Copyright (c) 2009-2014 University of North Carolina at Chapel Hill.
* All rights reserved.
*
* Permission to use, copy, modify, and distribute this software and its
* documentation for educational, non-commercial research, and non-profit
* purposes, without fee, and without a written agreement is hereby granted,
* provided that the above copyright notice, this paragraph, and the following
* four paragraphs appear in all copies.
*
* Permission to incorporate this software into commercial products may be
* obtained by contacting the authors <geom@cs.unc.edu> or the Office of
* Technology Development at the University of North Carolina at Chapel Hill
* <otd@unc.edu>.
*
* This software program and documentation are copyrighted by the University of
* North Carolina at Chapel Hill. The software program and documentation are
* supplied "as is," without any accompanying services from the University of
* North Carolina at Chapel Hill or the authors. The University of North
* Carolina at Chapel Hill and the authors do not warrant that the operation of
* the program will be uninterrupted or error-free. The end-user understands
* that the program was developed for research purposes and is advised not to
* rely exclusively on the program for any reason.
*
* IN NO EVENT SHALL THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR THE
* AUTHORS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR
* CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF THIS
* SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF NORTH CAROLINA AT
* CHAPEL HILL OR THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
* THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE AUTHORS SPECIFICALLY
* DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE AND ANY
* STATUTORY WARRANTY OF NON-INFRINGEMENT. THE SOFTWARE PROVIDED HEREUNDER IS ON
* AN "AS IS" BASIS, AND THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE
* AUTHORS HAVE NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
* ENHANCEMENTS, OR MODIFICATIONS.
*
* Please send all bug reports to <geom@cs.unc.edu>.
*
* The authors may be contacted via:
*
* Jamie Snape, Jur van den Berg, Stephen J. Guy, and Dinesh Manocha
* Dept. of Computer Science
* 201 S. Columbia St.
* Frederick P. Brooks, Jr. Computer Science Bldg.
* Chapel Hill, N.C. 27599-3175
* United States of America
*
* <http://gamma.cs.unc.edu/HRVO/>
*/

/**
* \file   Definitions.h
* \brief  Declares and defines internal functions.
*/

#ifndef HRVO_DEFINITIONS_H_
#define HRVO_DEFINITIONS_H_

#ifndef HRVO_VECTOR2_H_
#include "Vector2.h"
#endif

#include <string>
#include <sstream>

namespace hrvo {
  /**
  * \brief  A sufficiently small positive float.
  */
  const float HRVO_EPSILON = 0.00001f;


  #define SIMAGENT 0
  #define PERSON 1
  #define ROBOT 2

  #define WAIT_FOR_START 1
  #define HRVO_OUTPUT_TIME_AND_POSITIONS 1

  #define GOAL_SUM_PRIOR 1.0f


  const Vector2 STOP = Vector2(0.0f, 0.0f);
  const Vector2 START_POS1 = Vector2(-1.5f, 0.0f);
  const Vector2 START_POS2 = Vector2(1.5f, 0.0f);

  const float SIM_TIME_STEP = 0.1f;

  const float NEIGHBOR_DIST = 5.0f;
  const std::size_t MAX_NEIGHBORS = 10;
  const float AGENT_RADIUS = 0.5f;
  const float GOAL_RADIUS = 0.5f;
  const float PREF_SPEED = 0.3f;
  const float PREF_PEOPLE_SPEED = 1.0f;
  const float MAX_SPEED = 0.6f;
  const float MAX_PEOPLE_SPEED = 2.0f;
  const float MAX_ACCELERATION = 0.6f;
  const float MAX_PEOPLE_ACCELERATION = 2.0f;

  const std::size_t THIS_ROBOT = 0;

  const int ROS_FREQ = 10;

  enum Actor{
    YOUBOT_1 = 0,
    YOUBOT_2 ,
    YOUBOT_3 ,
    YOUBOT_4 ,
    YOUBOT_5
  };

  const char* getActorName(enum Actor actorID);

  std::string intToString(int i);


  /**
  * \brief      Computes the square of a float.
  * \param[in]  scalar  The float to be squared.
  * \return     The square of the float.
  */
  inline float sqr(float scalar)
  {
    return scalar * scalar;
  }
}

#endif /* HRVO_DEFINITIONS_H_ */
