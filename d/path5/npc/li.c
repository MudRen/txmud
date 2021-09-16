// shaogong.c

#include <cross_river.h>

inherit CROSS_RIVER_MASTER;

void create()
{
        set_name("李老汉", ({"li laohan"}));
        set("long", @LONG
这是一位慈眉善目的老者。
LONG
);
        set("gender","男性");

        set("age",66);
        set("con",20);
        set("str",30);
	set_skill("unarmed",60);
	set_skill("dodge",60);
	set_skill("parry",60);

        set("combat_exp",8000);

	set_max_passenger(8);
	set_cross_msg("过长江");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
