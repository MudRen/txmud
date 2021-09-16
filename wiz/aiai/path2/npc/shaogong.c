// shaogong.c

#include <cross_river.h>

inherit CROSS_RIVER_MASTER;

void create()
{
        set_name("艄公", ({"shao gong"}));
        set("long", @LONG
这是一位满头银发的老船夫。
LONG
);
        set("gender","男性");

        set("age",76);
        set("con",20);
        set("str",30);

	set(NO_KILL, 1);

	set_skill("unarmed",60);
	set_skill("dodge",60);
	set_skill("parry",60);

        set("combat_exp",8000);

	set_max_passenger(4);
	set_cross_msg("过黄河");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
