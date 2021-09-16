// chu_zi.c

#include <ansi.h>

inherit NPC;
 
void create()
{
	set_name("相府大厨", ({"cooker"}));

	set("long", "这就是丞相府的大厨，据说做淮阳菜一绝。");
	set("gender","男性");

        set("age",15);
        set("con",20);
        set("str",20);

	set("chat_chance", 5);
	set("chat_msg",({
		CYN"相府大厨说道：“天下美味属淮阳。”\n"NOR,
		CYN"相府大厨说道：“煎炒烹炸样样精，粗茶淡饭变美味。”\n"NOR,
}));

	set_skill("unarmed",40);

        set("combat_exp",5000+random(1000));

        setup();
        carry_object(__DIR__"obj/weiqun")->wear();
}
