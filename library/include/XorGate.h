#pragma once

#include "Component.h"

class UXorGateComponent : public IComponent
{
	static constexpr size_t s_InputCount = 2U;
	static constexpr size_t s_OutputCount = 1U;
public:
	void setInputState(const size_t position, const bool bValue = true) override
	{
		m_InputBitset.set(position, bValue);
		update( );
	}

	bool getInputState(const size_t position) const override
	{
		return m_InputBitset[position];
	}

	bool getOutputState(const size_t position = 0) const override
	{
		return m_OutputBitset[position];
	}

	size_t getInputCount( ) const override
	{
		return m_InputBitset.getSize( );
	}

	size_t getOutputCount( ) const override
	{
		return m_OutputBitset.getSize( );
	}

	void update( ) override
	{
		m_OutputBitset.set(0, m_InputBitset[0] ^ m_InputBitset[1]);
	}

	void reset( ) override
	{
		m_InputBitset.reset( );
		m_OutputBitset.reset( );
	}

public:
	virtual ~UXorGateComponent( ) = default;

private:
	TBitset<UXorGateComponent::s_InputCount> m_InputBitset;
	TBitset<UXorGateComponent::s_OutputCount> m_OutputBitset;
};
