// attribute.c

#include <dbase.h>

int query_str()	// ����
{
	return (int)query("str") + (int)query("force_factor")
		+ query_temp("apply/strength");
}

int query_cor()	// ��ʶ
{
	return (int)query("cor") + (int)query("bellicosity") / 50
		+ query_temp("apply/courage");
}

int query_int()	// ����
{
	return (int)query("int")
		+ query_temp("apply/intelligence");
}

int query_per()	// ��ò
{
	return (int)query("per")
		+ query_temp("apply/personality");
}

int query_con()	// ����
{
	return (int)query("con")
		+ query_temp("apply/constitution");
}

int query_kar()	// ��Ե
{
	return (int)query("kar")
		+ query_temp("apply/karma");
}
