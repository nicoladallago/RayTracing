#include "Point3.h"

template<class T>
API constexpr Point3<T>::Point3(const T& x, const T& y, const T& z) noexcept:
    Point3(Point2<T>(x, y), z) {
}


template<class T>
API constexpr Point3<T>::Point3(const Point2<T> point, const T& z) noexcept:
    m_xy(point),
    m_z(z) {
}


template<class T>
API constexpr Point3<T> Point3<T>::operator-() const noexcept {
   return Point3<T>(-m_xy, -m_z);
}


template<class T>
API constexpr T Point3<T>::operator[](const unsigned int index) const {
   if constexpr(index == 2) {
      return m_z;
   }
   return m_xy[index];
}


template<class T>
API constexpr T& Point3<T>::operator[](const unsigned int index) {
   if constexpr(index == 2) {
      return m_z;
   }
   return m_xy[index];
}


template<class T>
API constexpr Point3<T>& Point3<T>::operator+=(const Point3<T>& point) noexcept {
   m_xy += point.m_xy;
   m_z += point.m_z;
   return *this;
}


template<class T>
API constexpr Point3<T>& Point3<T>::operator*=(const T& val) noexcept {
   m_xy *= val;
   m_z *= val;
   return *this;
}


template<class T>
API constexpr Point3<T>& Point3<T>::operator/=(const T& val) noexcept {
   return *this *= 1 / val;
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
API constexpr const Point2<T>& Point3<T>::GetXY() const noexcept {
   return m_xy;
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


template<class T>
API constexpr T Point3<T>::Length() const noexcept {
   return std::sqrt(LenghtSquared());
}


template<class T>
API constexpr T Point3<T>::LenghtSquared() const noexcept {
   return m_xy.LenghtSquared() + m_z * m_z;
}


template<typename T>
API inline std::ostream& operator<<(std::ostream& out, const Point3<T>& point) {
   return out << point.GetXY() << ' ' << point.GetZ();
}


template<typename T>
API constexpr Point3<T> operator+(const Point3<T>& p1, const Point3<T>& p2) noexcept {
   return Point3<T>(p1.GetXY() + p2.GetXY(), p1.GetZ() + p2.GetZ());
}


template<typename T>
API constexpr Point3<T> operator-(const Point3<T>& p1, const Point3<T>& p2) noexcept {
   return Point3<T>(p1.GetXY() - p2.GetXY(), p1.GetZ() - p2.GetZ());
}


template<typename T>
API constexpr Point3<T> operator*(const Point3<T>& p1, const Point3<T>& p2) noexcept {
   return Point3<T>(p1.GetXY() * p2.GetXY(), p1.GetZ() * p2.GetZ());
}


template<typename T>
API constexpr Point3<T> operator*(const T& val, const Point3<T>& p) noexcept {
   return Point3<T>(val * p.GetXY(), val * p.GetZ());
}


template<typename T>
API constexpr Point3<T> operator*(const Point3<T>& p, const T& val) noexcept {
   return val * p;
}


template<typename T>
API constexpr Point3<T> operator/(const Point3<T>& p, const T& val) noexcept {
   return (1 / val) * p;
}


template<typename T>
API constexpr T Dot(const Point3<T>& p1, const Point3<T>& p2) noexcept {
   return Dot(p1.GetXY(), p2.GetXY()) + p1.GetZ() * p2.GetZ();
}


template<typename T>
API constexpr Point3<T> Cross(const Point3<T>& p1, const Point3<T>& p2) noexcept {
   return Point3<T>(p1.GetY() * p2.GetZ() - p1.GetZ() * p2.GetY(),
                    p1.GetZ() * p2.GetX() - p1.GetX() * p2.GetZ(),
                    p1.GetX() * p2.GetY() - p1.GetY() * p2.GetX());
}


template<typename T>
API constexpr Point3<T> UnitVector(const Point3<T>& p) noexcept {
   return p / p.Length();
}