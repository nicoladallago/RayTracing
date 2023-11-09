#pragma once
#include <cstdint>
#include <array>
#include <limits>
#include <type_traits>

namespace XoshiroCpp {
   // Converts given uint64 value `i` into a 64-bit floating
   // point value in the range of [0.0, 1.0)
   template<class Uint64, std::enable_if_t<std::is_same_v<Uint64, std::uint64_t>>* = nullptr>
   [[nodiscard]] constexpr double DoubleFromBits(Uint64 i) noexcept {
      return (i >> 11) * 0x1.0p-53;
   }

   // SplitMix64
   // Output: 64 bits
   // Period: 2^64
   // Footprint: 8 bytes
   // Original implementation: http://prng.di.unimi.it/splitmix64.c
   class SplitMix64 {
    public:
      using state_type = std::uint64_t;
      using result_type = std::uint64_t;

      explicit constexpr SplitMix64(state_type state) noexcept;

      constexpr result_type operator()() noexcept;

      template<std::size_t N>
      [[nodiscard]] constexpr std::array<std::uint64_t, N> generateSeedSequence() noexcept;

      [[nodiscard]] friend bool operator==(const SplitMix64& lhs, const SplitMix64& rhs) noexcept {
         return (lhs.m_state == rhs.m_state);
      }

      [[nodiscard]] friend bool operator!=(const SplitMix64& lhs, const SplitMix64& rhs) noexcept {
         return (lhs.m_state != rhs.m_state);
      }

    private:
      state_type m_state;
   };

   // xoshiro256++
   // Output: 64 bits
   // Period: 2^256 - 1
   // Footprint: 32 bytes
   // Original implementation: http://prng.di.unimi.it/xoshiro256plusplus.c
   // Version: 1.0
   class Xoshiro256PlusPlus {
    public:
      using state_type = std::array<std::uint64_t, 4>;
      using result_type = std::uint64_t;

      explicit constexpr Xoshiro256PlusPlus(std::uint64_t seed) noexcept;

      constexpr result_type operator()() noexcept;

      [[nodiscard]] friend bool operator==(const Xoshiro256PlusPlus& lhs, const Xoshiro256PlusPlus& rhs) noexcept {
         return (lhs.m_state == rhs.m_state);
      }

      [[nodiscard]] friend bool operator!=(const Xoshiro256PlusPlus& lhs, const Xoshiro256PlusPlus& rhs) noexcept {
         return (lhs.m_state != rhs.m_state);
      }

    private:
      state_type m_state;
   };
}

////////////////////////////////////////////////////////////////

namespace XoshiroCpp {
   namespace detail {
      [[nodiscard]] static constexpr std::uint64_t RotL(const std::uint64_t x, const int s) noexcept {
         return (x << s) | (x >> (64 - s));
      }
   }

   ////////////////////////////////////////////////////////////////
   //
   //	SplitMix64
   //
   constexpr SplitMix64::SplitMix64(const state_type state) noexcept:
       m_state(state) {
   }

   constexpr SplitMix64::result_type SplitMix64::operator()() noexcept {
      std::uint64_t z = (m_state += 0x9e3779b97f4a7c15);
      z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
      z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
      return z ^ (z >> 31);
   }

   template<std::size_t N>
   constexpr std::array<std::uint64_t, N> SplitMix64::generateSeedSequence() noexcept {
      std::array<std::uint64_t, N> seeds = {};

      for(auto& seed : seeds) {
         seed = operator()();
      }

      return seeds;
   }

   ////////////////////////////////////////////////////////////////
   //
   //	xoshiro256++
   //
   constexpr Xoshiro256PlusPlus::Xoshiro256PlusPlus(const std::uint64_t seed) noexcept:
       m_state(SplitMix64{seed}.generateSeedSequence<4>()) {
   }

   constexpr Xoshiro256PlusPlus::result_type Xoshiro256PlusPlus::operator()() noexcept {
      const std::uint64_t result = detail::RotL(m_state[0] + m_state[3], 23) + m_state[0];
      const std::uint64_t t = m_state[1] << 17;
      m_state[2] ^= m_state[0];
      m_state[3] ^= m_state[1];
      m_state[1] ^= m_state[2];
      m_state[0] ^= m_state[3];
      m_state[2] ^= t;
      m_state[3] = detail::RotL(m_state[3], 45);
      return result;
   }
}