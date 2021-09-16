// old_beggar.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("老乞丐", ({ "old beggar" }) );
        set("gender", "男性" );
        set("class", "gaibang");
        set("age", 60);
        set("attitude","peaceful");
        set("long", "一个满脸风霜之色的老乞丐，正在延街乞讨。\n");
        set("combat_exp", 20000);
        set("str", 25);
        set("max_force", 100);
        set("force", 100);
        set("is_beggar",1);
        set("chat_chance", 15);
        set("chat_msg", ({
                CYN"老乞丐说道：好心的大爷哪～ 赏我要饭的几文钱吧～\n"NOR,
                CYN"老乞丐懒洋洋地打了个哈欠。\n"NOR,
                CYN"老乞丐伸手捉住了身上的虱子，骂道：老子身上没几两肉，全叫你们给咬烂了。 \n"NOR,
                (: random_move :)
        }) );

        setup();

        if(random(2))
                carry_object(BOOK_DIR"old_book");
        carry_object(ARMOR_DIR"cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + "，您好心一定会有好报的！");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
        return 0;
}

