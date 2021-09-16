// s_force_book.c

inherit ITEM;

void create()
{
	set_name("内功秘籍", ({ "nei gong miji" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long", "这是指点内功心法的秘籍。\n");
		set("value", 50000);
		set("material", "paper");
		set("skill", ([
			"name":		"force", // 武功名称
			"exp_required":	50000,    // 读此书需要的最低经验.
			"sen_cost":	25,      // 读书花的神.
			"difficulty":	30,      // 参看 /cmds/std/study.c
			"max_skill":	160,	 // 能读到的最高等级.
			"min_skill":	110,
		]) );
	}
}
