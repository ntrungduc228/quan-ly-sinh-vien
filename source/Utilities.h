#ifndef __UITILITIES__
#define __UITILITIES__

#pragma once

string convertIntToString(int so){
	stringstream ss;
	ss << so;
	string str;
	str = ss.str();
	return str; 
}

#endif
