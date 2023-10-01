#include "Point2.h"

template<class T>
API constexpr Point2<T>::Point2(const T x, const T y) noexcept:
    m_x(x),
    m_y(y) {
}


template<class T>
API constexpr void Point2<T>::SetX(const T x) noexcept {
   m_x = x;
}


template<class T>
API constexpr void Point2<T>::SetY(const T y) noexcept {
   m_y = y;
}


template<class T>
API constexpr T Point2<T>::GetX() const noexcept {
   return m_x;
}


template<class T>
API constexpr T Point2<T>::GetY() const noexcept {
   return m_y;
}