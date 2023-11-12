#include <iostream>
#pragma once

class creation_exceptions : public std::exception {
public:
	const char* what() const override;
};

class summa_ugl_tr_er : public creation_exceptions {
public:
	const char* what() const override;
};


class ugl_pr_tr_not90_er : public creation_exceptions {
public:
	const char* what() const override;
};

class tr_neravenstvo_storon_er : public creation_exceptions {
public:
	const char* what() const override;
};

class tr_neravenstvo_uglov_er : public creation_exceptions {
public:
	const char* what() const override;
};

class rvnst_tr_neravenstvo_storon_er : public creation_exceptions {
public:
	const char* what() const override;
};

class rvnst_tr_neravenstvo_uglov_er : public creation_exceptions {
public:
	const char* what() const override;
};

class summa_ugl_chtr_er : public creation_exceptions {
public:
	const char* what() const override;
};

class chtr_neravenstvo_storon_er : public creation_exceptions {
public:
	const char* what() const override;
};

class ugl_prmg_not90_er : public creation_exceptions {
public:
	const char* what() const override;
};

class quadr_neravenstvo_storon_er : public creation_exceptions {
public:
	const char* what() const override;
};

class prlgrm_neravenstvo_uglov_er : public creation_exceptions {
public:
	const char* what() const override;
};