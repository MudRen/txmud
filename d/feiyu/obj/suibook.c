// suibook.c

inherit F_CONTROL;
inherit ITEM;

void create()
{
        set_name("�������޷��ķ����ؼ�", ({"suiyu force"}));
        set_weight(600);

	set("valid_number",1);
	set("class","rain");

	set("unit", "��");
	set("long", "�Ȿ�������޷��ķ����ؼ���ǰ���������������ġ�\n");
	set("material", "paper");
	set("skill", ([
		"name": "suiyu-force",
		"exp_required": 20000,
		"sen_cost": 40,
		"difficulty": 40,
		"max_skill": 100,
		"min_skill" : 30,
	]) );
}
