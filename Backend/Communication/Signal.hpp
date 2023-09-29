
template<class T>
Signal<T>::Signal(T&& data) noexcept:
    m_data(std::move(data)) {
}


template<class T>
T& Signal<T>::Get() noexcept {
   return m_data;
}


template<class T>
const T& Signal<T>::Get() const noexcept {
   return m_data;
}
