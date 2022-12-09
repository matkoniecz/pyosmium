#ifndef PYOSMIUM_OSM_BASE_OBJECTS_HPP
#define PYOSMIUM_OSM_BASE_OBJECTS_HPP

#include <pybind11/pybind11.h>

#include <osmium/osm.hpp>

template <typename T>
class COSMDerivedObject {
public:
    COSMDerivedObject(T *obj) : m_obj(obj) {}

    T const *get() const {
        if (!m_obj) {
            throw std::runtime_error{"Illegal access to removed OSM object"};
        }
        return m_obj;
    }

    bool is_valid() const { return m_obj; }

    void invalidate() { m_obj = nullptr; }

private:
    T *m_obj;
};

using COSMNode = COSMDerivedObject<osmium::Node const>;
using COSMWay = COSMDerivedObject<osmium::Way const>;
using COSMRelation = COSMDerivedObject<osmium::Relation const>;
using COSMArea = COSMDerivedObject<osmium::Area const>;
using COSMChangeset = COSMDerivedObject<osmium::Changeset const>;


#endif //PYOSMIUM_OSM_BASE_OBJECTS_HPP
