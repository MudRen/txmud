// jiebook.c

inherit F_CONTROL;
inherit ITEM;

void create()
{
        set_name("�����齣�����ؼ�", ({"jieqing sword"}));
        set_weight(600);

	set("valid_number",1);
	set("class","rain");

	set("unit", "��");
	set("long", "�Ȿ�����齣�����ؼ���ǰ���������������ġ�\n");
	set("material", "paper");
	set("skill", ([
		"name": "jieqing-sword",
		"exp_required": 30000,
		"sen_cost": 40,
		"difficulty": 40,
		"max_skill": 110,
		"min" : 40,
	]) );
}
