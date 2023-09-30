#include "Rect.h"

template<class T>
API constexpr Rect<T>::Rect(const T width, const T height) noexcept:
    m_width(width),
    m_height(height) {
}


template<class T>
API constexpr Rect<T>::Rect(const Point<T>& origin, const T width, const T height) noexcept :
    m_origin(origin),
    Rect(width, height) {
}


template<class T>
API constexpr Rect<T>::Rect(const T x, const T y, const T width, const T height) noexcept:
    m_origin(Point<T>(x, y)),
    Rect(width, height) {
}


template<class T>
API constexpr void Rect<T>::SetOrigin(const Point<T>& origin) noexcept {
   m_origin = origin;
}

template<class T>
API constexpr void Rect<T>::SetOrigin(const T x, const T y) noexcept {
   m_origin.SetX(x);
   m_origin.SetY(y);
}


template<class T>
API constexpr void Rect<T>::SetWidth(const T width) noexcept {
   m_width = width;
}


template<class T>
API constexpr void Rect<T>::SetHeight(const T height) noexcept {
   m_height = height;
}


template<class T>
API constexpr const Point<T>& Rect<T>::GetOrigin() const noexcept {
   return m_origin;
}


template<class T>
API constexpr T Rect<T>::GetX() const noexcept {
   return m_origin.GetX();
}


template<class T>
API constexpr T Rect<T>::GetY() const noexcept {
   return m_origin.GetY();
}


template<class T>
API constexpr T Rect<T>::GetWidth() const noexcept {
   return m_width;
}


template<class T>
API constexpr T Rect<T>::GetHeight() const noexcept {
   return m_height;
}