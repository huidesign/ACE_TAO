// -*- C++ -*-
// $Id$

ACE_INLINE int
ACE_OS::fcntl (ACE_HANDLE handle, int cmd, long arg)
{
  ACE_OS_TRACE ("ACE_OS::fcntl");
# if defined (ACE_LACKS_FCNTL)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::fcntl (handle, cmd, arg), int, -1);
# endif /* ACE_LACKS_FCNTL */
}

