#include "Point.h"

template<class T>
API constexpr Point<T>::Point(const T x, const T y) noexcept:
    m_x(x),
    m_y(y) {
}


template<class T>
API constexpr void Point<T>::SetX(const T x) noexcept {
   m_x = x;
}


template<class T>
API constexpr void Point<T>::SetY(const T y) noexcept {
   m_y = y;
}


template<class T>
API constexpr T Point<T>::GetX() const noexcept {
   return m_x;
}


template<class T>
API constexpr T Point<T>::GetY() const noexcept {
   return m_y;
}