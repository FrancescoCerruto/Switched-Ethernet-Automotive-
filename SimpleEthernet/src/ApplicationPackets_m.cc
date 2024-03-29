//
// Generated file, do not edit! Created by opp_msgtool 6.0 from ApplicationPackets.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "ApplicationPackets_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(DataPacket)

DataPacket::DataPacket(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

DataPacket::DataPacket(const DataPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

DataPacket::~DataPacket()
{
}

DataPacket& DataPacket::operator=(const DataPacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DataPacket::copy(const DataPacket& other)
{
    this->genTime = other.genTime;
    this->seqno = other.seqno;
    this->lastBurstPacket = other.lastBurstPacket;
}

void DataPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->genTime);
    doParsimPacking(b,this->seqno);
    doParsimPacking(b,this->lastBurstPacket);
}

void DataPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->genTime);
    doParsimUnpacking(b,this->seqno);
    doParsimUnpacking(b,this->lastBurstPacket);
}

omnetpp::simtime_t DataPacket::getGenTime() const
{
    return this->genTime;
}

void DataPacket::setGenTime(omnetpp::simtime_t genTime)
{
    this->genTime = genTime;
}

uint64_t DataPacket::getSeqno() const
{
    return this->seqno;
}

void DataPacket::setSeqno(uint64_t seqno)
{
    this->seqno = seqno;
}

bool DataPacket::getLastBurstPacket() const
{
    return this->lastBurstPacket;
}

void DataPacket::setLastBurstPacket(bool lastBurstPacket)
{
    this->lastBurstPacket = lastBurstPacket;
}

class DataPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_genTime,
        FIELD_seqno,
        FIELD_lastBurstPacket,
    };
  public:
    DataPacketDescriptor();
    virtual ~DataPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(DataPacketDescriptor)

DataPacketDescriptor::DataPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DataPacket)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

DataPacketDescriptor::~DataPacketDescriptor()
{
    delete[] propertyNames;
}

bool DataPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DataPacket *>(obj)!=nullptr;
}

const char **DataPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DataPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DataPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int DataPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_genTime
        FD_ISEDITABLE,    // FIELD_seqno
        FD_ISEDITABLE,    // FIELD_lastBurstPacket
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *DataPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "genTime",
        "seqno",
        "lastBurstPacket",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int DataPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "genTime") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "seqno") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "lastBurstPacket") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *DataPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::simtime_t",    // FIELD_genTime
        "uint64_t",    // FIELD_seqno
        "bool",    // FIELD_lastBurstPacket
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **DataPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DataPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DataPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DataPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DataPacket'", field);
    }
}

const char *DataPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DataPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_genTime: return simtime2string(pp->getGenTime());
        case FIELD_seqno: return uint642string(pp->getSeqno());
        case FIELD_lastBurstPacket: return bool2string(pp->getLastBurstPacket());
        default: return "";
    }
}

void DataPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_genTime: pp->setGenTime(string2simtime(value)); break;
        case FIELD_seqno: pp->setSeqno(string2uint64(value)); break;
        case FIELD_lastBurstPacket: pp->setLastBurstPacket(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataPacket'", field);
    }
}

omnetpp::cValue DataPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_genTime: return pp->getGenTime().dbl();
        case FIELD_seqno: return (omnetpp::intval_t)(pp->getSeqno());
        case FIELD_lastBurstPacket: return pp->getLastBurstPacket();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DataPacket' as cValue -- field index out of range?", field);
    }
}

void DataPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_genTime: pp->setGenTime(value.doubleValue()); break;
        case FIELD_seqno: pp->setSeqno(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_lastBurstPacket: pp->setLastBurstPacket(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataPacket'", field);
    }
}

const char *DataPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr DataPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DataPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataPacket'", field);
    }
}

Register_Class(DataControlInfo)

DataControlInfo::DataControlInfo(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

DataControlInfo::DataControlInfo(const DataControlInfo& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

DataControlInfo::~DataControlInfo()
{
}

DataControlInfo& DataControlInfo::operator=(const DataControlInfo& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void DataControlInfo::copy(const DataControlInfo& other)
{
    this->destination = other.destination;
}

void DataControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->destination);
}

void DataControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->destination);
}

const char * DataControlInfo::getDestination() const
{
    return this->destination.c_str();
}

void DataControlInfo::setDestination(const char * destination)
{
    this->destination = destination;
}

class DataControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_destination,
    };
  public:
    DataControlInfoDescriptor();
    virtual ~DataControlInfoDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(DataControlInfoDescriptor)

DataControlInfoDescriptor::DataControlInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DataControlInfo)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

DataControlInfoDescriptor::~DataControlInfoDescriptor()
{
    delete[] propertyNames;
}

bool DataControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DataControlInfo *>(obj)!=nullptr;
}

const char **DataControlInfoDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DataControlInfoDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DataControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int DataControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_destination
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *DataControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destination",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int DataControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "destination") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *DataControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_destination
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **DataControlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DataControlInfoDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DataControlInfoDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DataControlInfo *pp = omnetpp::fromAnyPtr<DataControlInfo>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DataControlInfoDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DataControlInfo *pp = omnetpp::fromAnyPtr<DataControlInfo>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DataControlInfo'", field);
    }
}

const char *DataControlInfoDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DataControlInfo *pp = omnetpp::fromAnyPtr<DataControlInfo>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DataControlInfoDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DataControlInfo *pp = omnetpp::fromAnyPtr<DataControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_destination: return oppstring2string(pp->getDestination());
        default: return "";
    }
}

void DataControlInfoDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataControlInfo *pp = omnetpp::fromAnyPtr<DataControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_destination: pp->setDestination((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataControlInfo'", field);
    }
}

omnetpp::cValue DataControlInfoDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DataControlInfo *pp = omnetpp::fromAnyPtr<DataControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_destination: return pp->getDestination();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DataControlInfo' as cValue -- field index out of range?", field);
    }
}

void DataControlInfoDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataControlInfo *pp = omnetpp::fromAnyPtr<DataControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_destination: pp->setDestination(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataControlInfo'", field);
    }
}

const char *DataControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr DataControlInfoDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DataControlInfo *pp = omnetpp::fromAnyPtr<DataControlInfo>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DataControlInfoDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DataControlInfo *pp = omnetpp::fromAnyPtr<DataControlInfo>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataControlInfo'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

