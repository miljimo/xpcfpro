#ifndef PROJECT_BASE_FACTORY_H
#define PROJECT_BASE_FACTORY_H
#include <qjsondocument.h>
#include <memory>
#include <iterator>
#include <string>

namespace xpcf
{
  class concept;

  template <class _Myclass> class basic_project_iterator
  {
  public:
    typedef _Myclass::value_type      value_type;
    typedef _Myclass::size_type       size_type;
    typedef _Myclass::pointer         pointer;
    typedef _Myclass::reference       reference;
    typedef _Myclass::const_pointer   const_pointer;
    typedef _Myclass::const_reference const_reference;


  };
  template <class _Elem> class concept_traits
  {
    typedef _Elem               value_type;
    typedef sizeof(_Elem)       size_type;
    typedef value_type *        pointer;
    typedef value_type &        reference;
    typedef value_type * const  const_pointer;
    typedef value_type & const  const_reference;

    virtual  value_type * allocate(unsigned int const _Nsize) 
  };

  template <class _Elem> class concept_allocator
  {
  public:
    //  typedefs

    typedef _Elem               value_type;
    typedef sizeof(_Elem)       size_type;
    typedef value_type *        pointer;
    typedef value_type &        reference;
    typedef value_type * const  const_pointer;
    typedef value_type & const  const_reference;

  public:
    //converting allocator of _Elem to _Other
    typename <class  _Other> class rebind {
    public:
      typedef concept_allocator<_Other> Other;
    }
  public:
    inline explicit concept_allocator(){};
    inline explicit                       concept_allocator(concept_allocator const &){}
    inline                               ~concept_allocator() {};
    template<typename _Other> inline explicit concept_allocator(concept_allocator<_Other> const &){};

    //addressing
    inline pointer address(reference _Ref) {
      return &_Ref
    }
    inline cons_pointer  address(const_reference_Cref){
      return &_Cref;
    }
    //memeory allocations
    inline pointer allocate(size_type _Size, typename std::allocator<void>::const_pointer = 0)
    {
      return reinterpret_cast<pointer>(::operator new (_Size * sizeof(_Elem)));
    }
    inline void deallocate(pointer p, size_type _Size = 0)
    {
      (_Size <=1)?::operator delete(p): (::operator delete[_Size](p));
    }

  };

  template <class _Elem, class _Inputadaptor, class _Output_Adaptor, class _Trait = concept_traits<_Elem>,
  class _Allocator = xpcf::concept_allocator<concept>> basic_project_factory
  {
  public:
    typedef typename _Trait::value_type       value_type;
    typedef typename _Trait::allocator_type           allocator_type;
    typedef typename _Trait::size_type                size_type;
    typedef typename _Trait::pointer                  pointer;
    typedef _Trait::reference                reference;
    typedef _Trait::const_pointer            const_pointer;
    typedef _Trait::const_reference          const_reference;
    typedef 

    explicit basic_project_factory(const _Allocator & __a = _Allocator())
    {
    }

    
   
  }; 

}
#endif