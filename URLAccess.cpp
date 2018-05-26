#include <iostream>
#include <sstream>
#include <string>
#include <curl/curl.h>
using namespace std;

string data;

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{
	for (int c=0;c<size*nmemb;c++)
	{
		data.push_back(buf[c]);
	}
	return size*nmemb;
}

int main()
{
	CURL* curl;

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.co.in/");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
	//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

	curl_easy_perform(curl);

	int cnt=0;
	string ln,line[100];
	stringstream stream(data);
	while(getline(stream, ln, '\n'))
		line[cnt++] = ln;
	cout << "===========================================================================================================" << endl;
	for(int i=0;i<cnt;i++)
		cout << "(" << i+1 << ") " << line[i] << endl;
	cout << "===========================================================================================================" << endl;
	//cin.get();

	curl_easy_cleanup(curl);
	curl_global_cleanup();

	return 0;
}
