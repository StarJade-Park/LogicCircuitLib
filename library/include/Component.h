#pragma once

#include "Assertion.h"
#include "TBitset.h"

class IComponent
{
public: // Pure virtual function list
/*
	void setInputState(const size_t position, const bool bValue = true) override;
	bool getInputState(const size_t position) const override;
	bool getOutputState(const size_t position = 0) const override;
	size_t getInputCount( ) const override;
	size_t getOutputCount( ) const override;
	void update( ) override;
	void reset( ) override;
*/


	virtual void setInputState(const size_t position, const bool bValue = true) = 0;
	virtual bool getInputState(const size_t position) const = 0;
	virtual bool getOutputState(const size_t position = 0) const = 0;
	virtual size_t getInputCount( ) const = 0;
	virtual size_t getOutputCount( ) const = 0;
	virtual void update( ) = 0;
	virtual void reset( ) = 0;

public: // Virtual function list
/*
	void printOutBit(const size_t position) const override;
	void printOutBits( ) const override;
	void printInBit(const size_t position) const override;
	void printInBits( ) const override;
*/

	virtual void printOutBit(const size_t position) const
	{
		(void)position;
		DEBUG_PRINT_WARNING("Not implementaion");
	}

	virtual void printOutBits( ) const
	{
		DEBUG_PRINT_WARNING("Not implementaion");
	}

	virtual void printInBit(const size_t position) const
	{
		(void)position;
		DEBUG_PRINT_WARNING("Not implementaion");
	}
	
	virtual void printInBits( ) const 
	{
		DEBUG_PRINT_WARNING("Not implementaion");
	}

public:
	virtual ~IComponent( ) = default;
};
