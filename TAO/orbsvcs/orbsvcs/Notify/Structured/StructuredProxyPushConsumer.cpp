// $Id$

#include "StructuredProxyPushConsumer.h"

#if ! defined (__ACE_INLINE__)
#include "StructuredProxyPushConsumer.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(RT_Notify, TAO_NS_StructuredProxyPushConsumer, "$Id$")

#include "ace/Refcounted_Auto_Ptr.h"
#include "ace/Auto_Ptr.h"
#include "tao/debug.h"
#include "StructuredPushSupplier.h"
#include "StructuredEvent.h"
#include "../AdminProperties.h"
#include "../Proxy.h"
#include "../Admin.h"
#include "../EventChannel.h"
#include "../EventChannelFactory.h"
#include "../Notify_Service.h"

TAO_NS_StructuredProxyPushConsumer::TAO_NS_StructuredProxyPushConsumer (void)
{
}

TAO_NS_StructuredProxyPushConsumer::~TAO_NS_StructuredProxyPushConsumer ()
{

}

void
TAO_NS_StructuredProxyPushConsumer::release (void)
{
  this->supplier_->release ();

  delete this;
  //@@ inform factory
}

void
TAO_NS_StructuredProxyPushConsumer::destroy (ACE_ENV_SINGLE_ARG_DECL)
{
  if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG, "In TAO_NS_StructuredProxyPushConsumer::destroy \n"));

  this->inherited::destroy (this ACE_ENV_ARG_PARAMETER);
}

CosNotifyChannelAdmin::ProxyType
TAO_NS_StructuredProxyPushConsumer::MyType (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return CosNotifyChannelAdmin::PUSH_STRUCTURED;
}

void
TAO_NS_StructuredProxyPushConsumer::connect_structured_push_supplier (CosNotifyComm::StructuredPushSupplier_ptr push_supplier ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   , CosEventChannelAdmin::AlreadyConnected
                   ))
{
  // Convert Supplier to Base Type
  TAO_NS_StructuredPushSupplier * supplier;
  ACE_NEW_THROW_EX (supplier,
                    TAO_NS_StructuredPushSupplier (this),
                    CORBA::NO_MEMORY ());

  supplier->init (push_supplier ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->connect (supplier ACE_ENV_ARG_PARAMETER);
}

void
TAO_NS_StructuredProxyPushConsumer::push_structured_event (const CosNotification::StructuredEvent & notification ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   , CosEventComm::Disconnected
                   ))
{
  // Check if we should proceed at all.
  if (this->admin_properties_->reject_new_events () == 1
      && this->admin_properties_->queue_full ())
    ACE_THROW (CORBA::IMP_LIMIT ());

  if (this->is_connected () == 0)
    {
      ACE_THROW (CosEventComm::Disconnected ());
    }

  // Convert
  TAO_NS_Event_var event (new TAO_NS_StructuredEvent (notification));

  // Continue processing.
  this->push (event);
}

void
TAO_NS_StructuredProxyPushConsumer::disconnect_structured_push_consumer (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  this->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
}
