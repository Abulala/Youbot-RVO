// ptracking_wrapper.cpp --- 
// 
// Filename: agents_dispatcher.cpp
// Description: Main thread
// Author: Federico Boniardi
// Maintainer: Federico Boniardi
// Created: Mon Jul  7 23:43:03 2014 (+0100)
// Version: 0.1.0
// Last-Updated: Tue Jul 8 02:24:25 2014 (+0100)
//           By: Federico Boniardi
//     Update #: 1
// URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
//  
// 
// 
// 

// Change Log:
//   changed folders and namespaces to ptracking_wrapper
// 
// 
// 
// The MIT License (MIT)
// 
// Copyright (c) 2014 Federico Boniardi
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// 
// 

// Code:

#include "ptracking_wrapper/AgentsDispatcher.hpp"

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "ptracking_wrapper");
  ptracking_wrapper::AgentsDispatcher agent_dispatcher;
  ros::spin();
  return 0;
}


// 
// agents_dispatcher.cpp ends here
