// shaogong.c

#include <cross_river.h>

inherit CROSS_RIVER_MASTER;

void create()
{
        set_name("渡船老大", ({"duchuan laoda"}));
        set("long", @LONG
这是一位满脸横肉的渡船老大。
LONG
);
        set("gender","男性");

        set("age",36);
        set("con",20);
        set("str",30);

	set(NO_KILL, 1);

	set_skill("unarmed",60);
	set_skill("dodge",60);
	set_skill("parry",60);

        set("combat_exp",800);

	set_max_passenger(4);
	set_cross_msg("过长江");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
