#include <ansi.h>
inherit NPC;
void create()
{
        set_name("唐小倩", ({ "tang xiaoqian" , "tang" , "xiaoqian"}) );
        set("gender", "女性" );
        set("age",19 );
        set("long", "唐小倩是唐黯魂的女儿，跟她的母亲长的简直一模一样。\n");
        set("combat_exp", 170);
        set("per", 30);

        setup();

        set("chat_chance", 4);
        set("chat_msg", ({
                "唐小倩看着窗外，不知道在想着什么。。。。\n",
                "唐小倩自言自语道：谁能帮我找到那面玉佩呀。\n",
        }) );
        carry_object(ARMOR_DIR"cloth")->wear();
}
