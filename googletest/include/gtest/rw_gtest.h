/*
 * @file rw_gtest.h
 * @author Anil Gunturu (anil.gunturu@riftio.com)
 * @date 11/18/2013
 * @brief rift specific google test classes
 *
 * Copyright 2016 RIFT.IO Inc
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
 */


#ifndef __RW_GTEST_H__
#define __RW_GTEST_H__

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>

#define TEST_DESCRIPTION(desc) ::testing::Test::RecordProperty("description", desc)

#define MAX_FILENAME_SZ 64

class ConsoleCapture {
 private:
  static char filename[MAX_FILENAME_SZ]; 
  static int stdout_backup;
  static std::string capture_str;

  static int restore_stdout(void);
  static int redirect_stdout(void);
  static int stop_stdout_capture(void);

  /* Non public constructor so that class can't be 
   * instantiated */
  ConsoleCapture();
  ~ConsoleCapture();

 public:
  static int start_stdout_capture(void);
  static std::string get_capture_string(void);
};

#endif // __RW_GTEST_H__
