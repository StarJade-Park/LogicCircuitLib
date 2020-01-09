#pragma once

#include "Assert.h"

// Template class bitset used bool type
// @ why use bool type?
//   - std::bitset is slow than bool array (reference link - https://rextester.com/SFWAN37914)
template<size_t N>
class TBitset final
{
	using LONG_LONG = long long;
public:
	// Ư�� ��Ʈ�� value�� �����մϴ�.
	void set(const size_t position, const bool value = true)
	{
		checkIndex(position);

		m_bBits[position] = value;
	}

	// ��� ��Ʈ�� value�� �����մϴ�.
	// - true : 1, false : 0
	void setAll(const bool value = false)
	{
		for ( auto&& bit : m_bBits )
		{
			bit = value;
		}
	}

	// ��� ��Ʈ�� 0(false)�� set�մϴ�.
	void reset( )
	{
		setAll(false);
	}

	// ��� ��Ʈ�� �������ϴ�.
	void flipAll( ) noexcept
	{
		for ( auto&& bit : m_bBits )
		{
			bit = !bit;
		}
	}

	// Ư�� ��Ʈ�� �������ϴ�.
	void flip(const size_t position)
	{
		checkIndex(position);

		m_bBits[position] = !m_bBits[position];
	}

	// TBitset�� ũ�⸦ ��ȯ�մϴ�.
	constexpr size_t getSize( ) const
	{
		return (size_t)eSize;
	}

	void print(const size_t position)
	{
		true == m_bBits[position] ? printf_s("true\n") : printf_s("false\n");
	}

	void printAll( )
	{
		for ( size_t i = 0; i < (size_t)eSize; ++i )
		{
			printf_s("[%zu] : ", i);
			print(i);
		}

		printf_s("\n");
	}

	void printBinaryFmt(const size_t position)
	{
		true == m_bBits[position] ? printf_s("1\n") : printf_s("0\n");
	}

	void printAllBinaryFmt( )
	{
		for ( size_t i = 0; i < (size_t)eSize; ++i )
		{
			printf_s("[%zu] : ", i);
			printBinaryFmt(i);
		}

		printf_s("\n");
	}

public:
	bool operator==(const TBitset<N>& other) const
	{
		for ( size_t i = 0; i < (size_t)eSize; ++i )
		{
			if ( m_bBits[i] != other.m_bBits[i] )
			{
				return false;
			}
		}

		return true;
	}

	bool operator!=(const TBitset<N>& other) const
	{
		for ( size_t i = 0; i < (size_t)eSize; ++i )
		{
			if ( m_bBits[i] == other.m_bBits[i] )
			{
				return false;
			}
		}

		return true;
	}

public: // operator[]
	bool operator[](const size_t position) const
	{
		checkIndex(position);

		return m_bBits[position];
	}

public: // Bit operators
	// note �ʿ��� �� �����ϱ� ���� �̸� �ּ����� �ۼ�����
	//TBitset<N>& operator&=(const TBitset<N>& other) noexcept;
	//TBitset<N>& operator|=(const TBitset<N>& other) noexcept;
	//TBitset<N>& operator^=(const TBitset<N>& other) noexcept;
	//TBitset<N> operator~( ) const noexcept;
	//TBitset<N> operator<<(const size_t position) const noexcept;
	//TBitset<N> operator<<=(const size_t position) const noexcept;
	//TBitset<N> operator>>(const size_t position) const noexcept;
	//TBitset<N> operator>>=(const size_t position) const noexcept;

public:
	TBitset( )
		: m_bBits{ false, }
	{
	}

	TBitset(const TBitset<N>&) = default;
	TBitset<N>& operator=(const TBitset<N>&) = default;

	TBitset(TBitset<N>&&) = default;
	TBitset<N>& operator=(TBitset<N>&&) = default;

	~TBitset( ) = default;

private:
	FORCE_INLINE void checkIndex(const size_t position) const
	{
		if ( N > position )
		{
			return;
		}

		DEBUG_PRINT_ERROR("Invalid bitset<N> position(%zu)", position);
	}

private:
	enum : LONG_LONG
	{
		eSize = (LONG_LONG)N,
	};

private:
	bool m_bBits[eSize];
};
