// chefu.c
// by dicky

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("车夫", ({ "che fu","chefu","fu", "man" }));
        set("gender", "男性");       
        set("long", "穿着破旧的粗布衣裳，苍白的脸，看来非但疲倦，而且憔悴衰老。\n");
        set("combat_exp", 5000);
        set("shen_type", 1);         
        set("age", 50);

        set_skill("force", 50);
        set_skill("unarmed", 50); 
	 
        setup();
        add_money("silver", 10);
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}


void greeting(object ob)
{      
       command("hi "+ob->query("id"));  
       command("say 这位" + RANK_D->query_respect(ob) +"想到江湖上去闯荡一翻吗，哈哈哈！现在江湖上门派众多，
你想去哪里呢？先看看牌子，然后再告诉我你要去哪里吧"HIR"（qu ***）"CYN"。"NOR); 
}                               
 