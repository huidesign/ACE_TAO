/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   RTScheduler_Manager.h
 *
 *  $Id$
 *
 *  @author Yamuna Krishnmaurthy <yamuna@oomworks.com>
 */
//=============================================================================


#ifndef TAO_PRIORITY_MAPPING_MANAGER_H
#define TAO_PRIORITY_MAPPING_MANAGER_H

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#include "RTSchedulerC.h"
//#include "tao/LocalObject.h"

class TAO_RTScheduler_Manager;
class TAO_RTScheduler_Manager_var;
typedef TAO_RTScheduler_Manager *TAO_RTScheduler_Manager_ptr;


/**
 * @class TAO_RTScheduler_Manager
 *
 * @brief RTScheduler_Manager pseudo-objref.
 *
 * Allows setting of user-defined RTScheduler at run-time.
 */
class TAO_RTScheduler_Export TAO_RTScheduler_Manager :
  public virtual TAO_Local_RefCounted_Object
{
public:

	TAO_RTScheduler_Manager (void);
  /// Constructor.
  TAO_RTScheduler_Manager (PortableInterceptor::ORBInitInfo_ptr);

  ///
  void rtscheduler (RTScheduling::Scheduler_ptr rtscheduler);

  ///
  RTScheduling::Scheduler_ptr rtscheduler (void);

public:
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef TAO_RTScheduler_Manager_ptr _ptr_type;
  typedef TAO_RTScheduler_Manager_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  // the static operations
  static TAO_RTScheduler_Manager_ptr _duplicate (TAO_RTScheduler_Manager_ptr obj);
  static TAO_RTScheduler_Manager_ptr _narrow (
      CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  static TAO_RTScheduler_Manager_ptr _unchecked_narrow (
      CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  static TAO_RTScheduler_Manager_ptr _nil (void)
    {
      return (TAO_RTScheduler_Manager_ptr)0;
    }

  virtual void *_tao_QueryInterface (ptr_arith_t type);

  virtual const char* _interface_repository_id (void) const;

protected:

  /// Protected destructor to enforce proper memory management of this
  /// reference counted object.
  ~TAO_RTScheduler_Manager (void);

private:

  TAO_RTScheduler_Manager (const TAO_RTScheduler_Manager &);
  void operator= (const TAO_RTScheduler_Manager &);
  PortableInterceptor::ORBInitInfo_var info_;

private:
  RTScheduling::Scheduler_var rtscheduler_;
};

class TAO_RTScheduler_Export TAO_RTScheduler_Manager_var : public TAO_Base_var
{
public:
  TAO_RTScheduler_Manager_var (void); // default constructor
  TAO_RTScheduler_Manager_var (TAO_RTScheduler_Manager_ptr);
  TAO_RTScheduler_Manager_var (const TAO_RTScheduler_Manager_var &); // copy constructor
  ~TAO_RTScheduler_Manager_var (void); // destructor

  TAO_RTScheduler_Manager_var &operator= (TAO_RTScheduler_Manager_ptr);
  TAO_RTScheduler_Manager_var &operator= (const TAO_RTScheduler_Manager_var &);
  TAO_RTScheduler_Manager_ptr operator-> (void) const;

  /// in, inout, out, _retn
  operator const TAO_RTScheduler_Manager_ptr &() const;
  operator TAO_RTScheduler_Manager_ptr &();
  TAO_RTScheduler_Manager_ptr in (void) const;
  TAO_RTScheduler_Manager_ptr &inout (void);
  TAO_RTScheduler_Manager_ptr &out (void);
  TAO_RTScheduler_Manager_ptr _retn (void);
  TAO_RTScheduler_Manager_ptr ptr (void) const;

  // Hooks used by template sequence and object manager classes
  // for non-defined forward declared interfaces.
  static TAO_RTScheduler_Manager_ptr duplicate (TAO_RTScheduler_Manager_ptr);
  static void release (TAO_RTScheduler_Manager_ptr);
  static TAO_RTScheduler_Manager_ptr nil (void);
  static TAO_RTScheduler_Manager_ptr narrow (CORBA::Object * ACE_ENV_ARG_DECL_NOT_USED);
  static CORBA::Object * upcast (void *);

private:
  /// Unimplemented - prevents widening assignment.
  TAO_RTScheduler_Manager_ptr ptr_;
  TAO_RTScheduler_Manager_var (const TAO_Base_var &rhs);
  TAO_RTScheduler_Manager_var &operator= (const TAO_Base_var &rhs);
};

class TAO_RTScheduler_Export TAO_RTScheduler_Manager_out
{
public:
  TAO_RTScheduler_Manager_out (TAO_RTScheduler_Manager_ptr &);
  TAO_RTScheduler_Manager_out (TAO_RTScheduler_Manager_var &);
  TAO_RTScheduler_Manager_out (const TAO_RTScheduler_Manager_out &);
  TAO_RTScheduler_Manager_out &operator= (const TAO_RTScheduler_Manager_out &);
  TAO_RTScheduler_Manager_out &operator= (const TAO_RTScheduler_Manager_var &);
  TAO_RTScheduler_Manager_out &operator= (TAO_RTScheduler_Manager_ptr);
  operator TAO_RTScheduler_Manager_ptr &();
  TAO_RTScheduler_Manager_ptr &ptr (void);
  TAO_RTScheduler_Manager_ptr operator-> (void);

private:
  TAO_RTScheduler_Manager_ptr &ptr_;
};

#if defined (__ACE_INLINE__)
#include "RTScheduler_Manager.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_PRIORITY_MAPPING_MANAGER_H */
