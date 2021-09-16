// w_lv.c

inherit WILD;

void create()
{
	set_name("野驴", ({ "wild donkey"}) ); 

	set("race", "野兽");
	set("gender", "雄性");
	set("unit","头");
	set("age", 6);
	set("long", "这是一头浑身脏唏唏的野驴。\n");
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set("str", 24);
	set("cor", 26);
	set("cps", 22);

	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "前蹄", "后蹄", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("bellicosity", 10 ); 

	set_temp("apply/attack", 60);
	set_temp("apply/armor", 100);

	set("ride",1);	// 坐骑标记。

	// msg 里加不加换行("\n")均可.
        set("ride_msg","$N飞身一跃，稳稳的骑上了"+name()+"屁股。");
        set("unride_msg","$N侧身从"+name()+"背上跨了下来。");

	set("ride_level",2);	// 属于2级坐骑。
	setup();
}
