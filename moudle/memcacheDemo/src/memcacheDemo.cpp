#include "libmemcached/memcached.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    memcached_return rc;
    memcached_st *memc = memc = memcached_create(NULL);
    memcached_server_st *server = memcached_server_list_append(NULL,"127.0.0.1",11211,&rc);

    rc=memcached_server_push(memc,server);
    if (rc != MEMCACHED_SUCCESS) {
        cout<<"memcached_server_push failed! rc: "<<rc<<endl;
        return -1;
    }
    memcached_server_free(server);

    string key = "key";
    string value = "value";
    size_t value_length = value.length();
    size_t key_length = key.length();
    time_t expiration = 0;
    uint32_t flags = 0;

    rc = memcached_set(memc, key.c_str(), key.length(), value.c_str(), value.length(), expiration, flags); 
    if (rc == MEMCACHED_SUCCESS) {
        cout<<"Save data:"<<value<<" sucessful!"<<endl;
    }
    
    char* result = memcached_get(memc,key.c_str(),key_length,&value_length,&flags,&rc);
    if (rc == MEMCACHED_SUCCESS) {
        cout<<"Get value:"<<result<<" sucessful!"<<endl;
    }

    rc=memcached_delete(memc, key.c_str(), key_length, expiration);
    if (rc == MEMCACHED_SUCCESS) {
        cout<<"Delete key:"<<key<<" sucessful!"<<endl;
    }
    
    memcached_free(memc);

    return 0;
}
