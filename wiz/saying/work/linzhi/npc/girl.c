//girl.c 藏族小女孩。
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("藏族小女孩", ({ "girl" }) );
        set("age", 12);
        set("long", "小女孩脸上莫名其妙泛起一阵红晕。\n");
        
        set("str",10);
        set("per",26);
        set("inquiry",([
        "卓玛":"我就是卓玛，有什么事吗？",
]));        
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/zang-xue")->wear();
}
int accept_object(object who,object ob)
{
        if((string)ob->query("id")=="bird" ) {
                say(
CYN"小女孩说：是仁措送我的吗？真好玩。\n"NOR
CYN"小女孩说：听说村东那个森林有个简单的方法到达圣树。\n"NOR
CYN"小女孩说：嗯，好像是跟那个混蛋巫师有点关系。\n"NOR
);
                command("giggle girl");
                destruct(ob);
                return 1;
        }
}

