// old_book.c

inherit ITEM;

void create()
{
	set_name("����", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
			"�ᵽһЩ��������ʲ��ġ�\n");
		set("value", 800);
		set("material", "paper");
		set("skill", ([
			"name":		"force", // �书����
			"exp_required":	100,    // ��������Ҫ����;���.
			"sen_cost":	25,      // ���黨����.
			"difficulty":	25,      // �ο� /cmds/std/study.c
			"max_skill":	28,	 // �ܶ�������ߵȼ�.
		]) );
	}
}