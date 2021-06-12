
#pragma once

string convertIntToString(int so){
	stringstream ss;
	ss << so;
	string str;
	str = ss.str();
	return str; 
}

string convertFloatToString(float so){
	stringstream ss;
	ss << so;
	string str;
	str = ss.str();
	return str;
}


