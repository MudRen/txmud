//boy.c 藏族小男孩。
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("藏族小男孩", ({ "boy" }) );
        set("age", 13);
        set("long", "小男孩正偷偷的瞄着小女孩。\n");
        
        set("str",10);
        set("per",23);
        set("chat_chance",4);
        set("chat_msg", ({
                CYN"小男孩说：卓玛到底喜不喜欢我呢？\n"NOR,
                CYN"小男孩说：有人能帮我捉一只小鸟吗？\n"NOR,
                }) );
        set("inquiry",([
        "卓玛":"卓玛就是卓玛啊。\n",
]));        
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        setup();
        carry_object(__DIR__"obj/zang-xue")->wear();
        carry_object(__DIR__"obj/zang-xue")->wear();
}
int accept_object(object who,object ob)
{
        if((string)ob->query("id")=="bird" ) {
                say(CYN"小男孩说：我不要了，您帮我送给卓玛好吗？\n"NOR);
                command("shy");
                return 0;
        }
}

