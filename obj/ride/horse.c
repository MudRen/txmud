// horse.c
// By Find.

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("宝马玉花聪", ({ "horse"}) ); 

	set("race", "野兽");
	set("gender", "雄性");
	set("unit","匹");
	set("age", 6);
	set("long", "这是一匹高头大马全身白毛，夹杂着一块块淡红色斑点，昂首扬鬃，
神俊非凡，黄金踏镫，马鞍边上镶着宝石，缰绳口上挂着一根金色的
小马鞭。\n");

	set("str", 24);
	set("cor", 26);
	set("cps", 22);

	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "前蹄", "後蹄", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("bellicosity", 10 ); 

	set_temp("apply/attack", 100);
	set_temp("apply/armor", 200);

	set("ride",1);	// 坐骑标记。

	// msg 里加不加换行("\n")均可.
        set("ride_msg","$N飞身一跃，稳稳的骑上了"+name()+"。");
        set("unride_msg","$N侧身从"+name()+"背上跃下。");

	set("ride_level",2);	// 属于2级坐骑。
	setup();
}
