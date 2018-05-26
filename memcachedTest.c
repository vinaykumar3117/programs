#include<stdio.h>
#include<string.h>
#include<libmemcached/memcached.h>
int main()
{
	memcached_server_st * servers = memcached_servers_parse("127.0.0.1:11211"); 
	memcached_st * memc = memcached_create(NULL); 
	memcached_server_push(memc, servers); 
	memcached_server_list_free(servers); 
	//memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_BINARY_PROTOCOL, 0); 

	char *strKey = "1"; 
	char *strValue = "hello.world"; 

	memcached_return rc;
	rc = memcached_set (memc, strKey, strlen(strKey), strValue, sizeof(strValue), 0, 0); 
	if (rc == MEMCACHED_SUCCESS) 
	{ 
		printf ("memcached_set ok!\n"); 
		size_t ValueLength = 0; 
		uint32_t flags; 
		char * pValue = memcached_get (memc, strKey, strlen(strKey), &ValueLength, & flags, & rc); 
		if (rc == MEMCACHED_SUCCESS) 
		{ 
			printf ("memcached_get key =%s value =%s\n", strKey, pValue); 
			free (pValue); 
		} 
		else
		{
			printf("Can't get KEY : %s\n",memcached_strerror(memc, rc));
		}
	} 
	else
	{
		printf("Can't set KEY : %s\n",memcached_strerror(memc, rc));
	}
	memcached_free (memc);
	return 0;
}
