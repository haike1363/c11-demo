#pragma once
#include <string>
#include <sstream>
#include <boost/serialization/map.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp>

#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define ENABLE_BOOST_SERIALIZE(...) GET_MACRO(__VA_ARGS__,\
    BOOST_SERIALIZE12,\
    BOOST_SERIALIZE11,\
    BOOST_SERIALIZE10,\
    BOOST_SERIALIZE9,\
    BOOST_SERIALIZE8,\
    BOOST_SERIALIZE7,\
    BOOST_SERIALIZE6,\
    BOOST_SERIALIZE5,\
    BOOST_SERIALIZE4,\
    BOOST_SERIALIZE3,\
    BOOST_SERIALIZE2,\
    BOOST_SERIALIZE1)(__VA_ARGS__)

#define BOOST_SERIALIZE1(p1) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) {\
    ar & p1; \
    }

#define BOOST_SERIALIZE2(p1, p2) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) {\
    ar & p1; \
    ar & p2; \
    }

#define BOOST_SERIALIZE3(p1, p2, p3) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) {\
    ar & p1; \
    ar & p2; \
    ar & p3; \
    }

#define BOOST_SERIALIZE4(p1, p2, p3, p4) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) { \
    ar & p1; \
    ar & p2; \
    ar & p3; \
    ar & p4; \
    }

#define BOOST_SERIALIZE5(p1, p2, p3, p4, p5) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) { \
    ar & p1; \
    ar & p2; \
    ar & p3; \
    ar & p4; \
    ar & p5; \
    }

#define BOOST_SERIALIZE6(p1, p2, p3, p4, p5,p6) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) { \
    ar & p1; \
    ar & p2; \
    ar & p3; \
    ar & p4; \
    ar & p5; \
    ar & p6; \
    }

#define BOOST_SERIALIZE7(p1, p2, p3, p4, p5,p6,p7) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) { \
    ar & p1; \
    ar & p2; \
    ar & p3; \
    ar & p4; \
    ar & p5; \
    ar & p6; \
    ar & p7; \
    }

#define BOOST_SERIALIZE8(p1, p2, p3, p4, p5,p6,p7,p8) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) { \
    ar & p1; \
    ar & p2; \
    ar & p3; \
    ar & p4; \
    ar & p5; \
    ar & p6; \
    ar & p7; \
    ar & p8; \
    }

#define BOOST_SERIALIZE9(p1, p2, p3, p4, p5,p6,p7,p8,p9) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) { \
    ar & p1; \
    ar & p2; \
    ar & p3; \
    ar & p4; \
    ar & p5; \
    ar & p6; \
    ar & p7; \
    ar & p8; \
    ar & p9; \
    }

#define BOOST_SERIALIZE10(p1, p2, p3, p4, p5,p6,p7,p8,p9,p10) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) { \
    ar & p1; \
    ar & p2; \
    ar & p3; \
    ar & p4; \
    ar & p5; \
    ar & p6; \
    ar & p7; \
    ar & p8; \
    ar & p9; \
    ar & p10; \
    }

#define BOOST_SERIALIZE11(p1, p2, p3, p4, p5,p6,p7,p8,p9,p10,p11) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) { \
    ar & p1; \
    ar & p2; \
    ar & p3; \
    ar & p4; \
    ar & p5; \
    ar & p6; \
    ar & p7; \
    ar & p8; \
    ar & p9; \
    ar & p10; \
    ar & p11; \
    }

#define BOOST_SERIALIZE12(p1, p2, p3, p4, p5,p6,p7,p8,p9,p10,p11,p12) \
    friend class boost::serialization::access; \
    template<class Archive> \
    void serialize(Archive & ar, const unsigned int version) { \
    ar & p1; \
    ar & p2; \
    ar & p3; \
    ar & p4; \
    ar & p5; \
    ar & p6; \
    ar & p7; \
    ar & p8; \
    ar & p9; \
    ar & p10; \
    ar & p11; \
    ar & p12; \
    }


template <class ValueT>
std::string BoostSerializeValue(const ValueT& value) {
    std::ostringstream ostm;
    boost::archive::text_oarchive oa(ostm);
    // boost::archive::binary_oarchive oa(ostm);
    oa << value;
    return ostm.str();
}

template <class ValueT>
void BoostUnSerializeValue(const std::string& buf, ValueT& value) {
    std::istringstream istm;
    istm.str(buf);
    boost::archive::text_iarchive ia(istm);
   // boost::archive::binary_iarchive ia(istm);
    ia >> value;
}

#define BOOST_SERIALIZE(val) BoostSerializeValue(val)

#define BOOST_UNSERIALIZE(buf, val) BoostUnSerializeValue(buf, val)
