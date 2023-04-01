/**
 * Autogenerated by Thrift Compiler (0.14.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef BeveragePreferenceService_H
#define BeveragePreferenceService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "vending_machine_types.h"

namespace vending_machine {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class BeveragePreferenceServiceIf {
 public:
  virtual ~BeveragePreferenceServiceIf() {}
};

class BeveragePreferenceServiceIfFactory {
 public:
  typedef BeveragePreferenceServiceIf Handler;

  virtual ~BeveragePreferenceServiceIfFactory() {}

  virtual BeveragePreferenceServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(BeveragePreferenceServiceIf* /* handler */) = 0;
};

class BeveragePreferenceServiceIfSingletonFactory : virtual public BeveragePreferenceServiceIfFactory {
 public:
  BeveragePreferenceServiceIfSingletonFactory(const ::std::shared_ptr<BeveragePreferenceServiceIf>& iface) : iface_(iface) {}
  virtual ~BeveragePreferenceServiceIfSingletonFactory() {}

  virtual BeveragePreferenceServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(BeveragePreferenceServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<BeveragePreferenceServiceIf> iface_;
};

class BeveragePreferenceServiceNull : virtual public BeveragePreferenceServiceIf {
 public:
  virtual ~BeveragePreferenceServiceNull() {}
};

class BeveragePreferenceServiceClient : virtual public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  BeveragePreferenceServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class BeveragePreferenceServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<BeveragePreferenceServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (BeveragePreferenceServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
 public:
  BeveragePreferenceServiceProcessor(::std::shared_ptr<BeveragePreferenceServiceIf> iface) :
    iface_(iface) {
  }

  virtual ~BeveragePreferenceServiceProcessor() {}
};

class BeveragePreferenceServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  BeveragePreferenceServiceProcessorFactory(const ::std::shared_ptr< BeveragePreferenceServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< BeveragePreferenceServiceIfFactory > handlerFactory_;
};

class BeveragePreferenceServiceMultiface : virtual public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceMultiface(std::vector<std::shared_ptr<BeveragePreferenceServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~BeveragePreferenceServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<BeveragePreferenceServiceIf> > ifaces_;
  BeveragePreferenceServiceMultiface() {}
  void add(::std::shared_ptr<BeveragePreferenceServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class BeveragePreferenceServiceConcurrentClient : virtual public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  BeveragePreferenceServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
