#include <ansi.h>
inherit NPC;

void create()
{
        set_name("周老板", ({ "zhou laoban" , "zhou" , "boss"}) );
        set("title",HIR"周扒皮"NOR);
        set("gender", "男性" );
        set("age", 40);
        set("long", "周老板整天笑眯眯地。\n");

        set("combat_exp", 1200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
