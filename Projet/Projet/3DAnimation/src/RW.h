#ifndef RW_h
#define RW_h


#include "GlWindow.h"


class RW : public GlWindow
{
	public:
        RW();
        ~RW();

		/*!
		*\brief Initialization des objets.
		*/
		bool initializeObjects();

		/*!
		*\brief Rendu de la scène.
		*/
		void render();

		void keyPressEvent(QKeyEvent *);
};


#endif
