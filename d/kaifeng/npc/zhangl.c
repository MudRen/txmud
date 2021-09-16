#include <ansi.h>
inherit NPC;

void create()
{
        set_name("张老三", ({ "zhang" , "laosan" }) );
        set("title",HIR"赌王"NOR);
        set("gender", "男性" );
        set("age", 39);
        set("long", "张老三的赌技在开封首屈一指。\n");
	set("kar",30);
	set("cor",35);
        set("combat_exp", 800000);
        set("str", 30);

	set("max_kee",1000);
        set("force", 1900);
        set("max_force", 1900);
        set("force_factor", 40);

        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("unarmed",100);
        set_skill("force",200);

        setup();
	carry_object(__DIR__"obj/yandou");
        carry_object(ARMOR_DIR"cloth")->wear();
}

