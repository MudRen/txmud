// literate_book.c
// by dicky

inherit ITEM;
void create()
{
    set_name("���־�", ({ "sanzi jing", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","������д�������־�����\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name":     "literate",
			"exp_required":	100,
			"gin_cost":	20,
			"difficulty":	20,
			"max_skill":	31,		
		]) );
	}
}