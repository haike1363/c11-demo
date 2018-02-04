#include <iostream>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/tuple.hpp>
#include <cereal/archives/json.hpp>

struct NodeBasae {
    int i = 1;
    std::string s = "sss";
    std::vector<std::string> data = {"s1", "s2", "s3"};

    template <class Archive>
    void serialize( Archive & ar )
    {
        ar(CEREAL_NVP(i), CEREAL_NVP(s), CEREAL_NVP(data));
    }
};

struct NodeDrived {
    int k = 2;
    NodeBasae base;
    template <class Archive>
    void serialize( Archive & ar )
    {
        ar( CEREAL_NVP(k), CEREAL_NVP(base) );
    }
};

typedef std::string Tagk;
typedef std::vector<Tagk> Tagks;
typedef std::tuple<Tagk, Tagks, NodeBasae> Output;

int main() {
    cereal::JSONOutputArchive archive( std::cout );
    NodeDrived myData;
    archive( CEREAL_NVP(myData) );
    Tagk tagk = "tagk";
    Tagks tagks = {"tagk1", "tagk2"};
    NodeBasae base;
    Output output = std::make_tuple(tagk, tagks, base);
    const Output& outputRef = output;
    archive( cereal::make_nvp("output", outputRef) );
    archive(cereal::make_nvp("output.NodeBase", std::get<2>(output)));
    return 0;
}