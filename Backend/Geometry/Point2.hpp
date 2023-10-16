#include "Point2.h"
#include "Utils/Utils.h"

#include <cmath> // TODO Remove this

template<class T>
API constexpr Point2<T>::Point2(const T& x, const T& y) noexcept:
    m_x(x),
    m_y(y) {
}


template<class T>
API constexpr Point2<T> Point2<T>::operator-() const noexcept {
   return Point2<T>(-m_x, -m_y);
}


template<class T>
API constexpr T Point2<T>::operator[](const unsigned int index) const {
   if constexpr(index == 0) {
      return m_x;
   }
   if constexpr(index == 1) {
      return m_y;
   }
   throw std::exception("Invalid index " + std::to_string(index));
}


template<class T>
API constexpr T& Point2<T>::operator[](const unsigned int index) {
   if constexpr(index == 0) {
      return m_x;
   }
   if constexpr(index == 1) {
      return m_y;
   }
   throw std::exception("Invalid index " + std::to_string(index));
}


template<class T>
API constexpr Point2<T>& Point2<T>::operator+=(const Point2<T>& point) noexcept {
   m_x += point.m_x;
   m_y += point.m_y;
   return *this;
}


template<class T>
API constexpr Point2<T>& Point2<T>::operator*=(const T& val) noexcept {
   m_x *= val;
   m_y *= val;
   return *this;
}


template<class T>
API constexpr Point2<T>& Point2<T>::operator/=(const T& val) noexcept {
   return *this *= 1 / val;
}


template<class T>
API constexpr bool Point2<T>::operator<(const Point2<T>& point) const noexcept {
   if(m_x < point.GetX()) {
      return true;
   }
   if(m_x == point.GetX()) {
      return m_y < point.GetY();
   }
   return false;
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


template<class T>
API constexpr T Point2<T>::Length() const noexcept {
   return std::sqrt(LenghtSquared());
}


template<class T>
API constexpr T Point2<T>::LenghtSquared() const noexcept {
   return m_x * m_x + m_y * m_y;
}


template<typename T>
API constexpr bool Point2<T>::NearZero() const noexcept {
   return (std::fabs(m_x) < NEAR_ZERO) && (std::fabs(m_y) < NEAR_ZERO);
}


template<typename T>
API inline Point2<T> Point2<T>::Random() noexcept {
   return Point2<T>(Utils::Random(), Utils::Random());
}


template<typename T>
API inline Point2<T> Point2<T>::Random(const double min, const double max) noexcept {
   return Point2<T>(Utils::Random(min, max), Utils::Random(min, max));
}


template<typename T>
API inline std::ostream& operator<<(std::ostream& out, const Point2<T>& point) {
   return out << point.GetX() << ' ' << point.GetY();
}


template<typename T>
API inline Point2<T> operator+(const Point2<T>& p1, const Point2<T>& p2) noexcept {
   return Point2<T>(p1.GetX() + p2.GetX(), p1.GetY() + p2.GetY());
}


template<typename T>
API inline Point2<T> operator-(const Point2<T>& p1, const Point2<T>& p2) noexcept {
   return Point2<T>(p1.GetX() - p2.GetX(), p1.GetY() - p2.GetY());
}


template<typename T>
API inline Point2<T> operator*(const Point2<T>& p1, const Point2<T>& p2) noexcept {
   return Point2<T>(p1.GetX() * p2.GetX(), p1.GetY() * p2.GetY());
}


template<typename T>
API inline Point2<T> operator*(const T& val, const Point2<T>& p) noexcept {
   return Point2<T>(val * p.GetX(), val * p.GetY());
}


template<typename T>
API inline Point2<T> operator*(const Point2<T>& p, const T& val) noexcept {
   return val * p;
}


template<typename T>
API inline Point2<T> operator/(const Point2<T>& p, const T& val) noexcept {
   return (1 / val) * p;
}


template<typename T>
API inline T Dot(const Point2<T>& p1, const Point2<T>& p2) noexcept {
   return p1.GetX() * p2.GetX() + p1.GetY() * p2.GetY();
}


template<typename T>
API inline Point2<T> UnitVector(const Point2<T>& p) noexcept {
   return p / p.Length();
}