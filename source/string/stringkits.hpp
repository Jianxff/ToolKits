/* ============================================================================

              __         .__                __   .__  __   
      _______/  |________|__| ____    ____ |  | _|__|/  |_ 
     /  ___/\   __\_  __ \  |/    \  / ___\|  |/ /  \   __\
     \___ \  |  |  |  | \/  |   |  \/ /_/  >    <|  ||  |  
    /____  > |__|  |__|  |__|___|  /\___  /|__|_ \__||__|  
         \/                      \//_____/      \/          
    
    
 Extended String Kits for Modern C++ 
 Version 1.0
 https://github.com/Jianxff/ToolKits

 Copyright 2023 Jianxff

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

============================================================================ */

#ifndef __STRINGKIT_HPP__
#define __STRINGKIT_HPP__

#include <iostream>
#include <vector>
/**
 * @brief erase space at head and tail of a string
 *
 * @param str string
 * @return std::string
 */
inline std::string Trim(std::string str){
    std::string temp = str;
    temp.erase(0, temp.find_first_not_of(" "));
    temp.erase(temp.find_last_not_of(" ") + 1);
    return temp;
}



/**
 * @brief split string by string
 *
 * @param str base string
 * @param sp split string
 * @return std::vector<std::string> splited string array
 */
inline std::vector<std::string> split(std::string str, std::string sp){
    std::vector<std::string> string_list;
    if(str.length() == 0)
        return string_list;
    
    std::string strs = str + sp;
	size_t pos = strs.find(sp);
	int step = sp.size();

	while (pos != strs.npos)
	{
		std::string temp = strs.substr(0, pos);
		string_list.push_back(temp);
		strs = strs.substr(pos + step, strs.size());
		pos = strs.find(sp);
	}
    return string_list;
}

/**
 * @brief split string by char
 * 
 * @param str base string
 * @param c split character
 * @return std::vector<std::string> 
 */
inline std::vector<std::string> split(std::string str, char c){
    std::vector<std::string> string_list;
    if(str.length() == 0)
        return string_list;

	std::string strs = str + c;
	size_t pos = strs.find(c);

	while (pos != strs.npos)
	{
		std::string temp = strs.substr(0, pos);
		string_list.push_back(temp);
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(c);
	}
    return string_list;
}

#endif;