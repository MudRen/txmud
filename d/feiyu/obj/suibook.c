// suibook.c

inherit F_CONTROL;
inherit ITEM;

void create()
{
        set_name("〖随雨无风心法〗秘籍", ({"suiyu force"}));
        set_weight(600);

	set("valid_number",1);
	set("class","rain");

	set("unit", "本");
	set("long", "这本〖随雨无风心法〗秘籍是前任掌门人留下来的。\n");
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
