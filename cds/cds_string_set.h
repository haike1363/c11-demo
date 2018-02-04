#pragma once
#include <string>
#include <functional>
#include <cds/container/michael_set.h>
#include <cds/container/michael_kvlist_hp.h> 

typedef std::string CDSKey;
typedef int CDSValue;

// List traits based on std::less predicate
struct list_traits: public cds::container::michael_list::traits
{
    typedef std::less<CDSKey> less;
};

// Ordered list
typedef cds::container::MichaelKVList< cds::gc::HP, CDSKey, CDSValue, list_traits> cds_kv_list;
// Map traits
struct map_traits: public cds::container::michael_map::traits
{
    struct hash {
        size_t operator()( CDSValue i ) const
        {
            return cds::opt::v::hash<CDSValue>()( i );
        }
    }
};
// Your map
typedef cds::container::MichaelHashMap< cds::gc::HP, cds_kv_list, map_traits > int2int_map;
// Now you can use int2int_map class
