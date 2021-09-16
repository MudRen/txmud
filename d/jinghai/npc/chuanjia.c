// chuanjia.c

#include <cross_river.h>

inherit CROSS_RIVER_MASTER;

void create()
{
        set_name("船家", ({"chuan jia"}));
        set("long", @LONG
这是一位满脸沧桑的老船家。
LONG
);
        set("gender","男性");

        set("age",56);
        set("con",20);
        set("str",30);
	set_skill("unarmed",60);
	set_skill("dodge",60);
	set_skill("parry",60);
	set(NO_KILL, 1);

        set("combat_exp",8000);

	set_max_passenger(6);
	set_cross_msg("渡海");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

// 重载这个函数使静海的人不收钱
int accept_object(object me,object obj)
{
	if(me->query("class") == "jinghai")
		return notify_fail(sprintf("%s摇摇头说道：本派坐船一概免费。\n", name()));
	else
		return ::accept_object(me, obj);
}
