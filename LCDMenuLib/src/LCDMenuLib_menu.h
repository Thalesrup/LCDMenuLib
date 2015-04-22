
//# Define
//# =======================
#ifndef LCDMenu_h
#	define LCDMenu_h

//# Include
//# =======================
#	include "Arduino.h"
#	include <avr/pgmspace.h>

	class LCDMenu
	{
		private:
			LCDMenu * parent;							// Parent menu, NULL if this is the top
			LCDMenu * child;							// First child menu, NULL if no children
			LCDMenu * sibling;							// Next sibling menu, NULL if this is the last sibling

			void setParent(LCDMenu &p);					// Sets the menu's parent to p
			void addSibling(LCDMenu &s,LCDMenu &p);		// Adds a sibling s with parent p.  If the menu already has a sibling, ask that sibling to add it
 
		public:
			uint8_t name;								// Name of this menu
			uint8_t disp;								// Set element group	

			LCDMenu(uint8_t n, uint8_t dis);			// Constructs the menu with a name and a NULL use function (be careful calling it)

			void addChild(LCDMenu &c);					// Adds the child c to the menu.  
														// If the menu already has a child, ask the child to add it as a sibling
			LCDMenu * getChild(uint8_t which, uint8_t group);			// Returns a pointer to the which'th child of this menu
			LCDMenu * getSibling(uint8_t howfar, uint8_t group);		// Returns a pointer to the sibling howfar siblings away from this menu
			LCDMenu * getParent();						// Returns this menu's parent menu.  If no parent, returns itself
	};
#endif