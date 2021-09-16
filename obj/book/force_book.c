// force_book.c

inherit ITEM;

void create()
{
	set_name("《调吸大法》", ({ "force book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long", "这是一本武馆里常见的讲基本内功的书籍。\n");
		set("value", 4000);
		set("material", "paper");
		set("skill", ([
			"name":		"force", // 武功名称
			"exp_required":	10000,    // 读此书需要的最低经验.
			"sen_cost":	25,      // 读书花的神.
			"difficulty":	30,      // 参看 /cmds/std/study.c
			"max_skill":	70,	 // 能读到的最高等级.
		]) );
	}
}