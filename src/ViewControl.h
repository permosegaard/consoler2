#pragma once

#include "View.h"

class ViewControl : public View {
public:
	ViewControl();
	~ViewControl();
	
	void animatedShow();
	void animatedHide();
};
