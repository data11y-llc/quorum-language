#include "RadioButtonProvider.h"

#include <iostream>
#include <string>

RadioButtonProvider::RadioButtonProvider(RadioButtonControl* pButtonControl) : ProviderT(pButtonControl)
{
	// Nothing to do.
}


// =========== ProviderT functions.

bool RadioButtonProvider::IsPatternSupported(PATTERNID patternId) const noexcept
{
	return (patternId == UIA_SelectionItemPatternId);
}

CONTROLTYPEID RadioButtonProvider::GetControlType() const noexcept
{
	return UIA_RadioButtonControlTypeId;
}

// =========== ISelectionItemProvider implementation.

// Select: Deselects any selected items and then selects the current element.
IFACEMETHODIMP RadioButtonProvider::Select()
{
	if (UiaClientsAreListening())
	{
		UiaRaiseAutomationEvent(this, UIA_SelectionItem_ElementSelectedEventId);
	}

	return S_OK;
}

// AddToSelection: Adds the current element to the collection of selected items.
IFACEMETHODIMP RadioButtonProvider::AddToSelection()
{
	Select();
	return S_OK;
}

// RemoveFromSelection: Removes the current element from the collection of selected items.
//						One and only one item must always be selected, so this is not implemented.
IFACEMETHODIMP RadioButtonProvider::RemoveFromSelection()
{
	return UIA_E_INVALIDOPERATION;
}

// get_IsSelected: Indicates whether an item is selected. 
IFACEMETHODIMP RadioButtonProvider::get_IsSelected(_Out_ BOOL * pRetVal)
{
	if (m_control->GetState())
	{
		*pRetVal = TRUE;
	}
	else
	{
		*pRetVal = FALSE;
	}


	return S_OK;


}

// get_SelectionContainer: Specifies the provider that implements ISelectionProvider and acts as the container for the calling object.
IFACEMETHODIMP RadioButtonProvider::get_SelectionContainer(_Outptr_result_maybenull_ IRawElementProviderSimple ** pRetVal)
{
	*pRetVal = NULL;
	return S_OK;
}
