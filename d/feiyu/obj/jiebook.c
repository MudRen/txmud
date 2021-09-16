// jiebook.c

inherit F_CONTROL;
inherit ITEM;

void create()
{
        set_name("〖戒情剑法〗秘籍", ({"jieqing sword"}));
        set_weight(600);

	set("valid_number",1);
	set("class","rain");

	set("unit", "本");
	set("long", "这本〖戒情剑法〗秘籍是前任掌门人留下来的。\n");
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
