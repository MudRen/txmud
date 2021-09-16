// attribute.c

#include <dbase.h>

int query_str()	// ±ÛÁ¦
{
	return (int)query("str") + (int)query("force_factor")
		+ query_temp("apply/strength");
}

int query_cor()	// µ¨Ê¶
{
	return (int)query("cor") + (int)query("bellicosity") / 50
		+ query_temp("apply/courage");
}

int query_int()	// ÎòÐÔ
{
	return (int)query("int")
		+ query_temp("apply/intelligence");
}

int query_per()	// ÈÝÃ²
{
	return (int)query("per")
		+ query_temp("apply/personality");
}

int query_con()	// ¸ù¹Ç
{
	return (int)query("con")
		+ query_temp("apply/constitution");
}

int query_kar()	// ¸£Ôµ
{
	return (int)query("kar")
		+ query_temp("apply/karma");
}
