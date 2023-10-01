#include "Point3.h"

template<class T>
API constexpr Point3<T>::Point3(const T x, const T y, const T z) noexcept:
    m_xy(Point2<T>(x, y)),
    m_z(z){
}


template<class T>
API constexpr void Point3<T>::SetX(const T x) noexcept {
   m_xy.SetX(x);
}


template<class T>
API constexpr void Point3<T>::SetY(const T y) noexcept {
   m_xy.SetY(y);
}


template<class T>
API constexpr void Point3<T>::SetZ(const T z) noexcept {
   m_z = z;
}


template<class T>
API constexpr T Point3<T>::GetX() const noexcept {
   return m_xy.GetX();
}


template<class T>
API constexpr T Point3<T>::GetY() const noexcept {
   return m_xy.GetY();
}


template<class T>
API constexpr T Point3<T>::GetZ() const noexcept {
   return m_z;
}