//////////////////////////////////////////////////////////////////////////////
// Project...: drax
// File......: TypedPtrArrayEx.hpp
// Date......: 21.11.2008
// Author....: Stephan Arlt
//////////////////////////////////////////////////////////////////////////////

#pragma once

template <class T>
class CTypedPtrArrayEx : public CTypedPtrArray<CPtrArray, T>
{
public:
   CTypedPtrArrayEx(BOOL pbAutoDelete = TRUE);
   virtual ~CTypedPtrArrayEx();

   //////////////////////////////////////////////////////////////////////////////
   // overridings
   //////////////////////////////////////////////////////////////////////////////

   void RemoveAll();
   void RemoveAt(int piIdx, int piCount = 1);

   //////////////////////////////////////////////////////////////////////////////
   // getter
   //////////////////////////////////////////////////////////////////////////////
   
   BOOL IsAutoDelete() const { return m_bAutoDelete; }

   //////////////////////////////////////////////////////////////////////////////
   // setter
   //////////////////////////////////////////////////////////////////////////////
   void SetAutoDelete(BOOL pbAutoDelete = TRUE) { m_bAutoDelete = pbAutoDelete; }

protected:
   BOOL m_bAutoDelete;
};

//////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////
template <class T>
CTypedPtrArrayEx<T>::CTypedPtrArrayEx(BOOL pbAutoDelete)
: m_bAutoDelete(pbAutoDelete)
{
}

//////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////
template <class T>
CTypedPtrArrayEx<T>::~CTypedPtrArrayEx()
{
   RemoveAll();
}

//////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////
template <class T>
void CTypedPtrArrayEx<T>::RemoveAll()
{
   RemoveAt(0, (int)GetSize());
}

//////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////
template <class T>
void CTypedPtrArrayEx<T>::RemoveAt(int piIdx, int piCount)
{
   while ( !(piCount == 0) )
   {
      if ( IsAutoDelete() )
      {
         T lpData = GetAt(piIdx);
         ASSERT(NULL != lpData);
         delete lpData;
      }

      CPtrArray::RemoveAt(piIdx);
      piCount--;
   }   
}
