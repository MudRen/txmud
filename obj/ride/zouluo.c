// zouluo.c

inherit NPC;

void create()
{
	set_name("山西走骡", ({ "zou luo", "luo"}) ); 

	set("race", "野兽");
	set("gender", "雄性");
	set("unit","头");
	set("age", 3);
	set("long", "这是一匹健壮的走骡。\n");

	set("str", 24);
	set("cor", 26);
	set("cps", 22);

	set("max_kee", 500);
	set("max_gin", 500);
	set("max_sen", 500);
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "前蹄", "後蹄", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("bellicosity", 10 ); 

	set_temp("apply/attack", 100);
	set_temp("apply/armor", 200);

	set("ride",1);	// 坐骑标记。

	set("ride_level",1);
	setup();
}
